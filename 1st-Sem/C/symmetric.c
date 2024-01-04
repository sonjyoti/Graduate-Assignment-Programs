#include <stdio.h>

struct matrix
{
    int arr[10][10];
    int r, c;
};

typedef struct matrix Matrix;

void inputMatrix(Matrix *x)
{
    int i, j;
    printf("Input the values of rows and columns: ");
    scanf("%d %d", &x->r, &x->c);

    printf("Input the elements: ");
    for (i = 0; i < x->r; i++)
        for (j = 0; j < x->c; j++)
            scanf("%d", &x->arr[i][j]);
}

void printMatrix(Matrix x)
{
    int i, j;
    for (i = 0; i < x.r; i++)
    {
        for (j = 0; j < x.c; j++)
        {
            printf("%d ", x.arr[i][j]);
        }
        printf("\n");
    }
}

int isSymmetric(Matrix x)
{
    int i, j;
    if (x.r == x.c)
    {
        for (i = 0; i < x.r; i++)
            for (j = 0; j < x.c; j++)
                if (x.arr[i][j] != x.arr[j][i])
                    return 0;
        return 1;
    }
    else
        return 0;
}

int main()
{
    Matrix a;
    printf("Enter matrix details: \n");
    inputMatrix(&a);
    printMatrix(a);
    if (isSymmetric(a))
        printf("Matrix entered is symmetric.\n");
    else
        printf("Matrix entered is non-symmetric.\n");
    return 0;
}