#include <stdio.h>

void binary(int n)
{
    if (n == 0)
        printf("0");
    else if (n == 1)
        printf("1");
    else
    {
        binary(n / 2);
        printf("%d", n % 2);
    }
}

int main()
{
    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    binary(n);
    printf("\n");
    return 0;
}