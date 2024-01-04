#include <stdio.h>

void printPascal(int n)
{
    int l, i;
    for (l = 0; l < n; l++)
    {
        for (i = 0; i <= l; i++)
            printf("%d ",
                   binomialCoeff(l, i));
        printf("\n");
    }
}

int binomialCoeff(int n, int k)
{
    int res = 1, i;
    if (k > n - k)
        k = n - k;
    for (i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printPascal(n);
    return 0;
}
