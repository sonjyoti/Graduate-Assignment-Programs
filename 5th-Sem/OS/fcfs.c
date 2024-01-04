
// Q. Implement the fcfs algorithm.

#include <stdio.h>

#define MAX_PROCESSES 5

struct Process
{
    int id, burstTime;
};

typedef struct Process Process;

void fcfs(Process process[], int n)
{
    int waiting_time = 0, turn_around_time = 0;
    printf("\nProcess\tBurst Time\tWaiting time\tTurn Around Time\n");
    for (int i = 0; i < n; ++i)
    {
        turn_around_time += process[i].burstTime;
        waiting_time = turn_around_time - process[i].burstTime;

        printf("%d\t%d\t\t%d\t\t%d\n", process[i].id, process[i].burstTime, waiting_time, turn_around_time);
    }

    float avg_wait_time = (float)waiting_time / n;
    float avg_turnaround_time = (float)turn_around_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("\nAverage Turn Around Time: %.2f\n", avg_turnaround_time);
}

int main()
{
    Process process[MAX_PROCESSES];
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        process[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i].burstTime);
    }
    fcfs(process, MAX_PROCESSES);
}
