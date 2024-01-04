#include <stdio.h>
#include <math.h>

int main()
{
    float i, n, mean, sd = 0, num, sum = 0, ans;
    printf("Enter the value of n: ");
    scanf("%f", &n);

    printf("Enter the values: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%f", &num);
        sum = sum + num;
    }
    mean = sum / n;
    printf("The mean of the entered numbers are: %.2f\n", mean);

    printf("Enter the inputs again: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%f", &num);
        sd += pow(num - mean, 2);
    }
    ans = sqrt(sd / n);
    printf("The Standard Deviation of the numbers is %.2f\n", ans);

    return 0;
}