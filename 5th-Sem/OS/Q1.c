// 1. Write a program to create a child process that starts looping and then terminates.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

void child_process()
{
    printf("Child process started.\n");
    while (1)
    {
        printf("Inside child process loop...\n");
        sleep(1);
    }
}

int main()
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Error creating child process.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        child_process();
    }
    else
    {
        printf("Parent process waiting for child to terminate.\n");
        sleep(5);
        kill(pid, SIGTERM);

        printf("Parent process terminating.\n");
    }
    return 0;
}