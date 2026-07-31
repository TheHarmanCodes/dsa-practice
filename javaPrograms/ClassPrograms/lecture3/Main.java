package lecture3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Employee emp[] = new Employee[10];
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 3; i++) {
            emp[i] = new Employee();
            System.out.println("Enter " + (i + 1) + " details");
            emp[i].input();
        }
        System.out.println("\n-----Enter details-----");
        for (int i = 0; i < 3; i++) {
            emp[i].display();
        }

        // System.out.println("\nEnter employee id to search: ");
        // int i, id = sc.nextInt();
        // for (i = 0; i < 3; i++) {
        // if (emp[i].isExists(id)) {
        // System.out.println("\nEmployee data found");
        // emp[i].display();
        // break;
        // }
        // }
        // if (i == 3) {
        // System.out.print("Employee with id: " + id + " not found.");
        // }

        // accessing the static variable
        System.out.println(Employee.uni);
        System.out.println(emp[2].uni);
        emp[1].uni = "Graphic era";

        System.out.println(emp[0].uni);

        // static variable uni is shared variable if any member change it then it is
        // changed for everyone
        Employee.uni = "Graphic Era University";
        System.out.println(Employee.uni);
        System.out.println(emp[2].uni);

        sc.close();
    }
}