/*8. Define a class student with the following specification:
    rollNo : integer
    sname : 20 characters
Derive two classes artSt and scSt. The class artSt will represent students belonging to arts stream
and the class scSt will represent students belonging to science stream. The artSt class will have
additional data members ph, hs, en and as to store marks obtained by a student in three subjects
Philosophy, History, English and Assamese. The class scSt will have additional data members
ph, ch, ma and en to store marks obtained in Physics, Chemistry, Mathematics and English.
Write the following member functions in the classes artSt and scSt
    ctotal() : a function to calculate the total marks obtained by a student
    takeData() : function to accept values of the data members
    showData() : function to display the marks sheet of a student .
*/

#include <iostream>

using namespace std;

class Student
{
public:
    int rollNo;
    char sName[20];
    Student()
    {
        cout << "Input student roll no.: ";
        cin >> rollNo;
        cout << "Input student name: ";
        cin >> sName;
    }
};

class ArtSt : private Student
{
private:
    int ph, hs, en, as;

public:
    ArtSt()
    {
        cout << "Arts Student.\n";
    }
    int cTotal()
    {
        return ph + hs + en + as;
    }

    void takeData()
    {
        cout << "Input marks for Philosophy: ";
        cin >> ph;
        cout << "Input marks for History: ";
        cin >> hs;
        cout << "Input marks for English: ";
        cin >> en;
        cout << "Input marks for Assamese: ";
        cin >> as;
    }

    void showData()
    {
        cout << "\n\n";
        cout << "Student stream: Arts\n";
        cout << "Student roll no.: " << rollNo << endl;
        cout << "Student name: " << sName << endl;
        cout << "Philosophy: " << ph << endl;
        cout << "History: " << hs << endl;
        cout << "English:" << en << endl;
        cout << "Assamese: " << as << endl;
        cout << "Total: " << cTotal() << endl;
        cout << "\n";
    }
};

class ScSt : private Student
{
private:
    int ph, ch, ma, en;

public:
    ScSt()
    {
        cout << "Science Student.\n";
    }
    int cTotal()
    {
        return ph + ch + ma + en;
    }

    void takeData()
    {
        cout << "Input marks for Physics: ";
        cin >> ph;
        cout << "Input marks for Chemistry: ";
        cin >> ch;
        cout << "Input marks for Mathematics: ";
        cin >> ma;
        cout << "Input marks for English: ";
        cin >> en;
    }

    void showData()
    {
        cout << "\n\n";
        cout << "Student stream: Science\n";
        cout << "Student roll no.: " << rollNo << endl;
        cout << "Student name: " << sName << endl;
        cout << "Physics: " << ph << endl;
        cout << "Chemistry: " << ch << endl;
        cout << "Mathematics:" << ma << endl;
        cout << "English: " << en << endl;
        cout << "Total: " << cTotal() << endl;
        cout << "\n";
    }
};

int main()
{
    ScSt std1;
    std1.takeData();
    std1.showData();
    ArtSt std2;
    std2.takeData();
    std2.showData();
    return 0;
}