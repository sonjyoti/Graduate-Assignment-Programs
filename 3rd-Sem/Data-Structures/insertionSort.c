
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
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
    printf("Array before sorting: ");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("\nArray after sorting: ");
    printArray(arr, n);
    printf("\n");
    return 0;
}