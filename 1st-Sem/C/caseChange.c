#include <stdio.h>
#include <stdlib.h>

char *upper(char a[])
{
    int i;
    for (i = 0; a[i] != 0; i++)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] = a[i] - 32;
    return a;
}

char *lower(char a[])
{
    int i;
    for (i = 0; a[i] != 0; i++)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] + 32;
    return a;
}

int main()
{
    int i;
    char c[] = "Song";
    printf("In upper case: %s\n", upper(c));
    printf("In lower case: %s\n\n", lower(c));
    return 0;
}