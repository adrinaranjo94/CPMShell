

#include "era.h"

void substringEra(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

char* selectDirEra(char dir[]){
	
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

char* checkParametersEra(char path[],char actualDir[]){
	char* auxPath;
	char subPath[strlen(path)];
	if(strstr(path,"A:") != NULL){
		auxPath = "./A";
		substringEra(path,subPath,7,strlen(path));
	}else if(strstr(path,"B:") != NULL){
		auxPath = "./B";
		substringEra(path,subPath,7,strlen(path));
	}else{
		auxPath = selectDirEra(actualDir);
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

char* use_era(char query[],char actualDir[]){
	if(strcmp(query,"TYPE") == 0){
		return "rm ";
	}else{
		return methodEra(checkParametersEra(query,actualDir));
	}
	
}
