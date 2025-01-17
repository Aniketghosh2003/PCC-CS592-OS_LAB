#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>
void main()
{
    int p;
    p = fork();
    if (p == 0)
    {
        printf("\nI am the child process and my pid is %d and my parent process id is %d", getpid(), getppid());
        printf("\nNow I will get replaced by another programm");
        execl("./5b_newchild","5b_newchild", NULL);
        printf("\nYou can not read me.");
    }
    else
    {
        wait(0);
        printf("\nI am the parent process and pid is %d", getpid());
    }
}