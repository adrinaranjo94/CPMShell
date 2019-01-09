#include "copy.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char auxDir[4];

//Metodo para remplazar cadenas de caracteres de un string por otras indicadas como parametro.
char *replaceWordRen(const char *s, const char *oldW,const char *newW) { 
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
char* getDirRen(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

//Metodo para devolver el nombre de la unidad seguido de :
char* getDirRenFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

//Metodo para devolver el nombre de la unidad con espacio y :
char* getDirRenSpaceFull(char dir){
	sprintf(auxDir," %c:",dir);
	
	return auxDir;
	
}

//Metodo para devolver el directorio en funcion del alias de la unidad
char* selectDirRen(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirRen(dir1)) == 0){
		pathDir = "./A";
		return pathDir;
	}else if(strcmp(dir,getDirRen(dir2)) == 0){
		pathDir = "./B";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

//Metodo para devolver el segundo directorio en funcion del alias de la unidad
char* selectSecondDirRen(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirRen(dir1)) == 0){
		pathDir = " ./A/";
		return pathDir;
	}else if(strcmp(dir,getDirRen(dir2)) == 0){
		pathDir = " ./B/";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

//Metodo para crear los parametros comando a ejecutar
char* checkParametersRen(char path[],char actualDir[],char dir1, char dir2){
	char* auxPath;
	char subPath[strlen(path)];
	char auxSubRen[strlen(subPath)];
	char *finalPath;
	
	char prueba[2];
	
	char filename[128];
	char filename1[128];
	char *barra="/";
	
	if(strstr(path,getDirRenFull(dir1)) != NULL || strstr(path,getDirRenFull(dir2)) != NULL){
		substring(path,auxSubRen,5,2);
		sprintf(prueba,"%s",auxSubRen);
		if(strcmp(getDirRenFull(dir1),auxSubRen) == 0){
			auxPath = "./A";
			substring(path,subPath,7,strlen(path));
			strncpy(filename, auxPath, sizeof(filename));
			strncat(filename, barra, sizeof(filename) );
		}else if(strcmp(getDirRenFull(dir2),auxSubRen) == 0){
			auxPath = "./B";
			substring(path,subPath,7,strlen(path));
			strncpy(filename, auxPath, sizeof(filename));
			strncat(filename, barra, sizeof(filename) );
		}else{
			auxPath = selectDirRen(actualDir,dir1,dir2);
			substring(path,subPath,5,strlen(path));
			strncpy(filename, auxPath, sizeof(filename));
			strncat(filename, barra, sizeof(filename) );
		}
		
		if(strstr(subPath,getDirRenSpaceFull(dir1)) !=NULL){
			finalPath = replaceWordRen(subPath,getDirRenSpaceFull(dir1)," ./A/");
		}else if(strstr(subPath,getDirRenSpaceFull(dir2)) != NULL){
			finalPath = replaceWordRen(subPath,getDirRenSpaceFull(dir2)," ./B/");
		}else{
			finalPath = replaceWordRen(subPath," ",selectSecondDirRen(actualDir,dir1,dir2));
		}
		
		strncpy(filename1, finalPath, sizeof(filename1));
		strcat(filename,filename1);
			
	}else{
		auxPath = selectDirRen(actualDir,dir1,dir2);
		substring(path,subPath,5,strlen(path));
		
		finalPath = replaceWordRen(subPath," ",selectSecondDirRen(actualDir,dir1,dir2));
		
		strncpy(filename, auxPath, sizeof(filename));
		strncat(filename, barra, sizeof(filename) );
		strncpy(filename1, finalPath, sizeof(filename1));
		strcat(filename,filename1);
	}
	
	char* final = filename;
	return final;
}

//Metodo para crear el comando final uniendo los parametros con el comando a ejecutar
char* methodRen(char dir[]){
	char rpath[255];
	char ldir[255];
	char lFinal[255];
	strncpy(rpath, "mv ", sizeof(rpath));
    strncpy(ldir, dir, sizeof(ldir));
    strncpy(lFinal,rpath,sizeof(lFinal));
    strncat(lFinal,ldir,sizeof(lFinal));

	char* afinal = lFinal;
	return afinal;
}

//Metodo inicial de la libreria para devolver el comando final
char* use_ren(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"REN") == 0){
		return "echo Para usar el comando REN debes introducir dos parametros.\nSi deseas saber mas informacion sobre el metodo introduce el comando HELP";
	}else{
		return methodRen(checkParametersRen(query,actualDir,dir1,dir2));
	}
}


