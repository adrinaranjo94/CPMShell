
#include "type.h"
#include <stdio.h>

char auxDir[4];

void substringType(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

char* getDirType(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

char* getDirTypeFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

char* selectDirType(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirType(dir1)) == 0){
		pathDir = "./A";
		return pathDir;
	}else if(strcmp(dir,getDirType(dir2)) == 0){
		pathDir = "./B";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

char* checkParametersType(char path[],char actualDir[],char dir1, char dir2){
	char* auxPath;
	char subPath[strlen(path)];
	if(strstr(path,getDirTypeFull(dir1)) != NULL){
		auxPath = "./A";
		substringType(path,subPath,8,strlen(path));
	}else if(strstr(path,getDirTypeFull(dir2)) != NULL){
		auxPath = "./B";
		substringType(path,subPath,8,strlen(path));
	}else{
		auxPath = selectDirType(actualDir,dir1,dir2);
		substringType(path,subPath,6,strlen(path));
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

char* methodType(char dir[]){
	char rpath[255];
	char ldir[255];
	char lFinal[255];
	strncpy(rpath, "cat ", sizeof(rpath));
    strncpy(ldir, dir, sizeof(ldir));
    strncpy(lFinal,rpath,sizeof(lFinal));
    strncat(lFinal,ldir,sizeof(lFinal));

	char* afinal = lFinal;
	return afinal;
}

char* use_type(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"TYPE") == 0){
		return "cat ";
	}else{
		return methodType(checkParametersType(query,actualDir,dir1,dir2));
	}
	
}
