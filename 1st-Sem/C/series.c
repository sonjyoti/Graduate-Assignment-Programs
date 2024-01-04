#include <stdio.h>
#include <math.h>

int main()
{
    float x, sum, term;
    int t;
    printf("Input value of x");
    scanf("%f", &x);
    x = x * M_PI / 180;
    term = x;
    sum = 0;
    t = 2;
    while (1)
    {
        sum = sum + term;
        term = -1 * term * x * x / ((2 * t - 2) * (2 * t - 1));
        if (fabs(term) < 0.0000001)
            break;
        t++;
    }
    printf("Result= %f\n", sum);
    printf("%f\n", sin(x));
    return 0;
}
