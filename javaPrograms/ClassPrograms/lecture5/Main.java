package lecture5;

class A {
    int a;

    A() {
        System.out.println("default constructor of A");
        a = 100;
    }

    A(int a) {
        System.out.println("argument constructor of A");
        this.a = a + 50;
    }

    A(A obj) {
        System.out.println("copy constructor of A");
        this.a = obj.a + 10;
    }
}

class B extends A {
    int b1;
    String s;

    B() {
        // super(); // called by default
        System.out.println("default constructor of B");
        b1 = 55;
        s = "Hello";
    }

    B(int a, String b) {
        super(a);
        System.out.println("Argument constructor of B");
        b1 = a;
        s = b;
    }

    B(B obj) {
        System.out.println("copy constructor of B");
        b1 = obj.b1 + 10;
        s = obj.s + " World";
    }

    public void showB() {
        System.out.println(b1 + "\n" + s);
    }
}

public class Main {
    public static void main(String[] args) {
        // B ob = new B();
        B ob = new B(5, "java");
        ob.showB();
    }
}
