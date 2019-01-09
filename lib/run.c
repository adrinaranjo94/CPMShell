
#include "run.h"
#include <stdio.h>

char auxDir[4];

void substringRun(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

char* getDirRun(char dir){
	sprintf(auxDir,"%c",dir);
	
	return auxDir;
	
}

char* getDirRunFull(char dir){
	sprintf(auxDir,"%c:",dir);
	
	return auxDir;
	
}

char* selectDirRun(char dir[],char dir1, char dir2){
	
	char *pathDir = ""; 
	if(strcmp(dir,getDirRun(dir1)) == 0){
		pathDir = "./A";
		return pathDir;
	}else if(strcmp(dir,getDirRun(dir2)) == 0){
		pathDir = "./B";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

char* checkParametersRun(char path[],char actualDir[],char dir1, char dir2){
	char* auxPath;
	char subPath[strlen(path)];
	if(strstr(path,getDirRunFull(dir1)) != NULL){
		auxPath = "NULL";
		substringRun(path,subPath,7,strlen(path));
	}else if(strstr(path,getDirRunFull(dir2)) != NULL){
		auxPath = "NULL";
		substringRun(path,subPath,7,strlen(path));
	}else{
		auxPath = selectDirRun(actualDir,dir1,dir2);
		substringRun(path,subPath,5,strlen(path));
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

char* methodRun(char dir[]){
	char rpath[255];
	char ldir[255];
	char lFinal[255];

	char auxDirFull[10];
	char finalDirFull[10];
	char auxlDirComplete[128];
	char finallDirComplete[128];
	if(strstr(dir,"NULL") != NULL){
		strncpy(rpath, "echo ", sizeof(rpath));
		strncpy(ldir, "Debes encontrarte en el mismo directorio del archivo que deseas hacer RUN", sizeof(ldir));
		strncpy(lFinal,rpath,sizeof(lFinal));
		strncat(lFinal,ldir,sizeof(lFinal));	
	}else{
		substringRun(dir,auxDirFull,1,4);
		sprintf(finalDirFull,"cd %s;",auxDirFull);
		
		substringRun(dir,auxlDirComplete,5,strlen(dir));
		sprintf(finallDirComplete,"./%s;cd ..",auxlDirComplete);
		
		printf("Dir total %s\n",dir);
		printf("Aux dir %s\n",auxDirFull);
		printf("%s\n",finalDirFull);
		printf("%s\n",finallDirComplete);
		strncpy(rpath, finalDirFull, sizeof(rpath));
		strncpy(ldir, finallDirComplete, sizeof(ldir));
		strncpy(lFinal,rpath,sizeof(lFinal));
		strncat(lFinal,ldir,sizeof(lFinal));
	}
	
	char* afinal = lFinal;
	return afinal;
}

char* use_run(char query[],char actualDir[],char dir1, char dir2){
	if(strcmp(query,"RUN") == 0){
		return "echo Debes indicar el archivo para utilizar este método.\nSi deseas sabes mas informacion sobre como utilizar el metodo introduce el comando HELP";
	}else{
		return methodRun(checkParametersRun(query,actualDir,dir1,dir2));
	}
	
}
