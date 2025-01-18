#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// Thread function
void *threadfunc(void *arg)
{
    int id = *(int *)arg; // Retrieve thread ID
    printf("\nThread %d started, sleeping for %d second(s)", id, id);
    sleep(id); // Simulate work by sleeping for 'id' seconds
    printf("\nThread %d finished execution", id);
    return NULL;
}

int main()
{
    int num = 5; // Number of threads
    pthread_t threads[num];
    int ids[num];
    int i;

    // Create threads
    for (i = 0; i < num; i++)
    {
        ids[i] = i + 1; // Assign a unique ID to each thread
        if (pthread_create(&threads[i], NULL, threadfunc, &ids[i]) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Join threads in reverse order
    for (i = num - 1; i >= 0; i--)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return 1;
        }
        printf("\nThread %d is joined", i + 1);
    }

    printf("\nAll threads joined\n");
    return 0;
}
