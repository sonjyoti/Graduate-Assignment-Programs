#include <stdio.h>

int factorialRec(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * (factorialRec(n - 1)));
}

int factorialNonRec(int n)
{
    unsigned long int fact = 1, i;
    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Factorial of negative number doesn't exist");

    else
    {
        printf("Factorial(from Non Recursive): %d\n", factorialNonRec(n));
        printf("Factorial(from Recursive): %d\n", factorialRec(n));
    }

    return 0;
}