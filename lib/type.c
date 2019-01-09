
#include "type.h"
#include <stdio.h>

char auxDir[4];

//Metodo para remplazar cadenas de caracteres de un string por otras indicadas como parametro.
void substringType(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

//Metodo para devolver el nombre de la unidad
char* getDirType(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

//Metodo para devolver el nombre de la unidad seguido de :
char* getDirTypeFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

//Metodo para devolver el directorio en funcion del alias de la unidad
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

//Metodo para crear los parametros comando a ejecutar
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

//Metodo para crear el comando final uniendo los parametros con el comando a ejecutar
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

//Metodo inicial de la libreria para devolver el comando final
char* use_type(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"TYPE") == 0){
		return "cat ";
	}else{
		return methodType(checkParametersType(query,actualDir,dir1,dir2));
	}
	
}
