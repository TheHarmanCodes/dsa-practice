package lecture3;

import java.util.Scanner;

public class Employee {
    private String name, dept;
    private int eid, salary;

    // we can also use getter and setters---
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDept() {
        return dept;
    }

    public void setDept(String dept) {
        this.dept = dept;
    }

    public int getEid() {
        return eid;
    }

    public void setEid(int eid) {
        this.eid = eid;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    // static variable is accessible to all class objects
    // can also be access using class name (ex: Employee.uni) without creating any
    // object
    public static String uni;
    static {
        uni = "GEU";
    }

    Employee() {
        String name = "";
        String dept = "";
    }

    Employee(int eid, String name, int salary, String dept) {
        this.eid = eid;
        this.name = name;
        this.salary = salary;
        this.dept = dept;
    }

    private Scanner sc = new Scanner(System.in);

    public void input() {
        System.out.print("Enter id: ");
        eid = sc.nextInt();
        System.out.print("Enter Employee Name: ");
        sc.nextLine();
        name = sc.nextLine();
        System.out.print("Enter Employee Salary: ");
        salary = sc.nextInt();
        System.out.print("Enter Employee Department: ");
        sc.nextLine();
        dept = sc.next();
    }

    public void display() {
        System.out.println("\nID: " + eid + "\nName: " + name + "\nSalary: " + salary
                + "\nDepartment: " + dept + "\nUni: " + uni);
    }

    boolean isExists(int eid) {
        return this.eid == eid;
    }
}