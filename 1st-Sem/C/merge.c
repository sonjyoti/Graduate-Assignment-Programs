#include <stdio.h>
#include <stdlib.h>

void inputArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void disArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void mergeArray(int *a, int n1, int *b, int n2, int *c, int n3)
{
    int i = 0, j;
    for (j = 0; i < n2; i++, j++)
        a[i] = b[j];
    for (j = 0; i < n1; i++, j++)
        a[i] = c[j];
}

void selection_sort(int *a, int n)
{
    int pass, small, i, temp;
    for (pass = 1; pass <= n - 1; pass++)
    {
        for (i = small = pass - 1; i < n; i++)
            if (a[i] < a[small])
                small = i;

        temp = a[pass - 1];
        a[pass - 1] = a[small];
        a[small] = temp;
    }
}

int main()
{
    int *a, *b, *c;
    int n1, n2, n3;
    printf("Input the value of n1: ");
    scanf("%d", &n1);
    a = (int *)malloc(n1 * (sizeof(int)));

    printf("Enter the elements for first array: ");
    inputArray(a, n1);
    disArray(a, n1);

    printf("Input the value of n2: ");
    scanf("%d", &n2);
    b = (int *)malloc(n2 * (sizeof(int)));

    printf("Enter the elements for second array: ");
    inputArray(b, n2);
    disArray(b, n2);

    n3 = n1 + n2;
    c = (int *)malloc(n3 * (sizeof(int)));

    mergeArray(c, n3, a, n1, b, n2);

    selection_sort(c, n3);

    printf("Merged array is: \n");
    disArray(c, n3);

    return 0;
}