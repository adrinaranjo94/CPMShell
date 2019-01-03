
#include "dir.h"

void substring(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}

char* selectDir(char dir[]){
	
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

char* checkParameters(char path[],char actualDir[]){
	char* auxPath;
	char subPath[strlen(path)];
	if(strstr(path,"A:") != NULL){
		auxPath = "./A";
		substring(path,subPath,7,strlen(path));
	}else if(strstr(path,"B:") != NULL){
		auxPath = "./B";
		substring(path,subPath,7,strlen(path));
	}else{
		auxPath = selectDir(actualDir);
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

char* use_dir(char query[],char actualDir[]){
	if(strcmp(query,"DIR") == 0){
		return showFiles(selectDir(actualDir));
	}else{
		return showFiles(checkParameters(query,actualDir));
	}
	
}
