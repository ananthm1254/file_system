pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'make build'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                sh 'make run-test'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}
