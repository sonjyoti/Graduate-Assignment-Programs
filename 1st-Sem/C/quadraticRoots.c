#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float a, b, c, r1, r2, d;
    printf("Enter the values of a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d > 0)
    {
        r1 = -b + sqrt(d) / (2 * a);
        r2 = -b - sqrt(d) / (2 * a);
        printf("The roots are real: %.1f %.1f\n", r1, r2);
    }
    else if (d == 0)
    {
        r1 = -b / (2 * a);
        r2 = -b / (2 * a);
        printf("The roots are equal: %.1f %.1f\n", r1, r2);
    }
    else
        printf("Roots are imaginary.\n");
    return 0;
}