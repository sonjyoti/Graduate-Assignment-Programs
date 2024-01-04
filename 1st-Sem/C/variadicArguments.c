// Write a program using variadic arguments to read n numbers and return the maximum from them

#include <stdio.h>
#include <stdarg.h>

int max(int n, ...)
{
    int num, i, t;
    va_list x;
    va_start(x, n);

    for (i = 1; i <= n; i++)
    {
        t = va_arg(x, int);
        if (i == 1)
            num = t;
        else
            num = t > num ? t : num;
    }
    va_end(x);
    return num;
}

int main()
{
    printf("%d\n", max(5, 1, 7, 9, 8, 4));
    printf("%d\n", max(3, 6, 4, 23));
    return 0;
}
