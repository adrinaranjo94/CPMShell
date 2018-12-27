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

int main(void)
{
    
    readConf();
    
    
    return 0;
}

void readConf(){
    FILE * fp;
    fp = fopen("./.cmpconfig.txt", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    if (fp == NULL)
        exit(EXIT_FAILURE);
    
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }
    printf("\n");
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
    
}
