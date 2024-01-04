#include <stdio.h>
#include <stdarg.h>

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

Matrix addMatrix(int n, ...)
{
    int i, j, k, r, c;
    Matrix add, t;
    va_list x;
    va_start(x, n);
    for (k = 1; k <= n; k++)
    {
        t = va_arg(x, Matrix);
        if (k == 1)
        {
            r = t.r;
            c = t.c;
            add.r = r;
            add.c = c;
            for (i = 0; i < r; i++)
                for (j = 0; j < c; j++)
                    add.arr[i][j] = t.arr[i][j];
        }
        else
        {
            if (add.r == t.r && add.c == t.c)
            {
                for (i = 0; i < t.r; i++)
                    for (j = 0; j < t.c; j++)
                        add.arr[i][j] += t.arr[i][j];
            }
            else
            {
                add.r = add.c = 0;
                return add;
            }
        }
    }
    va_end(x);
    return add;
}

int main()
{
    Matrix a, b, c, d, sum;
    int n = 4, i;

    printf("Input First Matrix: \n");
    inputMatrix(&a);

    printf("Output Matrix: \n");
    printMatrix(a);

    printf("Input Second Matrix: \n");
    inputMatrix(&b);

    printf("Output Matrix: \n");
    printMatrix(b);

    printf("Input Third Matrix: \n");
    inputMatrix(&c);

    printf("Output Matrix: \n");
    printMatrix(c);

    printf("Input Fourth Matrix: \n");
    inputMatrix(&d);

    printf("Output Matrix: \n");
    printMatrix(d);

    printf("Sum Matrix: \n");
    sum = addMatrix(n, a, b, c, d);
    printMatrix(sum);

    return 0;
}
