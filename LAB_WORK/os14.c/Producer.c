#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int pipefd, res;
    char buffer[1024];

    printf("\nEnter data: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remove the trailing newline character added by fgets
    buffer[strcspn(buffer, "\n")] = '\0';

    // Create FIFO if it doesn't exist
    if (mkfifo("fifo3", 0777) == -1)
    {
        perror("mkfifo");
    }

    printf("\nProcess %d opening FIFO for writing...\n", getpid());
    pipefd = open("fifo3", O_WRONLY);
    if (pipefd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Process %d successfully opened FIFO.\n", getpid());
    res = write(pipefd, buffer, strlen(buffer) + 1); // Include null terminator
    if (res == -1)
    {
        perror("write");
    }
    else
    {
        printf("Written %d bytes: %s\n", res, buffer);
    }

    close(pipefd);
    printf("\nProcess %d finished writing.\n", getpid());
    return 0;
}
