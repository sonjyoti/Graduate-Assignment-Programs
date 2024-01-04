#include <stdio.h>
#include <stdlib.h>

void concatenate(char a[], char b[], char c[], int l)
{
    int i, j;

    for (i = 0; a[i] != 0; i++)
        c[i] = a[i];
    for (j = 0; b[j]; i++, j++)
        c[i] = b[j];
}

int main()
{
    int l1, l2;
    char a[] = "Hello,";
    char b[] = " World";
    char *c;

    for (l1 = l2 = 0; a[l1] != 0 && b[l2] != 0; l1++, l2++)
        ;

    c = (char *)malloc(l1 * sizeof(char));

    concatenate(a, b, c, l1);

    printf("Concatenated string: %s\n", c);

    return 0;
}