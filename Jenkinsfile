/*
 * qplot Jenkinsfile
 */

def failure_function(exception_obj, failureMessage) {
    def toEmails = [[$class: 'DevelopersRecipientProvider']]
    emailext body: '${DEFAULT_CONTENT}\n\"' + failureMessage + '\"\n\nCheck console output at $BUILD_URL to view the results.', recipientProviders: toEmails, subject: '${DEFAULT_SUBJECT}'
    throw exception_obj
}

node ("fedora") {
    cleanWs()

    try {
        dir("code") {
            stage("Checkout projects") {
                checkout scm
                sh "git submodule update --init"
            }
        }
    } catch (e) {
        failure_function(e, 'Checkout failed')
    }

    dir("build") {
        try {
            stage("Run CMake") {
                sh 'rm -rf ./*'
                sh "cmake ../code/src"
            }
        } catch (e) {
            failure_function(e, 'CMake failed')
        }

        try {
            stage("Build project") {
                sh "make"
            }
        } catch (e) {
            failure_function(e, 'Build failed')
        }

    }
}

def get_osx_pipeline()
{
    return {
        stage("MacOSX") {
            node ("macos") {
            // Delete workspace when build is done
                cleanWs()

                dir("${project}/code") {
                    try {
                        checkout scm
                    } catch (e) {
                        failure_function(e, 'MacOSX / Checkout failed')
                    }
                }

                dir("${project}/build") {
                    try {
                        sh "cmake ../code/src"
                    } catch (e) {
                        failure_function(e, 'MacOSX / CMake failed')
                    }

                    try {
                        sh "make"
                    } catch (e) {
                        failure_function(e, 'MacOSX / build failed')
                    }
                }

            }
        }
    }
}

node('docker') {
    stage('Checkout') {
        dir("${project}/code") {
            try {
                scm_vars = checkout scm
            } catch (e) {
                failure_function(e, 'Checkout failed')
            }
        }
    }

    def builders = [:]
    //for (x in images.keySet()) {
    //    def image_key = x
    //    builders[image_key] = get_pipeline(image_key)
    //}
    builders['MocOSX'] = get_osx_pipeline()
    
    parallel builders

    // Delete workspace when build is done
    cleanWs()
}

