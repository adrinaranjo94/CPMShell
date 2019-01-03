//
//  readConf.c
//  
//
//  Created by Sergio Redondo on 27/12/2018.
//

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void readConf();

char c1 = ' ';
char c2 = ' ';

int main(void)
{
    c1 = 'a';
    printf("%c",c1);
    readConf();
    
    
    return 0;
}

void readConf(){
    FILE * fp;
    fp = fopen("./.cmpconfig.txt", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    if (fp == NULL){
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
        printf("%c", line[0]);
        if(i = 0){
            c1 = line[0];
            i++;
        }else{
            c2 = line[0];
        }
    }
    printf("\n");
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
    
}
