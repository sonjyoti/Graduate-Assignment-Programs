// 4. Write a program to create a thread in which prints "We are proud to be Indians" and terminates.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printMessage(void *args)
{
    printf("We are proud to be Indians\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    if (pthread_create(&thread, NULL, printMessage, NULL) != 0)
    {
        perror("Error creating thread!\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread, NULL) != 0)
    {
        perror("Error joining thread!\n");
        exit(EXIT_FAILURE);
    }
    printf("Main thread terminating.\n");
    return 0;
}