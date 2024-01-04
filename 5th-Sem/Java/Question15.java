
/*
15. Write a java program to create a class, library that contains the field, bookNo, Extend the
class, library to book having fields author and title, and then extend the class, book to issue. Create
an interface, language that contains a field, lang. Implement the interface for the class, book. Use
appropriate methods for the classes and interface
**/

import java.util.Scanner;

interface Language{
    String lang = "English";
}

class Library{
    protected static int bookNo = 1000;
}

class Book extends Library implements Language{
    protected String author, title;
}

class Issue extends Book{
    Scanner input = new Scanner(System.in);
    private String issueDate;
    public void inputBookDetails(){
        bookNo++;
        System.out.print("Required Book Title: ");
        title = input.nextLine();
        System.out.print("Required Book Author: ");
        author = input.nextLine();
        System.out.print("Issue date: ");
        issueDate = input.nextLine();
    }
    public void showData(){
        System.out.println("\nBook no: "+bookNo);
        System.out.println("Book title: "+title);
        System.out.println("Book author: "+author);
        System.out.println("Book Language: "+lang);
        System.out.println("Issued date: "+issueDate);
    }
}

public class Question15 {
    public static void main(String[] args) {
        Issue lib = new Issue();
        lib.inputBookDetails();
        lib.showData();
    }
}
