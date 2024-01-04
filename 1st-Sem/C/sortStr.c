#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(char *str[100], int n)
{
    int i, j, loc;
    char temp[100];
    for (i = 0; i < n; i++)
    {
        loc = i;
        for (j = i + 1; j < n; j++)
            if ((strcmp(str[loc], str[j]) > 0))
                loc = j;

        strcpy(temp, str[loc]);
        strcpy(str[loc], str[i]);
        strcpy(str[i], temp);
    }
}
int main()
{
    char *str[100];
    int i, n;
    printf("Input n: ");
    scanf("%d", &n);
    printf("Input the strings: \n");
    for (i = 0; i < n; i++)
    {
        str[i] = (char *)malloc(100);
        scanf("%s", str[i]);
    }

    sort(str, n);

    printf("Given strings in ascending order: \n");
    for (i = 0; i < n; i++)
        printf("%s\n", str[i]);
}
