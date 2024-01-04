#include <stdio.h>

int fact(int n)
{
    int f = 1;
    while (n != 0)
    {
        f = f * n;
        n--;
    }
    return f;
}
int npr(int n, int r)
{
    return (fact(n) / fact(n - r));
}
int ncr(int n, int r)
{
    return (fact(n) / (fact(n - r) * fact(r)));
}
int main()
{
    int n, r;
    printf("Input value of n and r: ");
    scanf("%d %d", &n, &r);
    printf("%dP%d is %d\n", n, r, npr(n, r));
    printf("%dC%d is %d\n", n, r, ncr(n, r));
    return 0;
}
