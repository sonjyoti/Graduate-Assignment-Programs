/*4. Define a class complex with two data members real and imag to represent real and imaginary
parts of a complex number. Write member functions
rPart() : to return the real part of a complex number
iPart() : to return the imaginary part of a complex number
add() : to add two complex numbers.
mul() : to multiply two complex numbers.
Write constructors with zero, one and two arguments to initialize objects. (This is an example of
polymorphism.)
*/

#include <iostream>

using namespace std;

class Complex
{
private:
    float img, real;
    void rPart()
    {
        cout << "Input the real part: ";
        cin >> real;
    }
    void iPart()
    {
        cout << "Input the imaginary part: ";
        cin >> img;
    }
    static void displayNumber(Complex a)
    {
        cout << "\nThe complex number is: ";
        if (a.img >= 0.0)
            cout << a.real << "+" << a.img << "i" << endl;
        else
            cout << a.real << a.img << "i" << endl;
    }

public:
    Complex()
    {
        rPart();
        iPart();
        displayNumber();
    }
    Complex(float ar)
    {
        img = real = ar;
        displayNumber();
    }
    Complex(float r, float i)
    {
        real = r;
        img = i;
        displayNumber();
    }
    static void add(Complex a, Complex b)
    {
        cout << "\nAdding the complex numbers: ";
        a.img += b.img;
        a.real += b.real;
        displayNumber(a);
    }
    static void multiplyComplex(Complex a, Complex b)
    {
        cout << "\nMultiplying the complex numbers: ";
        float mulTerm1, mulTerm2, mulTerm3;
        mulTerm1 = a.real * b.real;
        mulTerm2 = (a.real * b.img) + (a.img * b.real);
        mulTerm3 = a.img * b.img * -1;
        mulTerm1 += mulTerm3;

        if (mulTerm2 >= 0.0)
            cout << mulTerm1 << "+" << mulTerm2 << "i" << endl;
        else
            cout << mulTerm1 << mulTerm2 << "i" << endl;
    }
    void displayNumber()
    {
        cout << "The complex number is: ";
        if (img >= 0.0)
            cout << real << "+" << img << "i" << endl;
        else
            cout << real << img << "i" << endl;
    }
};

int main()
{
    Complex a(3, -2), b(4, 5);
    Complex::add(a, b);
    Complex::multiplyComplex(a, b);
    return 0;
}