// 9. Write a program to show attaching and detaching shared memory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = ftok(".", 'S');

    int shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    char *shared_memory = (char *)shmat(shm_id, NULL, 0);

    if (shared_memory == (char *)(-1))
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    strcpy(shared_memory, "Hello, Shared Memory\n");

    printf("Message written to shared memory: %s", shared_memory);

    if (shmdt(shared_memory) == -1)
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    return 0;
}