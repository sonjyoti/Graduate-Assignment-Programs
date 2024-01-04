// 8. Write a program to create threads, the main thread creates three threads. Two of the threads increment a counter variable while the third thread watches the value of the counter variable. When the counter variable reaches a predefined limit, the waiting thread is signalled by one of the incrementing threads. The waiting thread "awakens" and then modifies the counter. The program continues until the incrementing threads reach a final value and also print the final value.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define MAX_COUNT 10

int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *incrementCounter(void *args)
{
    int thNum = *((int *)args);

    for (int i = 0; i < MAX_COUNT; ++i)
    {
        pthread_mutex_lock(&mutex);
        count++;

        if (count == MAX_COUNT)
        {
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }
    printf("Incrementing Thread %d finished. Final value: %d\n", thNum, count);

    pthread_exit(NULL);
}

void *waitForCounter(void *args)
{
    pthread_mutex_lock(&mutex);
    while (count < MAX_COUNT)
    {
        pthread_cond_wait(&cond, &mutex);
    }
    count += 100;

    pthread_mutex_unlock(&mutex);

    printf("Waiting Thread modified the counter. Final value: %d\n", count);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadNumbers[NUM_THREADS] = {1, 2, 3};

    for (int i = 0; i < NUM_THREADS - 1; ++i)
    {
        pthread_create(&threads[i], NULL, incrementCounter, (void *)&threadNumbers[i]);
    }

    pthread_create(&threads[NUM_THREADS - 1], NULL, waitForCounter, (void *)&threadNumbers[NUM_THREADS - 1]);

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}