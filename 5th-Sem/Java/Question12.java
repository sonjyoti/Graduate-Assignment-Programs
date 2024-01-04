
/*
12. Write a program to find the square root of a number. If the input value is negative, raise a
user defined exception “The number is a negative number”.
**/

import java.util.Scanner;

public class Question12 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Input the number: ");
        int num = input.nextInt();
        try{
            if (num >= 0)
                System.out.printf("Square root of %d is: %.2f\n", num, Math.sqrt(num));
            else
                throw new RuntimeException();
        }
        catch (Exception e){
            System.out.println("The number is a negative number");
        }
    }
}
