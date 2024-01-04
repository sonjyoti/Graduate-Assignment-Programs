
/*
8. Write a java program for a class teacher that contains two fields name and qualification.
Extend the class to department that contains data members deptNo and deptName.
An interface name as college contains one field name of the college. Using the above classes and interface get the appropriate information and display them.
**/
import java.util.Scanner;

interface College{
    void inputData();
    void showData();
}

class Dept {
    protected String deptName;
    int deptNo;
}

class Teacher extends Dept implements College{
    Teacher(){
        inputData();
    }
    Scanner sc = new Scanner(System.in);
    private String profName, qual, clgName;
     @Override
     public void inputData(){
        System.out.print("Input college name: ");
        clgName = sc.nextLine();
        System.out.print("Input dept name: ");
        deptName = sc.nextLine();
        System.out.print("Input dept no: ");
        deptNo = sc.nextInt();
        sc.nextLine();
        System.out.print("Input prof. name: ");
        profName = sc.nextLine();
        System.out.print("Input prof. qualification: ");
        qual = sc.nextLine();
     }
    public void showData(){
        System.out.println("\nCollege name: "+clgName+"\nDept name: "+deptName+"\nDept no.: "+deptNo+"\nProf. name: "+profName+"\nProf. qualification: "+qual);
    }
}

public class Question8 extends Teacher{
    Question8(){
        super();
    }
}
