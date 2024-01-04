// 5. Write a program to demonstrate how to "wait" for thread completions by using the P thread join routine. Threads are explicitly created in a joinable state.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *threadFun(void *thread)
{
    long tid = (long)thread;
    printf("Thread started.");

    for (int i = 0; i < 3; ++i)
    {
        printf("Thread %ld is in process...\n", tid);
        sleep(1);
    }
    printf("Thread %ld  completed.\n", tid);

    pthread_exit((void *)tid);
}

int main()
{
    pthread_t threads[3];
    int res;
    for (long t = 0; t < 3; ++t)
    {
        printf("Creating thread %ld\n", t);

        res = pthread_create(&threads[t], NULL, threadFun, (void *)t);
        if (res)
        {
            fprintf(stderr, "Error creating thread %ld\n", t);
            exit(EXIT_FAILURE);
        }
    }

    for (long t = 0; t < 3; ++t)
    {
        void *retVal;
        if (pthread_join(threads[t], &retVal) != 0)
        {
            fprintf(stderr, "Error joining thread %ld\n", t);
            exit(EXIT_FAILURE);
        }
        printf("Thread %ld joined. Return value: %ld \n", t, (long)retVal);
    }
    printf("Main thread terminating.\n");
    return 0;
}