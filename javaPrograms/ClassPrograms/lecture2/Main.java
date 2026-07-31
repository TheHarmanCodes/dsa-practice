package lecture2;

public class Main {
    public static void main(String[] args) {
        Student s1, s2, s3;

        s1 = new Student();
        s1.input();
        // s1.display();

        s2 = s1; // here s2 will also store reference to s1
        // s1 === s2 (both are referring to same memory location)
        s2.display();

        s3 = new Student(201, "Ritik", "c", 80);
        s3.display();

    }
}
