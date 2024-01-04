#include <stdio.h>

void printBits(int n)
{
    int k, i;
    if (n < -127)
    {
        printf("Underflow\n");
        return;
    }
    else if (n > 127)
    {
        printf("Overflow\n");
        return;
    }
    if (n < 0)
        k = -1 * n;
    else
        k = n;
    char bits[8];
    for (i = 0; i < 8; i++)
    {
        bits[i] = (k >> i) & 1;
    }
    if (n < 0)
        bits[7] = 1;
    for (i = 7; i >= 0; i--)
        printf("%d", bits[i]);
    printf("\n");
}

int main()
{
    int n, k, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    printBits(n);
    return 0;
}
