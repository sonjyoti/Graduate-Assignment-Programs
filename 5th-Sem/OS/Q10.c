// 10. Write a program to show the communication between two processes through shared memory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

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

    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        char *shared_memory = (char *)shmat(shm_id, NULL, 0);
        if (shared_memory == (char *)(-1))
        {
            perror("shmat");
            exit(EXIT_FAILURE);
        }
        strcpy(shared_memory, "Hello from Child.");
        if (shmdt(shared_memory) == -1)
        {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        wait(NULL);
        char *shared_memory = (char *)shmat(shm_id, NULL, 0);
        if (shared_memory == (char *)(-1))
        {
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        printf("Message received from Child: %s\n", shared_memory);

        if (shmdt(shared_memory) == -1)
        {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }
        if (shmctl(shm_id, IPC_RMID, NULL) == -1)
        {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}