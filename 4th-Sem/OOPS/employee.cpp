/*2. Define a structure employee with the following specifications.
empNo : integer
eName : 20 characters
basic, hra, da : float
calculate() : a function to compute net pay as basic+hra+da with float return type.
getData() : a function to read values for empNo, eName, basic, hra, da.
dispData() : a function to display all the data on the screen
Write a main program to test the program.
*/

#include <iostream>

using namespace std;

struct Employee
{
    int empNo;
    char eName[20];
    float basic, hra, da;
};

typedef struct Employee Emp;

float calculate(Emp a)
{
    return (float)a.basic + a.hra + a.da;
}

void getData(Emp *a)
{
    cout << "Input Employee No.: ";
    cin >> a->empNo;
    cout << "Input Employee Name: ";
    cin >> a->eName;
    cout << "Input basic pay: $";
    cin >> a->basic;
    cout << "Input HRA: $";
    cin >> a->hra;
    cout << "Input DA.: $";
    cin >> a->da;
}

void displayData(Emp e)
{
    cout << "\n\nEmployee No.: " << e.empNo << endl;
    cout << "Employee Name: " << e.eName << endl;
    cout << "Basic pay: $" << e.basic << endl;
    cout << "HRA: $" << e.hra << endl;
    cout << "DA.: $" << e.da << endl;
    cout << "Net salary of the Employee: $" << calculate(e) << endl;
}

int main()
{
    Emp e;
    getData(&e);
    displayData(e);
    return 0;
}