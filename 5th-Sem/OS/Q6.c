// 6. Write a program to create a thread in which print "We are proud to be Indians" and pass multiple arguments using structure during its creation.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ThreadArgs
{
    int thread;
    char message[50];
};

typedef struct ThreadArgs ThArgs;

void *printMsg(void *args)
{
    ThArgs *tArgs = (ThArgs *)args;

    printf("Thread %d says: %s\n", tArgs->thread, tArgs->message);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    ThArgs args;
    args.thread = 1;
    snprintf(args.message, sizeof(args.message), "We are proud to be Indians");

    if (pthread_create(&thread, NULL, printMsg, (void *)&args) != 0)
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