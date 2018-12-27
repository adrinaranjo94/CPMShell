#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "lib/dir.h"

char* selectDir(char path[]);
char* checkParameters(char path[],char actualDir[]);
void substring(char s[], char sub[], int p, int l);


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
				//printf("\n%s",showFiles(checkParameters(query,actualDir)));
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

char* selectDir(char dir[]){
	
	char* pathDir = ""; 
	if(strcmp(dir,"A") == 0){
		pathDir = "./carpetaA";
		return pathDir;
	}else if(strcmp(dir,"B") == 0){
		pathDir = "./carpetaB";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

char* checkParameters(char path[],char actualDir[]){
	if(strstr(path,"A:") != NULL){
		return "./carpetaA";
	}else if(strstr(path,"B:") != NULL){
		return "./carpetaB";
	}else{
		
        char subPath[strlen(path)];
        char filename[128];
        char filename1[128];
        char* barra="/";
        substring(path,subPath,5,strlen(path));
        strncpy(filename, selectDir(actualDir), sizeof(filename));
        strncat(filename, barra, sizeof(filename) );
        strncpy(filename1, subPath, sizeof(filename1));
        strcat(filename,filename1);
        //printf("Filename is %s\n", filename);
        
        char* final = filename;
        return final;

	}
	
	return "";
}

void substring(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}
