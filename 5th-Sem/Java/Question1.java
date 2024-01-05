
/*
1. Design a class to represent a bank account and include the following data members –
Data Members: name of the depositor, account number, type of a/c, balance amount in the a/c
Methods: to assign initial values, to deposit an amount, to withdraw an amount after checking  the
minimum balance (Rs.1000), to display the name of the depositor and balance.
**/

import java.util.Scanner;

class BankAcc{
    BankAcc(double amount) {
        accOpen(amount);
    }
    protected String accHolder;
    protected long accountNo;
    protected String accType;
    protected double accBalance;
    protected Scanner sc = new Scanner(System.in);
    protected void accOpen(double amount) {
        System.out.println("Greetings sir/madam!\nPlease wait...");
        System.out.print("Enter your name: ");
        accHolder = sc.nextLine();
        accountNo = (100001234 + (long) (Math.random() * ((100009999 - 100001234) + 1)));
        accType = "Savings";
        depositBal(amount);
        displayDetails();
    }
    protected void depositBal(double amount){
        accBalance += amount;
        System.out.println("$"+amount+" has been credited to your a/c XXXXX"+accountNo%10000+"\n");
    }
    protected boolean checkMinBal(){
        return accBalance >= 1000;
    }
    protected void withdraw(double amount){
        if (!checkMinBal()){
            System.out.println("Minimum amount not maintained!\nUnable to withdraw!\n");
            return;
        }
        if (amount > accBalance) {
            System.out.println("Insufficient Balance!\n");
            return;
        }
        accBalance -= amount;
        System.out.println("$"+amount+" has been debited to your a/c XXXXX"+accountNo%10000+"\n");
    }
    protected void displayDetails(){
        System.out.println("a/c Holder: "+accHolder+"\na/c type: "+accType+"\na/c No.: "+accountNo+"\nAvail bal: $"+accBalance+"\n");
    }
}

