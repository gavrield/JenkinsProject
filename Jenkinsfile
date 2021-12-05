pipeline {
  agent { node { label 'slave01' } }

   stages {
      stage('Clone Sources') {
        steps {
          checkout scm
        } 
      }
      stage('Build') {
         steps {
            echo 'Build process..'            
            sh '''
                cd "${WORKSPACE}/scripts/"
                chmod 755 *.py, *.sh
            '''
         }
      }      
        stage("Env Variables") {
            steps {
                sh "printenv"
            }
        }    
      stage('C'){
         when {
             anyOf {
                    environment name: 'LANGUAGE', value: 'C'
                    environment name: 'LANGUAGE', value: 'All'
                }
         }
         steps{
            sh '''
               echo "executing C file"
               cd "${WORKSPACE}/scripts"
               gcc uppercase_word.c
               ./a.out $C_PARAM
               ./a.out > results_c_program
            '''
         }
      }
      stage('Python'){
         when {
             anyOf {
                    environment name: 'LANGUAGE', value: 'Python'
                    environment name: 'LANGUAGE', value: 'All'
                }
         }
         steps{
            sh '''
               echo "executing Python file"
               ./trianglePrint.py $PY_PARAM
               ./trianglePrint.py $PY_PARAM > results_python_program
            '''
         }
      }
      stage('Bash'){
         when {
             anyOf {
                    environment name: 'LANGUAGE', value: 'Bash'
                    environment name: 'LANGUAGE', value: 'All'
                }
         }
         steps{
            sh '''
               echo "executing Bash file"
               ./reverse_word.sh $BASH_PARAM
               ./reverse_word.sh $BASH_PARAM > results_bash_program
            '''
         }
      }
      stage('Saving Results') {
         steps {
            echo 'Saving Results process..'
            sh '''
	      report_file="${HOME}/Documents/Deployment/report"
         mkdir -p ${HOME}/Documents/Deployment/              
         if [ -f "${report_file}" ]; then
               echo "file ${report_file} exists"
         else
	            touch ${report_file}
         fi
	      date >> ${report_file}
	      echo "USER=$USER JOB_NAME=$JOB_NAME" >> ${report_file}
         echo "Build Number $BUILD_NUMBER" >> ${report_file}
         if ($LANGUAGE=='All'); then
            echo "All files were excuted" >> ${report_file}
            printf("%s: %s", "C lang results", $(cat "${WORKSPACE}/scripts/results_c_program"))>> ${report_file}
            printf("%s: %s", "Python lang results", $(cat "${WORKSPACE}/scripts/results_python_program"))>> ${report_file}
            printf("%s: %s", "Bash lang results", $(cat "${WORKSPACE}/scripts/results_bash_program"))>> ${report_file}
         fi
         if ($LANGUAGE=='C'); then
            echo "Only c file was excuted" >> ${report_file}
            printf("%s: %s", "C lang results", $(cat "${WORKSPACE}/scripts/results_c_program"))>> ${report_file}
         fi
         if ($LANGUAGE=='Python'); then
            echo "Only python file was excuted" >> ${report_file}
            printf("%s: %s", "Python lang results", $(cat "${WORKSPACE}/scripts/results_python_program"))>> ${report_file}
         fi
         if ($LANGUAGE=='Bash'); then
            echo "Only bash file was excuted" >> ${report_file}
            printf("%s: %s", "Bash lang results", $(cat "${WORKSPACE}/scripts/results_bash_program"))>> ${report_file}
         fi

	      echo "#############################" >> ${report_file}
            '''
         }
      }
      
   }
}