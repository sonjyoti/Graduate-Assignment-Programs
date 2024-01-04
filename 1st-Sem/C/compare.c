#include <stdio.h>

int main()
{
    int n, i, min, max, num, sum = 0;
    float avg;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);

        if (i == 0)
        {
            min = num;
            max = num;
        }
        else
        {
            min = min > num ? num : min;
            max = max > num ? max : num;
        }

        sum = sum + num;
    }
    avg = (float)sum / n;

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}