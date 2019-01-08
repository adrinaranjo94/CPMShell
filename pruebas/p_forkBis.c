#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main() 
{   

    if (fork() == 0) { 
        system("ls");
    } else {
        wait(NULL);
        printf("holi hijito mio");
    }

 return 0; 
} 
