import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Employee e1 = new Employee();
        // e1.input();

        // System.out.println(e1);

        Employee emps[] = new Employee[4]; // initially the array contains [null, null, null, null]

        int i, id;

        for (i = 0; i < 4; i++) {
            emps[i] = new Employee(); // initializing the object so that it can get the memory

            System.out.print("Enter " + (i + 1) + "st details\n");
            emps[i].input();
        }

        System.out.println("--------------");

        for (i = 0; i < 4; i++) {
            emps[i].display();
            System.out.println("-----");
        }

        System.out.println("Enter employee id to update name: ");
        id = sc.nextInt();
        boolean isUpdated = false;
        for (i = 0; i < 4; i++) {
            if (emps[i].searchId(id)) {
                System.out.println("Enter new Name: ");
                sc.nextLine();
                String name = sc.nextLine();
                emps[i].updateName(name);
                isUpdated = true;
                break;
            }

        }
        if (!isUpdated) {
            System.out.println("Emp id not found");
        }

        sc.close();
    }
}
