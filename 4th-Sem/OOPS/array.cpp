/*9.Write a class template for storing an array of elements. Overload the << and >> operators.
Write a member function to sort the array in descending order.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Array
{
private:
    int *p;
    int size;

public:
    Array()
    {
        cout << "Input size: ";
        cin >> size;
        p = (int *)malloc(size * sizeof(int));
    }
    Array(int s)
    {
        size = s;
        p = (int *)malloc(size * sizeof(int));
    }

    void desc()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (p[i] < p[j])
                {
                    int tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
            }
        }
    }

    friend ostream &operator<<(ostream &out, const Array &arr);

    friend istream &operator>>(istream &in, Array &arr);
};

ostream &operator<<(ostream &out, const Array &arr)
{
    for (int i = 0; i < arr.size; i++)
        out << arr.p[i] << " ";
    out << "\n";
    return out;
}

istream &operator>>(istream &in, Array &arr)
{
    cout << "Input elements: ";
    for (int i = 0; i < arr.size; i++)
        in >> arr.p[i];
    return in;
}

int main()
{
    Array arr;
    cin >> arr;
    cout << "Elements are: ";
    cout << arr;
    arr.desc();
    cout << "Descending order: ";
    cout << arr;
    return 0;
}