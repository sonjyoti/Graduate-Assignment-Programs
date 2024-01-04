#include <stdio.h>
#include <math.h>

int fibonacci(int n)
{
    if (n < 2)
        return n;

    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main()
{
    int n, i;
    printf("Input the vale of n: ");
    scanf("%d", &n);
    printf("Printing upto %dth fibonacci number: ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}
