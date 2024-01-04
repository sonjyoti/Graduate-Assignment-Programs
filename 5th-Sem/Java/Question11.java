
/*
11. Write a program to create an array of employee name and salary related to the employee.
If the salary is greater than Rs.10,000 raise an exception “Salary is greater than Rs.10,000”,
otherwise display the required information.
**/

import java.util.Scanner;

class Employees{
    Scanner input = new Scanner(System.in);
    String name;
    static int id = 1001;
    int empID = 0;
    float salary;
    Employees(){
        inputDetails();
    }
    private void inputDetails(){
        empID = id;
        id++;
        System.out.print("\nInput Employee Name: ");
        name = input.nextLine();
        System.out.print("Input Salary: ");
        salary = input.nextFloat();
        input.nextLine();
    }
    public void showDetails(){
        System.out.println("\nEmployee id: " + empID);
        System.out.println("Name: " + name);
        try {
            if (salary <= 10000)
                System.out.printf("Salary: %.2f\n", salary);
            else
                throw new RuntimeException();
        } catch (Exception e) {
            System.out.println("Salary is greater than 10,000");
        }
    }
}

public class Question11 {
    public static void main(String[] args) {
        Employees[] empArray = new Employees[3];
        for (int i = 0; i < 3; i++){
            empArray[i] = new Employees();
        }
        for (int i = 0; i < 3; i++) {
            empArray[i].showDetails();
        }
    }
}
