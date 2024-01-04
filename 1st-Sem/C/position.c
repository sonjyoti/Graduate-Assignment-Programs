#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, n, i, ele;

    printf("Input the value of n: ");
    scanf("%d", &n);

    a = (int *)malloc((n + 1) * sizeof(int));
    printf("Input the elements: ");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Input the element: ");
    scanf("%d", &ele);

    if (a[n - 1] >= ele)
    {
        for (i = n - 1; i >= 0 && a[i] > ele; i--)
        {
            a[i + 1] = a[i];
            a[i] = ele;
        }
    }
    else
        a[n] = ele;
    for (i = 0; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
