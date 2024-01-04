#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int number;
    char name[30];
    float pay;
    struct date
    {
        int dd, mm, yy
    } doj;
};

void increasePay(struct employee *x)
{
    if (x->pay <= 3000)
        x->pay = x->pay + (0.2 * x->pay);
    else if (x->pay <= 6000)
        x->pay = x->pay + (0.15 * x->pay);
}

void input(struct employee *x)
{
    printf("Input Employee no: ");
    scanf("%d", &x->number);
    printf("Input Employee name: ");
    scanf("%s", x->name);
    printf("Input Pay: ");
    scanf("%f", &x->pay);
    printf("Input DOJ: ");
    scanf("%2d/%2d/%4d", &x->doj.dd, &x->doj.mm, &x->doj.yy);
}

void output(struct employee x)
{
    printf("\nEmployee no.: %d\n", x.number);
    printf("Employee name: %s\n", x.name);
    printf("Employee salary: %.2f\n", x.pay);
    printf("Employee DOJ: %2d/%2d/%4d\n", x.doj.dd, x.doj.mm, x.doj.yy);
}

int main()
{
    struct employee *a;
    int n, i;
    printf("Enter the number of Employees: ");
    scanf("%d", &n);

    printf("Input Employees' Details: \n");
    a = (struct employee *)malloc(n * sizeof(struct employee));
    for (i = 0; i < n; i++)
    {
        input(&a[i]);
        increasePay(&a[i]);
    }

    printf("\n\n");

    printf("Results: \n");
    for (i = 0; i < n; i++)
        output(a[i]);
    return 0;
}