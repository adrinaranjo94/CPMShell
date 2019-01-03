#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "lib/dir.h"
#include "lib/type.h"


int main(){
	char *actualDir; 
	actualDir = "A";
	char query[255];
	printf("%s:> ",actualDir);
	
	strtok(fgets(query,255,stdin),"\n");
	while(strcmp(query,"EXIT") != 0){
		if(strstr(query,"DIR") != NULL){
			char command[100];
			sprintf(command, "%s", use_dir(query,actualDir));
			system(command);
		}else if(strstr(query,"TYPE") != NULL){
			char command[100];
			printf("%s",use_type(query,actualDir));
			sprintf(command, "%s", use_type(query,actualDir));
			system(command);
		}else if(strcmp(query,"B:") == 0){
			actualDir = "B";
		}else if(strcmp(query,"A:") == 0){
			actualDir = "A";
		}else{
			printf("no se\n");
			printf("%s",query);
		}
		printf("%s:> ",actualDir);
		
		strtok(fgets(query,255,stdin),"\n");
	}
	return 0;
	
}

