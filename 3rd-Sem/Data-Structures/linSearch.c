#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int main()
{
    int arr[5] = {9, 6, 3, 1, 76};
    int key = 1;
    if (linearSearch(arr, 5, key) != -1)
        printf("Key found at index: %d\n", linearSearch(arr, 5, key));
    else
        printf("Element not found.\n");
    return 0;
}