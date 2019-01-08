#include <string.h>
#include <stdlib.h>

char auxDir[3];

void substringEra(char s[], char sub[], int p, int l);

char* getDirEra(char dir);

char* getDirEraFull(char dir);

char* selectDirEra(char dir[],char dir1, char dir2);

char* checkParametersEra(char path[],char actualDir[],char dir1, char dir2);

char* methodEra(char dir[]);

char* use_era(char query[],char actualDir[],char dir1, char dir2);
