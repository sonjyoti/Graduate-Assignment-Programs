#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int arr[10][10];
    int r, c;
};

typedef struct matrix Matrix;

void inputMatrix(Matrix *x)
{
    int i, j;
    printf("Enter the no. of rows and columns required: ");
    scanf("%d %d", &x->r, &x->c);

    printf("Enter the elements: ");
    for (i = 0; i < x->r; i++)
    {
        for (j = 0; j < x->c; j++)
        {
            scanf("%d", &x->arr[i][j]);
        }
    }
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

Matrix isUpper(Matrix x)
{
    int i, j;
    if (x.r == x.c)
    {
        for (i = 0; i < x.r; i++)
            for (j = 0; j < x.c; j++)
                if (i <= j && x.arr[i][j] == 0 || (i > j && x.arr[i][j] != 0))
                    x.arr[i][j] = 0;
    }
    else
    {
        printf("Operation cannot be performed.\n");
        exit(1);
    }
    return x;
}

Matrix isLower(Matrix x)
{
    int i, j;
    if (x.r == x.c)
    {
        for (i = 0; i < x.r; i++)
            for (j = 0; j < x.c; j++)
                if (i >= j && x.arr[i][j] == 0 || (i < j && x.arr[i][j] != 0))
                    x.arr[i][j] = 0;
    }
    else
    {
        printf("Operation cannot be performed.\n");
        exit(1);
    }
    return x;
}

int main()
{
    Matrix a, up, low;
    printf("Input the details for the Matrix: \n");
    inputMatrix(&a);
    up = isUpper(a);
    printf("The upper triangle of the matrix: \n");
    printMatrix(up);
    low = isLower(a);
    printf("The lower triangle of the matrix: \n");
    printMatrix(low);
    return 0;
}
