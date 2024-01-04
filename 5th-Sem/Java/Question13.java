
/*
13. Write a program to create three StringBuffers. The first one takes no parameters, second one
takes an integer value and the third one sets an initial value “Java”. Find the content, length and
capacity for the StringBuffers
**/

public class Question13 {
    public static void main(String[] args) {
        // Creating the first StringBuffer with no parameters
        StringBuffer sb1 = new StringBuffer();

        // Creating the second StringBuffer with an integer value (12345 in this case)
        int num = 12345;
        StringBuffer sb2 = new StringBuffer(String.valueOf(num));

        // Creating the third StringBuffer with an initial value "Java"
        StringBuffer sb3 = new StringBuffer("Java");

        // Printing the content, length, and capacity of the StringBuffers
        System.out.println("StringBuffer 1 - Content: " + sb1 +
                " Length: " + sb1.length() +
                " Capacity: " + sb1.capacity());

        System.out.println("StringBuffer 2 - Content: " + sb2 +
                " Length: " + sb2.length() +
                " Capacity: " + sb2.capacity());

        System.out.println("StringBuffer 3 - Content: " + sb3 +
                " Length: " + sb3.length() +
                " Capacity: " + sb3.capacity());
    }
}
