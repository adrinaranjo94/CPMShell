#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Includes fork
#include <unistd.h>
#include <sys/wait.h>

//Includes library
#include "lib/dir.h"
#include "lib/type.h"
#include "lib/era.h"
#include "lib/copy.h"
#include "lib/ren.h"
#include "lib/run.h"

char c1 = ' ';
char c2 = ' ';
char auxDir[4];

void readConf();

char* getDir(char dir);
void normalZone();
void batchZone(char* nameFile);

int main(int argc, char* argv[]){
    //Detectamos si vienen archivos en los argumentos o si es una ejecucion normal
    if(argc == 2){
        batchZone(argv[1]);
    }else{
        normalZone();
    }
	return 0;
}
//Ejecucion normal
void normalZone(){
    readConf();
	//printf("C1 %c",c1);
	//printf("C2 %c",c2);
	char actualDir[2]; 
	sprintf(actualDir, "%c", c1);
	char query[255];

    int salida = 0;

	while(salida != -1){//START WHILE
        int fd[2];
        int val = 0;

        // create pipe descriptors
        pipe(fd);
        pid_t pid = fork();

        if (pid == 0) { // (HIJO)
                     
        //Leemos de consola la entrada
            printf("%s:> ",actualDir);
	        strtok(fgets(query,255,stdin),"\n");
            val = 0;
		    if(strstr(query,"DIR") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_dir(query,actualDir,c1,c2));
		        system(command);
		    }else if(strstr(query,"TYPE") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_type(query,actualDir,c1,c2));
			    system(command);
		    }else if(strstr(query,"ERA") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_era(query,actualDir,c1,c2));
		        system(command);
        	}else if(strstr(query,"COPY") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_copy(query,actualDir,c1,c2));
		        system(command);
		    }else if(strstr(query,"REN") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_ren(query,actualDir,c1,c2));
		        system(command);
		    }else if(strstr(query,"RUN") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_run(query,actualDir,c1,c2));
		        system(command);
		    }else if(strcmp(query,getDir(c1)) == 0){
       			
                val = 1;
		    }else if(strcmp(query,getDir(c2)) == 0){
			    
                val = 2;
		    }else if(strcmp(query,"HELP") == 0){
			    system("cat lib/help.txt");
            }else if(strcmp(query,"EXIT") == 0){
                val = -1;
            }else{
			    printf("comando desconocido\n");
			    //printf("%s",query);
		    }
            close(fd[0]);
            // send the value on the write-descriptor.
            write(fd[1], &val, sizeof(val));


            // close the write descriptor
            close(fd[1]);


            exit(0);
        }else{//END IF (PADRE)
             wait(NULL);
                 // parent: reading only, so close the write-descriptor
            close(fd[1]);

            // now read the data (will block)
            read(fd[0], &val, sizeof(val));


            switch(val){
                case -1: salida = -1; break;
                case 1://TODO
                    sprintf(actualDir, "%c", c1);
                    break;
                case 2://TODO
                    sprintf(actualDir, "%c", c2);
                    break;
                
            }
            // close the read-descriptor
            close(fd[0]);
        }//END IF
	}//END WHILE
}

void batchZone(char* nameFile){
    readConf();
	//printf("C1 %c",c1);
	//printf("C2 %c",c2);
	char actualDir[2]; 
	sprintf(actualDir, "%c", c1);
    //printf("NAME: %s", nameFile);
    char query[255];
    char line[100];
    FILE* file = fopen(nameFile,"r");
    int salida = 0;
    
    char a[1000][255];//MEJORAR CON MALLOC

    int i = 0;
    int iT = 0;
    int salir = 0;
    while (salir == 0){ //Se podria cambiar por EOF
        if(fgets(line,100,file) == NULL){
            strcpy(a[i],"EXIT");
            salir = 1;
        }else{
            strncpy(a[i],line,strlen(line)-1);
            i++;       
        }
    }
    /*
    for(int j = 0; j <=i ; j++){
        printf("Q:%s\n",a[j]);
    }
    */
    fclose(file);
 
    for(int j = 0; j <=i ; j++){


        int fd[2];
        int val = 0;

        // create pipe descriptors
        pipe(fd);
        pid_t pid = fork();

        if (pid == 0) {
            strcpy(query,a[j]);
            val = 0;
            //LLAMADAS A LAS FUNCIONES DE LAS LIBRERIAS
		    if(strstr(query,"DIR") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_dir(query,actualDir,c1,c2));
		        system(command);
		    }else if(strstr(query,"TYPE") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_type(query,actualDir,c1,c2));
			    system(command);
		    }else if(strstr(query,"ERA") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_era(query,actualDir,c1,c2));
		        system(command);
        	}else if(strstr(query,"COPY") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_copy(query,actualDir,c1,c2));
		        system(command);
		    }else if(strstr(query,"REN") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_ren(query,actualDir,c1,c2));
		        system(command);
		    }else if(strstr(query,"RUN") != NULL){
		        char command[100];
		        sprintf(command, "%s", use_run(query,actualDir,c1,c2));
		        system(command);
		    }else if(strcmp(query,getDir(c1)) == 0){
       			
                val = 1;
		    }else if(strcmp(query,getDir(c2)) == 0){
			    
                val = 2;
		    }else if(strcmp(query,"HELP") == 0){
			    system("cat lib/help.txt");
            }else if(strcmp(query,"EXIT") == 0){

                val = -1;
            }else{
			    printf("comando desconocido\n");
			    //printf("%s",query);
		    }
            close(fd[0]);
            // send the value on the write-descriptor.
            write(fd[1], &val, sizeof(val));
            // close the write descriptor
            close(fd[1]);


            exit(0);
        }else{//END IF
             wait(NULL);
                 // parent: reading only, so close the write-descriptor
            close(fd[1]);

            // now read the data (will block)
            read(fd[0], &val, sizeof(val));


            // close the read-descriptor
            switch(val){
                case -1: salida = -1; break;
                case 1://TODO
                    sprintf(actualDir, "%c", c1);
                    break;
                case 2://TODO
                    sprintf(actualDir, "%c", c2);
                    break;
                
            }
            close(fd[0]);
            //salida = 0;
        }

    }

}

char* getDir(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}
//leemos la configuracion del archivo oculto con las rutas relativas de los archivos
void readConf(){
    FILE * fp;
    fp = fopen("lib/.cmpconfig.txt", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    if (fp == NULL){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        if(i == 0){
            c1 = line[0];
            
            i++;
        }else{
            c2 = line[0];
        }
    }
    fclose(fp);
    if (line)
        free(line);
    
    return;
    
}
