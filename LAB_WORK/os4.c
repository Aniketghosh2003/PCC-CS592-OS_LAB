// creates  multiple child and the parent waits for all the child , collects the exit status with MACROS and each child exits a particular exit code
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

void waitexample()
{
    int i, cid, stat;
    pid_t pid[5];
    for (i = 0; i < 5; i++)
    {
        if ((pid[i] = fork()) == 0)
        {
            printf("\nThe child's pid is %d", getpid());
            sleep(1);
            exit(100 + i);
        }
    }
    for (i = 0; i < 5; i++)
    {
        cid = waitpid(pid[i], &stat, 0);
        if (WIFEXITED(stat))
        {
            printf("\nchid %d terminated and exit status is %d", getpid(), WEXITSTATUS(stat));
        }
    }
}

int main()
{
    waitexample();
    return 0;
}