#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main() 
{   
    int* test;
    test = 1;
    if (fork() == 0) {
        system("ls");
        test = 0;
    } else {
        wait(NULL);
        printf("holi hijito mio %d", *test);
    }

 return 0; 
} 
