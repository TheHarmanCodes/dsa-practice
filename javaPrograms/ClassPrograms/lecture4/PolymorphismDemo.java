package lecture4;

/**
 * Polymorphism
 * or Compile Time Polymorphism (static Polymorphism)
 * done using method overloading (same method name and can have different
 * arguments)
 */

class CalculateArea {
    // area of square
    float area(float side) {
        return side * side;
    }

    // area of rectangle
    float area(float length, float width) {
        return length * width;
    }

    // area of circle
    float area(float r, int x) {
        return (float) (Math.PI * r * r);
    }

    int area(int a) {
        return a * a;
    }
}

public class PolymorphismDemo {
    public static void main(String[] args) {
        CalculateArea c1 = new CalculateArea();
        System.out.println(c1.area(5));
        System.out.println(c1.area(10, 15.2f));
        System.out.println(c1.area(6, 0));
    }
}
