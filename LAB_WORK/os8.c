#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
//#include <sys/wait.h>

void child_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("\nChild process received SIGUSR1");
    }
    else if (sig == SIGINT)
    {
        printf("\nChild process received SIGINT,Terminating");
        exit(0);
    }
}

int main()
{
    pid_t p = fork();
    if (p < 0)
    {
        perror("\nfork failed");
    }
    else if (p == 0)
    {
        signal(SIGUSR1, child_handler);
        signal(SIGINT, child_handler);
        while (1)
        {
            sleep(1);
        }
    }
    else
    {
        sleep(2);
        kill(p, SIGUSR1);
        sleep(5);
        kill(p, SIGINT);
        wait(NULL);
        printf("\nparent process : child terminated.\n");
    }
    return 0;
}