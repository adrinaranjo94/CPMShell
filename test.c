#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int val = 0;

    // create pipe descriptors
    pipe(fd);

    // fork() returns 0 for child process, child-pid for parent process.
    if (fork() != 0)
    {

        // parent: reading only, so close the write-descriptor
        close(fd[1]);

        // now read the data (will block)
        read(fd[0], &val, sizeof(val));
        printf("parent(%d) received value: %d\n", getpid(), val);

        // close the read-descriptor
        close(fd[0]);
        
    }
    else
    {  

        // child: writing only, so close read-descriptor.

close(fd[0]);

        // send the value on the write-descriptor.
        val = 23;
        write(fd[1], &val, sizeof(val));
        printf("child(%d) send value: %d\n", getpid(), val);

        // close the write descriptor
        close(fd[1]);    }
    return 0;
}
