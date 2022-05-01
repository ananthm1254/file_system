pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh 'python3 file_generator.py'
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
