/*5. Define a class string with the following data members char *p; int size; and write member
functions to do the following (without using library function) and using dynamic memory
allocation.
• Length of the string
• Compare two strings
• Copy
 one string to another
• Reverse the string
Write suitable constructors and destructors. Also write a copy constructor for the class.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class String
{
private:
    char *p;
    int size;

public:
    String()
    {
        cout << "Input the size of the string: ";
        cin >> size;
        p = (char *)malloc(size);
        cout << "Input string: ";
        cin >> p;
    }

    String(int s)
    {
        size = s;
        p = (char *)malloc(size);
        cout << "Input string: ";
        cin >> p;
    }

    String(const String &str)
    {
        cout << "Copy constructor!\n";
        p = str.p;
    }

    int strlen()
    {
        int i = 0;
        while (p[i] != '\0')
        {
            i++;
        }
        return i;
    }

    bool comStr(String str)
    {
        if (str.strlen() == strlen())
        {
            for (int i = 0; i < str.strlen(); i++)
            {
                if (str.p[i] != p[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    void strCpy(String str)
    {
        if (strlen() < str.strlen())
            cout << "!incompatible length\n";
        for (int i = 0; i < str.strlen(); i++)
        {
            p = str.p;
        }
    }

    void strRev()
    {
        int f = 0, s = strlen() - 1;
        while (f < s)
        {
            char c = p[f];
            p[f] = p[s];
            p[s] = c;
            f++;
            s--;
        }
    }

    void display()
    {
        int i = 0;
        while (p[i] != '\0')
            cout << p[i++];
        cout << endl;
    }

    ~String()
    {
        cout << "Object destroyed!\n";
    }
};

int main()
{
    String str1, str2(10);
    cout << "Length of string(str1): " << str1.strlen() << endl;
    if (str1.comStr(str2))
        cout << "\nComparing strings(str1, str2): True\n";
    else
        cout << "\nComparing strings(str1, str2): False\n";
    String str3 = str2;
    cout << "\nString(str3): ";
    str3.display();
    str2.strRev();
    cout << "\nReversed String(str3): ";
    str2.display();
    str1.strCpy(str2);
    cout << "Copied string(str1, str2): ";
    str1.display();
}
