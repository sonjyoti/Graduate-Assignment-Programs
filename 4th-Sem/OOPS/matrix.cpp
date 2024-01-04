/*6. Define a class to store matrices. Write suitable friend functions to add and multiply two
matrices.
*/

#include <iostream>

using namespace std;

class Matrix
{
private:
    int row, col;
    int **p;

public:
    Matrix()
    {
        cout << "Input row: ";
        cin >> row;
        cout << "Input col: ";
        cin >> col;
        p = (int **)malloc(row * sizeof(int));
        for (int i = 0; i < row; i++)
            p[i] = (int *)malloc(col * sizeof(int));
        input();
    }

    Matrix(int r, int c)
    {
        row = r, col = c;
        p = (int **)malloc(row * sizeof(int));
        for (int i = 0; i < row; i++)
            p[i] = (int *)malloc(col * sizeof(int));
    }

    void input()
    {
        cout << "Input the elements: ";
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> p[i][j];
    }

    void add(Matrix a)
    {
        if (a.row != row || a.col != col)
        {
            cout << "!incompatible for addition\n";
            return;
        }
        for (int i = 0; i < a.row; i++)
            for (int j = 0; j < a.col; j++)
                p[i][j] += a.p[i][j];
    }

    void multiply(Matrix a)
    {
        if (a.row != col)
        {
            cout << "!incompatible for multiplication\n";
            return;
        }
        Matrix ans(row, a.col);
        for (int i = 0; i < ans.row; i++)
        {
            for (int j = 0; j < ans.col; j++)
            {
                ans.p[i][j] = 0;
                for (int k = 0; k < ans.col; k++)
                {
                    ans.p[i][j] += p[i][j] * a.p[i][k];
                }
            }
        }
        cout << "Multiplication of the matrices: \n";
        ans.display();
    }

    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix a;
    cout << "Matrix a:\n";
    a.display();
    Matrix b;
    cout << "Matrix b:\n";
    b.display();
    a.add(b);
    cout << "Matrix addition: \n";
    a.display();
    a.multiply(b);
    return 0;
}