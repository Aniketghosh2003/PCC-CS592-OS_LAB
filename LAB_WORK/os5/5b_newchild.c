#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
    printf("\nNow you are replaced with this program.");
    printf("\nI am child process and my pid is %d", getpid());
}