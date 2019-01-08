
#include "dir.h"
#include <stdio.h>

char auxDir[3];

void substring(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}


char* getDirDir(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

char* getDirDirFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

char* selectDir(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirDir(dir1)) == 0){
		pathDir = "./A";
		return pathDir;
	}else if(strcmp(dir,getDirDir(dir2)) == 0){
		pathDir = "./B";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

char* checkParameters(char path[],char actualDir[],char dir1, char dir2){
	char* auxPath;
	char subPath[strlen(path)];
	if(strstr(path,getDirDirFull(dir1)) != NULL){
		auxPath = "./A";
		substring(path,subPath,7,strlen(path));
	}else if(strstr(path,getDirDirFull(dir2)) != NULL){
		auxPath = "./B";
		substring(path,subPath,7,strlen(path));
	}else{
		auxPath = selectDir(actualDir,dir1,dir2);
		substring(path,subPath,5,strlen(path));
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

char* showFiles(char dir[]){
	char rpath[255];
	char ldir[255];
	char lFinal[255];
	strncpy(rpath, "ls -l ", sizeof(rpath));
    strncpy(ldir, dir, sizeof(ldir));
    strncpy(lFinal,rpath,sizeof(lFinal));
    strncat(lFinal,ldir,sizeof(lFinal));

	char* afinal = lFinal;
	return afinal;
}

char* use_dir(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"DIR") == 0){
		return showFiles(selectDir(actualDir,dir1,dir2));
	}else{
		return showFiles(checkParameters(query,actualDir,dir1,dir2));
	}
}
