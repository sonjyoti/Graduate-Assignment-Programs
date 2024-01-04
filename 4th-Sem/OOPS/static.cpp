/*7. Write a class based program implementing static members.
 */

#include <iostream>

using namespace std;

class Static
{
private:
    static int n;

public:
    Static()
    {
        cout << "A static class example.\n";
    }
    static void increment()
    {
        n++;
    }
    static void display()
    {
        cout << "Value of n: " << n << endl;
    }
};

int Static::n;

int main()
{
    Static s;
    Static::increment();
    Static::display();
    return 0;
}