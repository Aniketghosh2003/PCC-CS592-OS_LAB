#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
    int p = fork();
    if (p < 0)
    {
        perror("\nfork failed");
        exit(1);
    }
    else if (p == 0)
    {
        printf("\nChild process starts!!!");
        sleep(10);
        printf("\nMy pid is %d and parent pid is %d", getpid(), getppid());
        exit(0);
    }
    else
    {
        sleep(20);
        printf("\nParent process starts");
        printf("\nMy pid is %d and my child's pid is %d", getpid(), p);
    }
}