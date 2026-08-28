package lecture6;

class P1 {
    P1() {
        System.out.println("P1 default constructor");
    }

    P1(int x) {
        this();
        System.out.println("P1 parametrized constructor " + x);
    }
}

class P2 extends P1 {
    P2() {
        super(30);
        // super();
        System.out.println("P2 default constructor");
    }

    P2(int x) {
        this();
        // super(x * x);
        System.out.println("P2 parametrized constructor " + x);
    }
}

class C3 extends P2 {
    C3() {
        super(20);
        // super();
        System.out.println("C3 default constructor");
    }

    C3(int x) {
        this();
        // super(x * x);
        System.out.println("C3 parametrized constructor " + x);
    }
}

public class ConstructorChain {
    public static void main(String[] args) {
        // C3 obj = new C3();
        C3 obj = new C3(10);
    }
}
