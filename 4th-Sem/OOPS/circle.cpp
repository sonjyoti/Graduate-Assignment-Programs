/*3. Define a class circle to represent circles. Add a data member radius to store the radius of a
circle. Write member functions area() and perimeter() to compute the area and perimeter of a
circle.
*/

#include <iostream>

using namespace std;

class Circle
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    Circle()
    {
        cout << "Input radius: ";
        cin >> radius;
    }

    float area()
    {
        return (float)3.14 * radius * radius;
    }

    float perimeter()
    {
        return (float)2 * 3.14 * radius;
    }
};

int main()
{
    Circle c(4);
    cout << "Area of the circle: " << c.area() << "cm\u00B2" << endl;
    cout << "Circumference of the circle: " << c.perimeter() << "cm" << endl;
    return 0;
}