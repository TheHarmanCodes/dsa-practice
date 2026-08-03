package lecture4;

public class TypeConversion {
    public static void main(String[] args) {
        // Implicit type conversion, -> automatically done by java compiler

        int x = 66;
        long l = x; // auto converted from int to long

        float f = l; // auto converted from long to float

        System.out.println(x);
        System.out.println(l);
        System.out.println(f);

        // explicit type conversion, -> manually done by programmer
        float b = 50.55f;

        int a = (int) b;
        System.out.println(a); // decimal value will be lost

    }
}
