#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int **arr;
    int r, c;
};

typedef struct matrix Matrix;

void input(Matrix *a)
{
    int i, j;
    printf("Enter the no. of rows: ");
    scanf("%d", &a->r);
    printf("Enter the no. of cols: ");
    scanf("%d", &a->c);
    a->arr = (int **)malloc(a->r * (sizeof(int *)));
    printf("Input elements for the %d X %d matrix: \n", a->r, a->c);
    for (i = 0; i < a->r; i++)
        a->arr[i] = (int *)malloc(a->c * (sizeof(int)));
    for (i = 0; i < a->r; i++)
        for (j = 0; j < a->c; j++)
            scanf("%d", &a->arr[i][j]);
}

void output(Matrix *a)
{
    int i, j, rSum, *arr;
    arr = (void *)malloc(a->c * (sizeof(int)));
    printf("Output\n\n");
    for (i = 0; i < a->r; i++)
    {
        rSum = 0;
        for (j = 0; j < a->c; j++)
        {
            printf("%d ", a->arr[i][j]);
            rSum += a->arr[i][j];
        }
        printf("\tRow Sum = %d\n", rSum);
    }

    for (j = 0; j < a->c; j++)
        arr[j] = 0;

    for (i = 0; i < a->r; i++)
    {
        for (j = 0; j < a->c; j++)
        {
            arr[j] += a->arr[i][j];
        }
    }

    for (j = 0; j < a->c; j++)
        printf("\n%d Column Sum = %d\n", j, arr[j]);
}

int main()
{
    Matrix a;
    input(&a);
    output(&a);
    return 0;
}