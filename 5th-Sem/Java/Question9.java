/*
9. Design three classes person, employee and student using the concept of inheritance.
Each class should have a constructor of its own properties as name, age, gender and common method showData().
**/

import java.util.Scanner;

class Person{
    Scanner input = new Scanner(System.in);
    String name;
    int age;
    String gender;
}

class Employee extends Person{
    static int empId = 1001;
    float salary;
    Employee(){
        inputData();
    }
    private void inputData(){
        empId++;
        System.out.println("Input Employee Details-- ");
        System.out.print("Name: ");
        name = input.nextLine();
        System.out.print("Age: ");
        age = input.nextInt();
        input.nextLine();
        System.out.print("Gender: ");
        gender = input.nextLine();
        System.out.print("Salary: ");
        salary = input.nextFloat();
    }
    public void showData(){
        System.out.println("Employee id: "+empId);
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
        System.out.println("Gender: "+gender);
        System.out.printf("Salary: %.2f\n", salary);
    }
}

class Student extends Person{
    static int roll_no = 1101;
    String course;
    Student(){
        inputData();
    }
    private void inputData(){
        roll_no++;
        System.out.println("Input Student Details-- ");
        System.out.print("Name: ");
        name = input.nextLine();
        System.out.print("Age: ");
        age = input.nextInt();
        input.nextLine();
        System.out.print("Gender: ");
        gender = input.nextLine();
        System.out.print("Course: ");
        course = input.nextLine();
    }
    public void showData(){
        System.out.println("Student roll no. : "+roll_no);
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
        System.out.println("Gender: "+gender);
        System.out.println("Course: "+course);
    }
}

public class Question9 {
    public static void main(String[] args) {
        Student sonjyoti = new Student();
        sonjyoti.showData();

        Student sarma= new Student();
        sarma.showData();

        Employee rahul = new Employee();
        rahul.showData();

        Employee shilpi = new Employee();
        shilpi.showData();
    }
}
