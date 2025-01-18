#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

// Thread function
void *addnumbers(void *arg)
{
    int *nums = (int *)arg;                                                         // Cast argument to int pointer
    int res = nums[0] + nums[1];                                                    // Calculate the sum
    char *message = (char *)malloc(60 * sizeof(char));                              // Allocate memory for the result message
    sprintf(message, "\nThe Sum of digits %d and %d is %d", nums[0], nums[1], res); // Format result
    return (void *)message;                                                         // Return the message
}

int main()
{
    pthread_t thread;
    int nums[2] = {10, 20}; // Input numbers

    // Create the thread
    if (pthread_create(&thread, NULL, addnumbers, nums) != 0)
    {
        perror("Failed to create thread");
        return 1;
    }

    char *message;
    // Wait for the thread to complete
    if (pthread_join(thread, (void **)&message) != 0)
    {
        perror("Failed to join thread");
        return 1;
    }

    // Print the result
    printf("%s\n", message);
    free(message); // Free allocated memory

    return 0;
}
