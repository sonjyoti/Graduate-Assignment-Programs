#include <stdio.h>

int main()
{
    int sale, n, i;
    float com;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter the %d no. sale: ", i);
        scanf("%d", &sale);
        if (sale <= 500)
            com = 0.05 * sale;
        else if (sale <= 2000)
            com = (0.10 * sale) + 35;
        else if (sale <= 5000)
            com = (0.12 * sale) + 185;
        else
            com = (0.125 * sale);
        printf("The commission for the %d no. sale is Rs %.2f\n", i, com);
    }
    return 0;
}