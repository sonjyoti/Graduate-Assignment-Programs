
/*
10. Write a program to create a class shape with properties length and breadth. Extend the class
to rectangle and square, and find the area of the rectangle and the square. Use input() method to take
input using keyboard.
**/

import java.util.Scanner;

abstract class Shape{
    float length, breadth;
    Scanner input = new Scanner(System.in);
    abstract void input();
}

class Rectangle extends Shape{
    Rectangle(){
        input();
    }
    @Override
    void input() {
        System.out.println("\nInput rectangle dimensions: ");
        System.out.print("Length: ");
        length = input.nextFloat();
        System.out.print("Breadth: ");
        breadth = input.nextFloat();
    }
    public void showData(){
        System.out.println("\nRectangle length: "+length+"\nRectangle breadth: "+breadth);
        System.out.printf("Area: %.2f\n", length*breadth);
    }
}

class Square extends Shape{
    Square(){
        input();
    }
    @Override
    void input() {
        System.out.println("\nInput Square dimensions: ");
        System.out.print("Length: ");
        length = input.nextFloat();
    }
    public void showData(){
        System.out.println("\nSquare length: "+length);
        System.out.printf("Area: %.2f\n", length*length);
    }
}

public class Question10 {
    public static void main(String[] args) {
        Rectangle rec = new Rectangle();
        rec.showData();

        Square sqr = new Square();
        sqr.showData();
    }
}
