#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int n, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void helper(int *arr, int n, int low, int high)
{
    if (low > high)
    {
        return;
    }
    int pi = partition(arr, n, low, high);
    helper(arr, n, low, pi - 1);
    helper(arr, n, pi + 1, high);
}

void quickSort(int *arr, int n)
{
    helper(arr, n, 0, n - 1);
    return;
}

int main()
{
    int *arr, n;
    printf("Input size: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Input elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, n);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}