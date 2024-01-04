
/*
14. Write a java program to input a string and converts the string to lower case and upper case.
Also find the substring from 5 to end, from 0 to 5, from 3 to 7, and from 5 to 5.
**/

import java.util.Scanner;

public class Question14 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Input the string: ");
        String str = input.nextLine();
        System.out.println("lowercase: "+str.toLowerCase());
        System.out.println("UPPERCASE: "+str.toUpperCase());
        System.out.println("Substring from 5 to end: "+str.substring(5));
        System.out.println("Substring from 0 to 5: "+str.substring(0, 5));
        System.out.println("Substring from 3 to 7: "+str.substring(3, 7));
        System.out.println("Substring from 5 to 5: "+str.substring(5, 5));
    }
}
