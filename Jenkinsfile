project = "qplot"

images = [
        'ubuntu18' : [
                'name'  : 'essdmscdm/ubuntu18.04-build-node:1.1.0',
                'sh'    : 'sh',
                'cmake' : 'cmake'
        ]
]

base_container_name = "${project}-${env.BRANCH_NAME}-${env.BUILD_NUMBER}"

def failure_function(exception_obj, failureMessage) {
    def toEmails = [[$class: 'DevelopersRecipientProvider']]
    emailext body: '${DEFAULT_CONTENT}\n\"' + failureMessage + '\"\n\nCheck console output at $BUILD_URL to view the results.',
            recipientProviders: toEmails,
            subject: '${DEFAULT_SUBJECT}'
    slackSend color: 'danger',
            message: "${base_container_name}: " + failureMessage
    throw exception_obj
}

def get_macos_pipeline() {
    return {
        stage("macOS") {
            node("macos") {
                // Delete workspace when build is done
                cleanWs()

                dir("${project}/code") {
                    try {
                        checkout scm
                        sh "git submodule update --init"
                    } catch (e) {
                        failure_function(e, 'MacOSX / Checkout failed')
                    }
                }

                dir("${project}/build") {
                    try {
                        sh "ls -al "
                        sh "cmake ../code"
                    } catch (e) {
                        failure_function(e, 'MacOSX / CMake failed')
                    }

                    try {
                        sh "make"
                    } catch (e) {
                        failure_function(e, 'MacOSX / build+test failed')
                    }
                }

            }
        }
    }
}


def Object container_name(image_key) {
    return "${base_container_name}-${image_key}"
}

def create_container(image_key) {
    def image = docker.image(images[image_key]['name'])
    def container = image.run("\
            --name ${container_name(image_key)} \
        --tty \
        --network=host \
        --env http_proxy=${env.http_proxy} \
        --env https_proxy=${env.https_proxy} \
        --env local_conan_server=${env.local_conan_server} \
          ")
}

def docker_clone(image_key) {
    def custom_sh = images[image_key]['sh']
    def clone_script = """
        git clone \
            --branch ${env.BRANCH_NAME} \
            https://github.com/ess-dmsc/${project}.git /home/jenkins/${project}
        cd ${project}
        git submodule update --init
        """
    sh "docker exec ${container_name(image_key)} ${custom_sh} -c \"${clone_script}\""
}

def docker_dependencies(image_key) {
    def custom_sh = images[image_key]['sh']
    def conan_remote = "ess-dmsc-local"
    def dependencies_script = """
        mkdir ${project}/build
        cd ${project}/build
        conan remote add \\
            --insert 0 \\
            ${conan_remote} ${local_conan_server}
                    """
    sh "docker exec ${container_name(image_key)} ${custom_sh} -c \"${dependencies_script}\""
}

def docker_cmake(image_key, xtra_flags) {
    def custom_sh = images[image_key]['sh']
    def cmake = images[image_key]['cmake']
    def configure_script = """
        cd ${project}/build
        ${cmake} --version
        ${cmake} ${xtra_flags} ..
        """

    sh "docker exec ${container_name(image_key)} ${custom_sh} -c \"${configure_script}\""
}

def docker_build(image_key) {
    def custom_sh = images[image_key]['sh']
    def build_script = """
        cd ${project}/build
        . ./activate_run.sh
        make --version
        make -j4
                  """
    sh "docker exec ${container_name(image_key)} ${custom_sh} -c \"${build_script}\""
}

def get_pipeline(image_key) {
    return {
        stage("${image_key}") {
            node("docker") {
                try {
                    create_container(image_key)
                    docker_clone(image_key)
                    docker_dependencies(image_key)
                    docker_cmake(image_key, "")
                    docker_build(image_key)
                } finally {
                    sh "docker stop ${container_name(image_key)}"
                    sh "docker rm -f ${container_name(image_key)}"
                }
            }
        }
    }
}

node('docker') {
    cleanWs()

    dir("${project}_code") {
        stage('Checkout') {
            try {
                scm_vars = checkout scm
                sh "git submodule update --init"
            } catch (e) {
                failure_function(e, 'Checkout failed')
            }
        }
    }

    def builders = [:]
    for (x in images.keySet()) {
        def image_key = x
        builders[image_key] = get_pipeline(image_key)
    }
    builders['macOS'] = get_macos_pipeline()

    try {
        parallel builders
    } catch (e) {
        failure_function(e, 'Job failed')
    }

    // Delete workspace if build was successful
    cleanWs()
}

