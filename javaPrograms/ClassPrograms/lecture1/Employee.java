import java.util.Scanner;

public class Employee {
    private int eid;
    private String name;
    private float salary;
    private String department;

    private Scanner sc = new Scanner(System.in);

    public void input() {
        System.out.print("Enter id: ");
        eid = sc.nextInt();
        System.out.print("Enter Employee Name: ");
        sc.nextLine();
        name = sc.nextLine();
        System.out.print("Enter Employee Salary: ");
        salary = sc.nextFloat();
        System.out.print("Enter Employee Department: ");
        sc.nextLine();
        department = sc.nextLine();
    }

    public void display() {
        System.out.println("\n ----Employee Details----" + "\nID: " + eid + "\nName: " + name + "\nSalary: " + salary
                + "\nDepartment: " + department);
    }

    public boolean searchId(int eid) {
        return this.eid == eid;
    }

    public void updateName(String name) {
        this.name = name;
    }

    public void bonus(float amount) {
        if (amount <= 0 || Float.isNaN(amount) || Float.isInfinite(amount)) {
            System.out.println("bonus amount must be a valid positive value");
            return;
        }
        salary = salary + amount;
    }

    @Override
    public String toString() {
        return "{" + "eid=" + eid + ", name='" + name + '\'' + ", salary=" + salary + ", department='" + department
                + '\'' + '}';
    }
}