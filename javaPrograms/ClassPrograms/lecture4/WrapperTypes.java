package lecture4;

import java.util.ArrayList;

public class WrapperTypes {
    public static void main(String[] args) {
        /**
         * primitive data type -> wrapper classes
         * byte -> Byte
         * short -> Short
         * int -> Integer
         * long -> Long
         * float -> Float
         * double -> Double
         * char -> Character
         * boolean -> Boolean
         */

        Integer y = 20; // Boxing (int to Integer)
        Integer z = 20;
        System.out.println(y == z); // true
        y++; // AutoBoxing (Unboxing , Boxing) java 5 onwards
        System.out.println(y); // 21

        Integer a = 220;
        Integer b = 220;
        System.out.println(a == b); // false (1 Byte limit exceed) (== compares reference)
        System.out.println(a.equals(b)); // true, comparing values using .equals

        System.out.println(Integer.valueOf(a));
        // Unboxing converts an Integer reference to an int value
        int primitiveVal = a; // compiler do internally- equivalent to a.intValue()
        System.out.println(primitiveVal);

        Integer val = null; // possible in wrapper classes
        System.out.println(val); // print null
        // int val2 = null; // not possible

        ArrayList<Integer> list = new ArrayList<>();
        list.add(44); // AutoBoxing int -> Integer
        System.out.println(list);
        // ArrayList<int> list = new ArrayList<>(); // not possible

        int num = Integer.parseInt("123");
        System.out.println(num);// "123" converted from string to int
    }
}