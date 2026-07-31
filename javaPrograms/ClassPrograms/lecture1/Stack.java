package lecture1;

import java.util.EmptyStackException;

public class Stack { // only Integer stack
    private int top, size;
    private int arr[];

    Stack(int size) {
        this.size = size;
        arr = new int[size];
        top = -1;
    }

    public int push(int item) {
        if (getSize() == size) {
            throw new IllegalStateException("Stack Overflow");
        }
        arr[++top] = item;
        return arr[top];
    }

    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return arr[top--];
    }

    public void display() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        for (int i = top; i >= 0; i--) {
            System.out.println(arr[i]);
        }
    }

    public boolean isEmpty() {
        return top == -1;
    }

    private int getSize() {
        return top + 1;
    }

}
