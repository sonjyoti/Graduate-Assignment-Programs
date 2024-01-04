/*33. Write a program to swap two numbers using function (pass the pointers).*/

#include <stdio.h>

void swap(int *n1, int *n2)
{
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
}

int main()
{
    int n1, n2;
    printf("Enter the numbers: ");
    scanf("%d %d", &n1, &n2);
    printf("Values of n1 and n2 before swapping.\nn1=%d\nn2=%d\n", n1, n2);
    swap(&n1, &n2);
    printf("Values of n1 and n2 before swapping.\nn1=%d\nn2=%d\n", n1, n2);
    return 0;
}