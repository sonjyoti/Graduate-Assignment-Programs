#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    char ch;
    int n = 0;

    if ((fp = fopen("vowel.txt", "r")) == NULL)
    {
        printf("File unable to open\n");
        exit(0);
    }
    do
    {
        ch = getc(fp);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            n++;
    } while (ch != EOF);
    fclose(fp);

    printf("Number of vowels in the file is: %d\n", n);
    return 0;
}