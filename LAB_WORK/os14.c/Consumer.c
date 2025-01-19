#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int pipefd, res;
    char buffer[1024];

    printf("\nProcess %d opening FIFO for reading...\n", getpid());
    pipefd = open("fifo3", O_RDONLY);
    if (pipefd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("\nProcess %d successfully opened FIFO.\n", getpid());
    res = read(pipefd, buffer, sizeof(buffer) - 1); // Leave space for null terminator
    if (res == -1)
    {
        perror("read");
        close(pipefd);
        exit(EXIT_FAILURE);
    }

    buffer[res] = '\0'; // Null-terminate the string
    printf("\nProcess %d finished by reading '%s' (%d bytes).\n", getpid(), buffer, res);

    close(pipefd);

    // Unlink FIFO after reading
    if (unlink("fifo3") == -1)
    {
        perror("unlink");
    }

    return 0;
}
