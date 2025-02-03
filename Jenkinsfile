@Library('ecdc-pipeline')
import ecdcpipeline.ContainerBuildNode
import ecdcpipeline.PipelineBuilder

project = "qplot"
clangformat_os = "ubuntu2204"

// Set number of old builds to keep.
 properties([[
     $class: 'BuildDiscarderProperty',
     strategy: [
         $class: 'LogRotator',
         artifactDaysToKeepStr: '',
         artifactNumToKeepStr: '10',
         daysToKeepStr: '',
         numToKeepStr: ''
     ]
 ]]);

container_build_nodes = [
  'centos': ContainerBuildNode.getDefaultContainerBuildNode('centos7-gcc11-qt6'),
  'ubuntu2204': ContainerBuildNode.getDefaultContainerBuildNode('ubuntu2204')
]

def failure_function(exception_obj, failureMessage) {
    def toEmails = [[$class: 'DevelopersRecipientProvider']]
    emailext body: '${DEFAULT_CONTENT}\n\"' + failureMessage + '\"\n\nCheck console output at $BUILD_URL to view the results.',
            recipientProviders: toEmails,
            subject: '${DEFAULT_SUBJECT}'
    throw exception_obj
}

pipeline_builder = new PipelineBuilder(this, container_build_nodes)
pipeline_builder.activateEmailFailureNotifications()

builders = pipeline_builder.createBuilders { container ->

    pipeline_builder.stage("${container.key}: checkout") {
        dir(pipeline_builder.project) {
            scm_vars = checkout scm
        }
        // Copy source code to container
        container.copyTo(pipeline_builder.project, pipeline_builder.project)
    }  // stage


    if (container.key != clangformat_os) {
        pipeline_builder.stage("${container.key}: configure") {
            container.sh """
                cd ${project}
                mkdir build
                cd build
                cmake --version
                CMAKE_PREFIX_PATH=/opt/Qt-6.8.2/lib/cmake cmake ..
            """
        }  // stage

        pipeline_builder.stage("${container.key}: build") {
            container.sh """
                cd ${project}/build
                make --version
                make -j4
                make qplot_test -j4
            """
        }  // stage
    }

    if (container.key == clangformat_os) {
        pipeline_builder.stage("${container.key}: cppcheck") {
        try {
                def test_output = "cppcheck.xml"
                container.sh """
                                cd ${project}
                                cppcheck --enable=all --inconclusive --template="{file},{line},{severity},{id},{message}" --xml --xml-version=2 ./ 2> ${test_output}
                            """
                container.copyFrom("${project}", '.')
                sh "mv -f ./${project}/* ./"
            } catch (e) {
                failure_function(e, "Cppcheck step for (${container.key}) failed")
            }
        }  // stage
        recordIssues(tools: [cppCheck(pattern: 'cppcheck.xml')])
    }
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
                    } catch (e) {
                        failure_function(e, 'MacOSX / Checkout failed')
                    }
                }

                dir("${project}/build") {
                    try {
                        sh "CMAKE_PREFIX_PATH=/usr/local/opt/qt cmake ../code"
                    } catch (e) {
                        failure_function(e, 'MacOSX / CMake failed')
                    }

                    try {
                        sh "make -j4 && make qplot_test -j4"
                    } catch (e) {
                        failure_function(e, 'MacOSX / build+test failed')
                    }
                }

            }
        }
    }
}

node('docker') {
    dir("${project}_code") {

        stage('Checkout') {
            try {
                scm_vars = checkout scm
            } catch (e) {
                failure_function(e, 'Checkout failed')
            }
        }

        stage("Static analysis") {
            try {
                sh "find . -name '*TestData.h' > exclude_cloc"
                sh "cloc --exclude-list-file=exclude_cloc --by-file --xml --out=cloc.xml ."
                sh "xsltproc jenkins/cloc2sloccount.xsl cloc.xml > sloccount.sc"
                sloccountPublish encoding: '', pattern: ''
            } catch (e) {
                failure_function(e, 'Static analysis failed')
            }
        }
    }

    if (env.ENABLE_MACOS_BUILDS.toUpperCase() == 'TRUE') {
        builders['macOS'] = get_macos_pipeline()
    }

    try {
        timeout(time: 2, unit: 'HOURS') {
            parallel builders
        }
    } catch (e) {
        failure_function(e, 'Job failed')
        throw e
    } finally {
        // Delete workspace when build is done
        cleanWs()
    }
}


