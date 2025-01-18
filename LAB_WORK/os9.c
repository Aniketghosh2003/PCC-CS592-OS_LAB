#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void *thread1func(void *arg)
{
    pid_t pid = getpid();           // Get Process ID
    pthread_t tid = pthread_self(); // Get Thread ID

    printf("\nThread1 PID: %d, TID: %lu", pid, (unsigned long)tid);
    for (int i = 0; i < 5; i++)
    {
        printf("\nThread1 is running...");
        sleep(1); // Simulate work
    }
    return NULL;
}

void *thread2func(void *arg)
{
    pid_t pid = getpid();           // Get Process ID
    pthread_t tid = pthread_self(); // Get Thread ID

    printf("\nThread2 PID: %d, TID: %lu", pid, (unsigned long)tid);
    for (int i = 0; i < 5; i++)
    {
        printf("\nThread2 is running...");
        sleep(1); // Simulate work
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // Create threads
    int rd1 = pthread_create(&thread1, NULL, thread1func, NULL);
    int rd2 = pthread_create(&thread2, NULL, thread2func, NULL);

    if (rd1 != 0 || rd2 != 0)
    {
        perror("Pthread creation failed");
        exit(1);
    }

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nBoth threads finished execution.\n");
    return 0;
}
