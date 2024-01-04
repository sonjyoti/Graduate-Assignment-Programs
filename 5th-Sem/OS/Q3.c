// 3. Write a program to show a process can ignore a signal.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_signal(int signum)
{
    printf("%d: child process signal ignoring.\n", signum);
}

int main()
{
    pid_t pid = fork();
    signal(SIGTERM, SIG_IGN);
    if (pid == -1)
    {
        perror("Error creating child process!");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        signal(SIGTERM, handle_signal);
        printf("Child process started.\n");
        while (1)
        {
            printf("Inside child process loop...\n");
            sleep(5);
        }
        printf("Child process terminating.\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Parent process waiting for child to terminate.\n");
        sleep(2);
        kill(pid, SIGTERM);
        int status;
        waitpid(pid, &status, 0);
        printf("Parent process terminating.\n");
    }
    return 0;
}