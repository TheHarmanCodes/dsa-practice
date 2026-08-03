package javaPrograms.ADT;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>(5);
        stack.push(5);
        stack.push(45);
        stack.push(40);
        stack.push(50);
        stack.push(10);
        System.out.println(stack.peek());
        stack.pop();
        System.out.println(stack.peek());

        System.out.println(stack);
        stack.push(1);
        stack.push(888);
        System.out.println(stack);
    }
}
