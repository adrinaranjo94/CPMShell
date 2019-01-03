

#include "dir.h"
#include <stdio.h>

void substringType(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

char* selectDirType(char dir[]){
	
	char *pathDir = ""; 
	if(strcmp(dir,"A") == 0){
		pathDir = "./A";
		return pathDir;
	}else if(strcmp(dir,"B") == 0){
		pathDir = "./B";
		return pathDir;
	}else{
		return pathDir;
	}
	
	return pathDir;
}

char* checkParametersType(char path[],char actualDir[]){
	char* auxPath;
	if(strcmp(path,"A:") == 0){
		auxPath = "./A";
	}else if(strcmp(path,"B:") == 0){
		auxPath = "./B";
	}else{
		auxPath = selectDirType(actualDir);
	}
	
	char subPath[strlen(path)];
	char filename[128];
	char filename1[128];
	char *barra="/";
	substringType(path,subPath,6,strlen(path));
	strncpy(filename, auxPath, sizeof(filename));
	strncat(filename, barra, sizeof(filename) );
	strncpy(filename1, subPath, sizeof(filename1));
	strcat(filename,filename1);
	
	char* final = filename;
	printf("Final con auxpath: %s\n",final);
	printf("PATH: %s\n",path);
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

char* use_type(char query[],char actualDir[]){
	if(strcmp(query,"TYPE") == 0){
		return "cat ";
	}else{
		return methodType(checkParametersType(query,actualDir));
	}
	
}
