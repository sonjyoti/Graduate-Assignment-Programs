#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int *arr;
    int n;
    printf("Input size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Input %d elements for the array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("\nArray before sorting: ");
    printArray(arr, n);
}