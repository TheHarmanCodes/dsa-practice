package lecture2;

import java.util.Scanner;

/*
* In lecture 2 we learn about the Constructor
* Constructors are special methods which has the same name as the class 
* A constructor is invoked when an object is created
* A constructor has no return type
*/

public class Student {
    // Members of the class
    // instance members
    private String name, sub;
    private int roll, mo, mm;

    {
        System.out.println("init block");
    }

    // User-defined no-argument constructor
    // class name and constructor name are same
    // constructor never return
    Student() {
        mm = 100;
    }

    // Parameterized Constructor
    Student(int roll, String name, String sub, int mo) {
        this(); // 'this' will call default constructor
        this.roll = roll;
        this.name = name;
        this.mo = mo;
    }

    public void input() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter roll number: ");
        roll = sc.nextInt();

        System.out.print("Name: ");
        sc.nextLine();
        name = sc.nextLine();

        System.out.print("Enter Subject: ");
        sub = sc.nextLine();

        System.out.print("Marks obtained ");
        mo = sc.nextInt();
        sc.close();
    }

    public void display() {
        System.out.println("\nStudent Details:\nRoll no: " + roll + "\nName: " + name + "\nSubject: " + sub
                + "\nMarks Obtained: " + mo + "\nMaximum Marks: " + mm);
    }

    boolean isExists(int roll) {
        return this.roll == roll;
    }

    // public String toString() {
    // return "Student{" +
    // "roll=" + roll +
    // ", name='" + name + '\'' +
    // ", subject='" + sub + '\'' +
    // ", marksObtained=" + mo +
    // ", maximumMarks=" + mm +
    // '}';
    // }

}
