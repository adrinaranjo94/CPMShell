
#include "dir.h"
#include <stdio.h>

char auxDir[4];

//Metodo para remplazar cadenas de caracteres de un string por otras indicadas como parametro.
void substring(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

//Metodo para devolver el nombre de la unidad
char* getDirDir(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

//Metodo para devolver el nombre de la unidad seguido de :
char* getDirDirFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

//Metodo para devolver el directorio en funcion del alias de la unidad
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

//Metodo para crear los parametros comando a ejecutar
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

//Metodo para crear el comando final uniendo los parametros con el comando a ejecutar
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

//Metodo inicial de la libreria para devolver el comando final
char* use_dir(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"DIR") == 0){
		return showFiles(selectDir(actualDir,dir1,dir2));
	}else{
		return showFiles(checkParameters(query,actualDir,dir1,dir2));
	}
}
