#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Includes fork
#include <signal.h>
#include <sys/wait.h>

//Includes library
#include "lib/dir.h"
#include "lib/type.h"
#include "lib/era.h"

char c1 = ' ';
char c2 = ' ';
char auxDir[3];

void readConf();

char* getDir(char dir);


int main(){
    readConf();
	//printf("C1 %c",c1);
	//printf("C2 %c",c2);
	char actualDir[2]; 
	sprintf(actualDir, "%c", c1);
	char query[255];
	printf("%s:> ",actualDir);
	
	strtok(fgets(query,255,stdin),"\n");
	while(strcmp(query,"EXIT") != 0){
		if(strstr(query,"DIR") != NULL){
            if (fork() == 0) {
			    char command[100];
			    sprintf(command, "%s", use_dir(query,actualDir,c1,c2));
			    system(command);
            } else {
                wait(NULL);
                kill(0,SIGTERM);
            }
		}else if(strstr(query,"TYPE") != NULL){
            if (fork() == 0) {
			    char command[100];
			    sprintf(command, "%s", use_type(query,actualDir,c1,c2));
    			system(command);
            } else {
                wait(NULL);
                kill(0,SIGTERM);
            }
		}else if(strstr(query,"ERA") != NULL){
            if (fork() == 0) {
			    char command[100];
			    sprintf(command, "%s", use_era(query,actualDir));
			    system(command);
            } else {
                wait(NULL);
                kill(0,SIGTERM);
            }

		}else if(strcmp(query,getDir(c1)) == 0){
            if (fork() == 0) {
    			sprintf(actualDir, "%c", c1);
            } else {
                wait(NULL);
                kill(0,SIGTERM);
            }
		}else if(strcmp(query,getDir(c2)) == 0){
            if (fork() == 0) {
			sprintf(actualDir, "%c", c2);
            } else {
                wait(NULL);
                kill(0,SIGTERM);
            }
		}else if(strcmp(query,"HELP") == 0){
            if (fork() == 0) {
    			system("cat lib/help.txt");
            } else {
                wait(NULL);
                kill(0,SIGTERM);
            }
        }
        else{
			printf("comando desconocido\n");
			//printf("%s",query);
		}
		printf("%s:> ",actualDir);
		
		strtok(fgets(query,255,stdin),"\n");
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
