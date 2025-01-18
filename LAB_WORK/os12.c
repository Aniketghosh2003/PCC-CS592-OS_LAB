#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipefd[2]; // Array for pipe file descriptors
    char data[1024], buffer[1024];
    pid_t pid;

    // Create a pipe
    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Prompt user for input
    printf("\nEnter data: ");
    scanf("%s", data);

    // Fork a new process
    pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    { // Child process
        // Close unused read end
        close(pipefd[0]);

        // Write data to the pipe
        int res = write(pipefd[1], data, strlen(data));
        printf("\nChild wrote %d bytes to the pipe", res);

        // Close write end
        close(pipefd[1]);

        exit(EXIT_SUCCESS);
    }
    else
    { // Parent process
        // Close unused write end
        close(pipefd[1]);

        // Read data from the pipe
        int res = read(pipefd[0], buffer, sizeof(buffer) - 1);
        buffer[res] = '\0'; // Null-terminate the string

        printf("\nParent read %d bytes: %s", res, buffer);

        // Close read end
        close(pipefd[0]);

        // Wait for child process to finish
        wait(NULL);

        printf("\nParent: All done!\n");
    }

    return 0;
}
