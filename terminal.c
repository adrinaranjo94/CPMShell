#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "lib/show_files.h"

const char* selectDir(char path[]);
const char* checkParameters(char path[]);

int main(){
	char *actualDir; 
	actualDir = "A";
	char query[255];
	printf("%s:> ",actualDir);
	
	while(fgets(query,255,stdin) != NULL){
		if(strstr(query,"DIR") != NULL){
			if(strcasecmp(query,"DIR") == 0){
				system(showFiles(selectDir(actualDir)));
			}else{
				system(showFiles(checkParameters(query)));
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
		
		fgets(query,255,stdin);
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

const char* checkParameters(char dir[]){
	if(strstr(dir,"A") != NULL){
		return "./carpetaA";
	}else if(strstr(dir,"B") != NULL){
		return "./carpetaB";
	}else{
		return "";
	}
	
	return "";
}


