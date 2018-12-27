#include <stdio.h>
#include <string.h>

const char * selectDir(char path[]);
void showFiles(char path[]);
int main(){
	
	system("clear");
	showFiles(selectDir("actual"));

	
	return 0;
	
}

const char * selectDir(char dir[]){
	if(strcmp(dir,"padre") == 0){
		printf("Mostrando directorio %s",dir);
		return "../";
	}else if(strcmp(dir,"actual") == 0){
		printf("Mostrando directorio %s",dir);
		return ".";
	}else{
		return "";
	}
	
	return "";
}

void showFiles(char dir[]){
	char path[255];
	strcat(path,"ls -la ");
	strcat(path,dir);

	system(path);
	
}

