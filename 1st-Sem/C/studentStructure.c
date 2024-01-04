#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollNo;
    char name[30];
    int total;
};

int main()
{
    struct student *x;
    int n, i;
    printf("Input n: ");
    scanf("%d", &n);
    x = (struct student *)malloc(n * (sizeof(struct student *)));
    for (i = 0; i < n; i++)
    {
        printf("\nRoll No : ");
        scanf("%d", &x[i].rollNo);
        printf("Name: ");
        scanf("%s", x[i].name);
        printf("Total: ");
        scanf("%d", &x[i].total);
    }
    printf("\nStudents with a total of above 75 marks are: \n");

    for (i = 0; i < n; i++)
    {
        if (x[i].total >= 75)
        {
            printf("\nRoll No :%d\n", x[i].rollNo);
            printf("Name: %s\n", x[i].name);
            printf("Total: %d\n", x[i].total);
        }
    }
    return 0;
}
