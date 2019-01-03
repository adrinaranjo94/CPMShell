#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "lib/dir.h"
#include "lib/type.h"

char c1 = ' ';
char c2 = ' ';

void readConf();

int main(){
    readConf();
	char *actualDir; 
	actualDir = "A";
	char query[255];
	printf("%s:> ",actualDir);
	
	strtok(fgets(query,255,stdin),"\n");
	while(strcmp(query,"EXIT") != 0){
		if(strstr(query,"DIR") != NULL){
			char command[100];
			sprintf(command, "%s", use_dir(query,actualDir));
			system(command);
		}else if(strstr(query,"TYPE") != NULL){
			char command[100];
			printf("%s",use_type(query,actualDir));
			sprintf(command, "%s", use_type(query,actualDir));
			system(command);
		}else if(strcmp(query,"B:") == 0){
			actualDir = "B";
		}else if(strcmp(query,"A:") == 0){
			actualDir = "A";
		}else if(strcmp(query,"HELP") == 0){
			system("cat lib/help.txt");
        }
        else{
			printf("no se\n");
			printf("%s",query);
		}
		printf("%s:> ",actualDir);
		
		strtok(fgets(query,255,stdin),"\n");
	}
	return 0;
}

void readConf(){
    FILE * fp;
    fp = fopen("./.cmpconfig.txt", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    if (fp == NULL){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
        printf("%c", line[0]);
        if(i = 0){
            c1 = line[0];
            i++;
        }else{
            c2 = line[0];
        }
    }
    printf("\n");
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
    
}

