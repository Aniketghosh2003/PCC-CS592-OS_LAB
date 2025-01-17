#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    int p = fork();
    if (p < 0)
    {
        perror("fork failed");
        exit(1);
    }
    else if (p == 0)
    {
        // child process
        sleep(5);
        printf("\nMy parent is terminated");
        printf("\nMy pid is %d and my parent id %d", getpid(), getppid());
    }
    else
    {
        // parent process
        printf("\nI am parent and my pid is %d", getpid());
        exit(0);
    }
}