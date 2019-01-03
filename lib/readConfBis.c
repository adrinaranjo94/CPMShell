//
//  readConfBis.c
//  
//
//  Created by Carlos Rodriguez on 27/12/2018.
//

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void readConf();

char c1 = ' ';
char c2 = ' ';

int main(void)
{
    readConf();
    
    printf("%c\n",c1);
    printf("%c\n",c2);
    
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
        if(i == 0){
            c1 = line[0];
            i++;
        }else{
            c2 = line[0];
        }
    }
    fclose(fp);
    if (line)
        free(line);
    
    return;
    
}
