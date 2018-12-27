#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "lib/show_files.h"

const char* selectDir(char path[]);
const char* checkParameters(char path[],char actualDir[]);

int main(){
	char *actualDir; 
	actualDir = "A";
	char query[255];
	printf("%s:> ",actualDir);
	
	strtok(fgets(query,255,stdin),"\n");
	while(strcmp(query,"EXIT") != 0){
		if(strstr(query,"DIR") != NULL){
			if(strcmp(query,"DIR") == 0){
				system(showFiles(selectDir(actualDir)));
			}else{
				system(showFiles(checkParameters(query,actualDir)));
				printf("%s",checkParameters(query,actualDir));
			}
		}else if(strcmp(query,"B:") == 0){
			actualDir = "B";
		}else if(strcmp(query,"A:") == 0){
			actualDir = "A";
		}else{
			printf("no se\n");
			printf("%s",query);
		}
		printf("%s:> ",actualDir);
		
		strtok(fgets(query,255,stdin),"\n");
	}
	return 0;
	
}

const char* selectDir(char dir[]){
	if(strcmp(dir,"A") == 0){
		return "./carpetaA";
	}else if(strcmp(dir,"B") == 0){
		return "./carpetaB";
	}else{
		return "";
	}
	
	return "";
}

const char* checkParameters(char path[],char actualDir[]){
	if(strstr(path,"A:") != NULL){
		return "./carpetaA";
	}else if(strstr(path,"B:") != NULL){
		return "./carpetaB";
	}else{
		
		char pathFinal[255];
		char barra[1] = "/";
		strcpy(pathFinal,selectDir(actualDir));
		strcpy(pathFinal,barra);
		
		
		char* final = pathFinal;
		return final;

	}
	
	return "";
}


