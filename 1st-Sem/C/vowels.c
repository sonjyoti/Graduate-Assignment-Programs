#include <stdio.h>
#include <string.h>

int vowels(char ch[10])
{
    int i, ans = 0;
    for (i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U')
            ans++;
    }
    return ans;
}

int main()
{
    char ch[10];
    printf("Enter the string: ");
    scanf("%s", ch);
    printf("The number of vowels in %s is %d\n", ch, vowels(ch));
    return 0;
}