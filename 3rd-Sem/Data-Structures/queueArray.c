#include <stdio.h>
#include <stdlib.h>

int rear = 0;

void enqueue(int *arr, int n)
{
    if (rear == n)
    {
        printf("Overflow...\n");
        return;
    }
    int data;
    printf("Input data: ");
    scanf("%d", &data);
    arr[rear++] = data;
}

void dequeue(int *arr, int n)
{
    if (rear == 0)
    {
        printf("Underflow...\n");
        return;
    }
    for (int i = 1; i < rear; i++)
        arr[i - 1] = arr[i];
    rear--;
}

void printQ(int arr[], int n)
{
    if (rear == 0)
    {
        printf("Empty queue...\n");
        return;
    }
    printf("front-->");
    for (int i = 0; i < rear; i++)
    {
        printf("%d-->", arr[i]);
    }
    printf("rear\n");
}

int main()
{
    int *arr, n;
    printf("Input size: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    enqueue(arr, n);
    printQ(arr, n);
    enqueue(arr, n);
    printQ(arr, n);
    dequeue(arr, n);
    printQ(arr, n);
}