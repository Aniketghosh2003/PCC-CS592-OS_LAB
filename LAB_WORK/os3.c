#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int q;

    printf("\nBefore creating child process using fork.");
    printf("\nThe current process PID is %d and its parent PID is %d\n", getpid(), getppid());

    q = fork(); 

    if (q < 0)
    {
        printf("\nThere was an error creating the child process.\n");
    }
    else if (q == 0)
    {
        printf("\n[Child Process] The child PID is %d and its parent PID is %d\n", getpid(), getppid());
    }
    else
    {
        printf("\n[Parent Process] The child PID is %d and the parent PID is %d\n", q, getpid());
    }

    printf("\nThis is common code executed by both parent and child processes.\n");
    return 0;
}
