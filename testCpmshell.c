#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Includes fork
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//Includes library
#include "lib/dir.h"
#include "lib/type.h"
#include "lib/era.h"

char c1 = ' ';
char c2 = ' ';
char auxDir[4];

void readConf();

char* getDir(char dir);


int main(){
    readConf();
	//printf("C1 %c",c1);
	//printf("C2 %c",c2);
	char actualDir[2]; 
	sprintf(actualDir, "%c", c1);
	char query[255];
	
    int salida = 1;
    

    
	while(salida != -1){
    int fd[2];
    int val = 0;

    // create pipe descriptors
    pipe(fd);
        pid_t pid = fork();
        if (pid == 0) {
                     
        //Leemos de consola la entrada
        printf("%s:> ",actualDir);
	    strtok(fgets(query,255,stdin),"\n");

        //Comprobamos que entra
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
        }else if(strcmp(query,getDir(c1)) == 0){
            //TODO:
            sprintf(actualDir, "%c", c1);
        }else if(strcmp(query,getDir(c2)) == 0){
            sprintf(actualDir, "%c", c2);
        }else if(strcmp(query,"HELP") == 0){
            system("cat lib/help.txt");
        }else if(strcmp(query,"EXIT") == 0){
            //TODO:
            //mensaje = "exit";
            close(fd[0]);

        // send the value on the write-descriptor.
            val = -1;
            write(fd[1], &val, sizeof(val));
            printf("child(%d) send value: %d\n", getpid(), val);

            // close the write descriptor
            close(fd[1]);
                printf("parent(%d) received value: %d\n", getpid(), val);        
        }else{
            printf("comando desconocido\n");
            //printf("%s",query);
        }

            exit(0);
        }else{
         wait(NULL);
             // parent: reading only, so close the write-descriptor
        close(fd[1]);

        // now read the data (will block)
        read(fd[0], &val, sizeof(val));


        // close the read-descriptor
        switch(val){
            case -1: salida = -1; break;
            case 1://TODO
                break;
            case 2://TODO
                break;
            
        }
        close(fd[0]);
        //salida = 0;
        }
	}
	return 0;
}

char* getDir(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

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
