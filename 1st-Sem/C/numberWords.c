#include <stdio.h>

void words(int n)
{
    switch (n)
    {
    case 0:
        printf("Zero ");
        break;
    case 1:
        printf("One ");
        break;
    case 2:
        printf("Two ");
        break;
    case 3:
        printf("Three ");
        break;
    case 4:
        printf("Four ");
        break;
    case 5:
        printf("Five ");
        break;
    case 6:
        printf("Six ");
        break;
    case 7:
        printf("Seven\n");
        break;
    case 8:
        printf("Eight ");
        break;
    case 9:
        printf("Nine ");
        break;
    default:
        break;
    }
}

int main()
{
    int n, i = 1, t;
    printf("Enter the no. : ");
    scanf("%d", &n);
    
    
    if (n < 10) // jdi 1 digit r number hoi direct mne iyar porai words function tu call hobo
    {
        words(n);
        return 0; //then iyat return hoi jbo program terminated
        printf("\n");
    }
    while (i < n) // jdi 2 or more digit hoi. aitu loop a kimn digit hoi xeitu uliai lobo
        i = i * 10; 

    i = i / 10;
    while (i > 0) // then aitu loop a 1ta 1ta number "words" function tut pothabo. jot words bur print hobo
    {
        t = n / i;
        words(t);
        n = n % i;
        i = i / 10;
    }
    printf("\n");
    return 0;
}
