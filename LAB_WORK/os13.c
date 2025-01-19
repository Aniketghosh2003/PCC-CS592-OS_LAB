#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> // Correct header for `mkfifo`

int main()
{
    int res;
    res = mkfifo("fifo", 0755); // Correct function name is `mkfifo`
    if (res == 0)
    {
        printf("\nFIFO created\n");
        system("ls -l");
    }
    else
    {
        perror("\nFailed to create FIFO");
    }
    return 0;
}
