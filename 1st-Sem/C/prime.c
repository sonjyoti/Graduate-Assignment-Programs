#include <stdio.h>

int prime(int n)
{
    int i;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n, m, i;
    printf("Input the values of the range: ");
    scanf("%d %d", &n, &m);

    printf("The prime numbers in the range of %d and %d are: ", n, m);
    for (i = n; i <= m; i++)
    {
        if (prime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}


// another approach

/*int n, i;
    scanf("%d", &n);
    for(i = 2; i*i <= n; i++) iterating till sqrt of n because after that all the checks will be the above done and hence would be repeatative
    {
        if(n % i == 0)
        {
            printf("Not prime\n");
            return 0;
        }
    }
    printf("Prime\n");
    return 0;
}
*/
