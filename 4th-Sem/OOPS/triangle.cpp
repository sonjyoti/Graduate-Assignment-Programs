/* 1.
 Define a class named triangle to represent a triangle using the lengths of the three sides.
Write a constructor to initialize objects of this class, given the lengths of the sides. Also write
member functions to check
(a) if a triangle is isosceles
(b) if a triangle is equilateral
Write a main function to test your functions.
*/

#include <iostream>

using namespace std;

class Triangle
{
private:
    int side1, side2, side3;

public:
    Triangle(int s1, int s2, int s3)
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
    Triangle()
    {
        side1 = 1;
        side2 = 1;
        side3 = 1;
    }
    bool checkEquilateral()
    {
        if ((side1 == side2) && (side1 == side3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkIsosceles()
    {
        if (((side1 == side2) && (side1 != side3) && (side2 != side3)) || ((side1 == side3) && (side1 != side2) && (side2 != side3)) || (side2 == side3) && (side1 != side2) && (side1 != side3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Triangle t(3, 3, 3);
    if (t.checkEquilateral())
    {
        cout << "Triangle is an equilateral triangle." << endl;
    }
    if (t.checkIsosceles())
    {
        cout << "Triangle is an isosceles triangle." << endl;
    }
}
