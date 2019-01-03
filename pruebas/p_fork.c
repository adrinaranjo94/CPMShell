#include <stdio.h>
#include <string.h>

int main() 
{ 
/*
 int myvar = 0; 
    if(fork()) 
     myvar = 1; 
    else if(fork()) 
     myvar = 2; 
    else 
     myvar = 3; 

    printf("I'm %d: myvar is %d\n", getpid(), myvar); 
    return 0; 
*/
    
    const char *progname = "./yourProgName"; 
    const char *argument1 = "arg1"; 
    const char *argument2 = "arg2"; 

    //printf("I'm %d: myargument is %s & %s\n", getpid(), argument1, argument2);

    if (fork() == 0) 
    { 
        argument1 = "argument1"; 
        argument2 = "argument2"; 
        // We are the child process, so replace the process with a new executable. 
        execl(progname, progname, argument1, argument2, (char *)NULL); 
        //printf("I'm %d: myargument is %s & %s\n", getpid(), argument1, argument2);

    } 
    // The parent process continues from here. 

    printf("I'm %d: myargument is %s & %s\n", getpid(), argument1, argument2);
 return 0; 
} 