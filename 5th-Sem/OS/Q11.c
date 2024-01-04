// 13. Write a program to implement Banker's Algorithm for multiple resource type each.

#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int inSafe(int process, int request[])
{
    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        if (request[i] > need[process][i] || request[i] > available[i])
        {
            return 0;
        }
    }
    return 1;
}

void allocateResources(int process, int request[])
{
    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }
}

void releaseResources(int process, int request[])
{
    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        available[i] += request[i];
        allocation[process][i] -= request[i];
        need[process][i] += request[i];
    }
}

int bankerAlgorithm(int process, int request[])
{
    if (inSafe(process, request))
    {
        allocateResources(process, request);
        if (inSafe(process, request))
        {
            printf("Request granted. New state is safe.\n");
            return 1;
        }
        else
        {
            releaseResources(process, request);
            printf("Request denied. New state is unsafe.\n");
            return 0;
        }
    }
    else
    {
        printf("Request denied. Process would be in an unsafe state.\n");
        return 0;
    }
}

void displayState()
{
    printf("\nCurrent State:\n");
    printf("Available resources:");

    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        printf("%d ", available[i]);
    }

    printf("\n");

    printf("Maximum matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            printf("%d ", maximum[i][j]);
        }
        printf("\n");
    }

    printf("Allocation matrix:\n");

    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("Need matrix.\n");

    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the available resources for each type: ");
    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        scanf("%d", &available[i]);
    }

    printf("Enter the  maximum matrix (process x resource):\n");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            scanf("%d", &maximum[i][j]);
            need[i][j] = maximum[i][j];
        }
    }

    printf("Enter the  allocation matrix (process x resource):\n");
    for (int i = 0; i < MAX_PROCESSES; ++i)
    {
        for (int j = 0; j < MAX_RESOURCES; ++j)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] -= maximum[i][j];
        }
    }

    displayState();

    int process;
    printf("\nEnter the process requesting resources(0 to %d): ", MAX_PROCESSES - 1);
    scanf("%d", &process);

    if (process < 0 || process >= MAX_PROCESSES)
    {
        printf("Invalid process number.\n");
        return 1;
    }
    int request[MAX_RESOURCES];
    printf("Enter the resource request for each type: ");
    for (int i = 0; i < MAX_RESOURCES; ++i)
    {
        scanf("%d", &request[i]);
    }
    if (bankerAlgorithm(process, request))
    {
        displayState();
    }
    return 0;
}