
#include "era.h"
#include <stdio.h>

char auxDir[4];

//Metodo para remplazar cadenas de caracteres de un string por otras indicadas como parametro.
void substringEra(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

//Metodo para devolver el nombre de la unidad
char* getDirEra(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

//Metodo para devolver el nombre de la unidad seguido de :
char* getDirEraFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

//Metodo para devolver el directorio en funcion del alias de la unidad
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

//Metodo para crear los parametros comando a ejecutar
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

//Metodo para crear el comando final uniendo los parametros con el comando a ejecutar
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

//Metodo inicial de la libreria para devolver el comando final
char* use_era(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"ERA") == 0){
		return "rm ";
	}else{
		return methodEra(checkParametersEra(query,actualDir,dir1,dir2));
	}
	
}
