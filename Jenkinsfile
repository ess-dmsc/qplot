/*
 * qplot Jenkinsfile
 */

node ("qt") {

    dir("code") {
        stage("Checkout projects") {
            checkout scm
            sh "git submodule update --init"
        }
    }

    dir("build") {
        stage("Run CMake") {
            sh 'rm -rf ./*'
            sh "source /opt/cern/root/bin/thisroot.sh && \
                /opt/cmake/cmake-3.7.1-Linux-x86_64/bin/cmake ../code/src"
        }

        stage("Build project") {
            sh "make VERBOSE=1"
        }

    }
}
