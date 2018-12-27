#define _show_files_h_

#include <string.h>

const char * showFiles(char dir[]){
	char path[255] = "ls -la ";
	strcat(path,dir);

	char* final = path;
	return final;
}



