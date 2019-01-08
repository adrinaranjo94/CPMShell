
#include "era.h"
#include <stdio.h>

void substringEra(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

char* getDirEra(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

char* getDirEraFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

char* selectDirEra(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirEra(dir1)) == 0){
		pathDir = "./A";
		return pathDir;
	}else if(strcmp(dir,getDirEra(dir2)) == 0){
		pathDir = "./B";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

char* checkParametersEra(char path[],char actualDir[],char dir1, char dir2){
	char* auxPath;
	char subPath[strlen(path)];
	if(strstr(path,getDirEraFull(dir1)) != NULL){
		auxPath = "./A";
		substringEra(path,subPath,7,strlen(path));
	}else if(strstr(path,getDirEraFull(dir2)) != NULL){
		auxPath = "./B";
		substringEra(path,subPath,7,strlen(path));
	}else{
		auxPath = selectDirEra(actualDir,dir1,dir2);
		substringEra(path,subPath,5,strlen(path));
	}
	char filename[128];
	char filename1[128];
	char *barra="/";
	strncpy(filename, auxPath, sizeof(filename));
	strncat(filename, barra, sizeof(filename) );
	strncpy(filename1, subPath, sizeof(filename1));
	strcat(filename,filename1);
	
	char* final = filename;
	return final;
}

char* methodEra(char dir[]){
	char rpath[255];
	char ldir[255];
	char lFinal[255];
	strncpy(rpath, "rm ", sizeof(rpath));
    strncpy(ldir, dir, sizeof(ldir));
    strncpy(lFinal,rpath,sizeof(lFinal));
    strncat(lFinal,ldir,sizeof(lFinal));

	char* afinal = lFinal;
	return afinal;
}

char* use_era(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"ERA") == 0){
		return "rm ";
	}else{
		return methodEra(checkParametersEra(query,actualDir,dir1,dir2));
	}
	
}
