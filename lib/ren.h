#include <string.h>

char auxDir[4];

char *replaceWordRen(const char *s, const char *oldW, const char *newW);

void substring(char s[], char sub[], int p, int l);

char* getDirRen(char dir);

char* getDirRenFull(char dir);

char* getDirRenSpaceFull(char dir);

char* selectDirRen(char dir[],char dir1, char dir2);

char* selectSecondDirRen(char dir[],char dir1, char dir2);

char* checkParametersRen(char path[],char actualDir[],char dir1, char dir2);

char* showFiles(char dir[]);

char* use_ren(char query[],char actualDir[],char dir1, char dir2);
