// 7. Write a program to compute the dot product of two vectors and also show the use of mutex variable.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

#define VECTOR_SIZE 5
#define THREAD_SIZE 2

double vector1[VECTOR_SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
double vector2[VECTOR_SIZE] = {5.0, 4.0, 3.0, 2.0, 1.0};

double res = 0.0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct ThreadArgs
{
    int start, end;
};

typedef struct ThreadArgs ThArgs;

void *dotProduct(void *args)
{
    ThArgs *thArgs = (ThArgs *)args;
    double localResult = 0.0;
    for (int i = thArgs->start; i < thArgs->end; ++i)
    {
        localResult += vector1[i] * vector2[i];
    }
    pthread_mutex_lock(&mutex);
    res += localResult;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREAD_SIZE];
    ThArgs thArgs[THREAD_SIZE];
    int step = VECTOR_SIZE / THREAD_SIZE;

    for (int i = 0; i < THREAD_SIZE; ++i)
    {
        thArgs[i].start = i * step;
        thArgs[i].end = (i == THREAD_SIZE - 1) ? VECTOR_SIZE : (i + 1) * step;
        pthread_create(&threads[i], NULL, dotProduct, (void *)&thArgs[i]);
    }

    for (int i = 0; i < THREAD_SIZE; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Dot product: %f\n", res);

    return 0;
}