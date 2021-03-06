#include "copy.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char auxDir[4];

//Metodo para remplazar cadenas de caracteres de un string por otras indicadas como parametro.
char *replaceWordCopy(const char *s, const char *oldW,const char *newW) { 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    for (i = 0; s[i] != '\0'; i++) 
    { 
        if (strstr(&s[i], oldW) == &s[i]) 
        { 
            cnt++; 

            i += oldWlen - 1; 
        } 
    } 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) { 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 

//Metodo para devolver el nombre de la unidad
char* getDirCopy(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

//Metodo para devolver el nombre de la unidad seguido de :
char* getDirCopyFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

//Metodo para devolver el nombre de la unidad con espacio y :
char* getDirCopySpaceFull(char dir){
	sprintf(auxDir," %c:",dir);
	
	return auxDir;
	
}

//Metodo para devolver el directorio en funcion del alias de la unidad
char* selectDirCopy(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirCopy(dir1)) == 0){
		pathDir = "./A";
		return pathDir;
	}else if(strcmp(dir,getDirCopy(dir2)) == 0){
		pathDir = "./B";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

//Metodo para devolver el segundo directorio en funcion del alias de la unidad
char* selectSecondDirCopy(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirCopy(dir1)) == 0){
		pathDir = " ./A/";
		return pathDir;
	}else if(strcmp(dir,getDirCopy(dir2)) == 0){
		pathDir = " ./B/";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}


//Metodo para crear los parametros comando a ejecutar
char* checkParametersCopy(char path[],char actualDir[],char dir1, char dir2){
	char* auxPath;
	char subPath[strlen(path)];
	char auxSubDir[strlen(subPath)];
	char *finalPath;
	
	char prueba[2];
	
	char filename[128];
	char filename1[128];
	char *barra="/";
	
	if(strstr(path,getDirCopyFull(dir1)) != NULL || strstr(path,getDirCopyFull(dir2)) != NULL){
		substring(path,auxSubDir,6,2);
		sprintf(prueba,"%s",auxSubDir);
		if(strcmp(getDirCopyFull(dir1),auxSubDir) == 0){
			auxPath = "./A";
			substring(path,subPath,8,strlen(path));
			strncpy(filename, auxPath, sizeof(filename));
			strncat(filename, barra, sizeof(filename) );
		}else if(strcmp(getDirCopyFull(dir2),auxSubDir) == 0){
			auxPath = "./B";
			substring(path,subPath,8,strlen(path));
			strncpy(filename, auxPath, sizeof(filename));
			strncat(filename, barra, sizeof(filename) );
		}else{
			auxPath = selectDirCopy(actualDir,dir1,dir2);
			substring(path,subPath,6,strlen(path));
			strncpy(filename, auxPath, sizeof(filename));
			strncat(filename, barra, sizeof(filename) );
		}
		
		if(strstr(subPath,getDirCopySpaceFull(dir1)) !=NULL){
			finalPath = replaceWordCopy(subPath,getDirCopySpaceFull(dir1)," ./A/");
		}else if(strstr(subPath,getDirCopySpaceFull(dir2)) != NULL){
			finalPath = replaceWordCopy(subPath,getDirCopySpaceFull(dir2)," ./B/");
		}else{
			finalPath = replaceWordCopy(subPath," ",selectSecondDirCopy(actualDir,dir1,dir2));
		}
		
		strncpy(filename1, finalPath, sizeof(filename1));
		strcat(filename,filename1);
			
	}else{
		auxPath = selectDirCopy(actualDir,dir1,dir2);
		substring(path,subPath,6,strlen(path));
		
		finalPath = replaceWordCopy(subPath," ",selectSecondDirCopy(actualDir,dir1,dir2));
		
		strncpy(filename, auxPath, sizeof(filename));
		strncat(filename, barra, sizeof(filename) );
		strncpy(filename1, finalPath, sizeof(filename1));
		strcat(filename,filename1);
	}
	
	char* final = filename;
	return final;
}

//Metodo para crear el comando final uniendo los parametros con el comando a ejecutar
char* methodCopy(char dir[]){
	char rpath[255];
	char ldir[255];
	char lFinal[255];
	strncpy(rpath, "cp ", sizeof(rpath));
    strncpy(ldir, dir, sizeof(ldir));
    strncpy(lFinal,rpath,sizeof(lFinal));
    strncat(lFinal,ldir,sizeof(lFinal));

	char* afinal = lFinal;
	return afinal;
}

//Metodo inicial de la libreria para devolver el comando final
char* use_copy(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"COPY") == 0){
		return "echo Para usar el comando COPY debes introducir dos parametros.\nSi deseas saber mas informacion sobre el metodo introduce el comando HELP";
	}else{
		return methodCopy(checkParametersCopy(query,actualDir,dir1,dir2));
	}
}


