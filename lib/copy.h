#include <string.h>

char auxDir[4];

char *replaceWord(const char *s, const char *oldW, const char *newW);

void substring(char s[], char sub[], int p, int l);

char* getDirCopy(char dir);

char* getDirCopyFull(char dir);

char* getDirCopySpaceFull(char dir);

char* selectDirCopy(char dir[],char dir1, char dir2);

char* selectSecondDirCopy(char dir[],char dir1, char dir2);

char* checkParametersCopy(char path[],char actualDir[],char dir1, char dir2);

char* showFiles(char dir[]);

char* use_copy(char query[],char actualDir[],char dir1, char dir2);
