/* Write a program to merge two sorted arrays.*/
#include <stdio.h>
void merge(int *a, int n, int *b, int p, int *c, int *total)
{
    int i, j, k;
    for (i = j = k = 0; i < n && j < p;)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    for (; i < n; c[k++] = a[i++])
        ;
    for (; j < p; c[k++] = b[j++])
        ;
    *total = n + p;
}
int main()
{
    int a[] = {1, 3, 5, 7, 9}, b[] = {2, 4, 6, 8, 12, 14, 17}, c[12], total, i;
    merge(a, 5, b, 7, c, &total);
    printf("Merged array is ");
    for (i = 0; i < total; i++)
        printf("%d ", c[i]);
}