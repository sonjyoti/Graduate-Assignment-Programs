#include <stdio.h>

int main()
{
    int n, x;
    float y;
    printf("Enter the value of x and n: ");
    scanf("%d %d", &x, &n);
    switch (n)
    {
    case 1:
        y = n + x;
        break;
    case 2:
        y = 1 + (float)x / n;
        break;
    case 3:
        y = n + (3 * x);
        break;
    default:
        y = 1 + (n * x);
        break;
    }
    printf("The value of y is %.1f\n", y);
    return 0;
}