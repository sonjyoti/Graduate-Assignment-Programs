#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int arr[10][10];
    int r, c;
};

typedef struct matrix Matrix;

void inputMatrix(Matrix *a)
{
    int i, j;
    printf("Input the value of rows and columns: ");
    scanf("%d %d", &a->r, &a->c);

    printf("Input the values of the matrix: ");
    for (i = 0; i < a->r; i++)
    {
        for (j = 0; j < a->c; j++)
        {
            scanf("%d", &a->arr[i][j]);
        }
    }
}

void printMatrix(Matrix a)
{
    int i, j;
    for (i = 0; i < a.r; i++)
    {
        for (j = 0; j < a.c; j++)
        {
            printf("%d ", a.arr[i][j]);
        }
        printf("\n");
    }
}

Matrix multiplyMatrix(Matrix a, Matrix b)
{
    Matrix ans;
    int i, j, k;
    ans.r = a.r;
    ans.c = b.c;
    if (a.c != b.r)
    {
        printf("Operation cannot be performed.\n");
        exit(1);
    }
    for (i = 0; i < a.r; i++)
    {
        for (j = 0; j < b.c; j++)
        {
            ans.arr[i][j] = 0;
            for (k = 0; k < b.c; k++)
            {
                ans.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }
    return ans;
}

int main()
{
    Matrix a, b, ans;
    printf("For the first matrix: \n");
    inputMatrix(&a);
    printMatrix(a);
    printf("For the second matrix: \n");
    inputMatrix(&b);
    printMatrix(b);
    ans = multiplyMatrix(a, b);
    printf("Multiplication of the two matrix is: \n");
    printMatrix(ans);
    return 0;
}