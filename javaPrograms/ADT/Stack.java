package javaPrograms.ADT;

import java.util.ArrayList;
import java.util.EmptyStackException;

public class Stack<T> {
    private ArrayList<T> arr;
    private int capacity;
    private int top;

    Stack(int capacity) {
        // we can also remove the capacity as we used ArrayList,
        this.capacity = capacity;
        top = -1;
        arr = new ArrayList<T>(capacity);
    }

    public T push(T element) {
        if (getSize() == capacity) {
            throw new IllegalStateException("Stack Overflow");
        }
        top++;
        arr.add(element);
        return element;
    }

    public T pop() {
        if (isEmpty()) { // OR getSize() == 0
            throw new EmptyStackException();
        }
        T element = arr.removeLast();
        top--;
        return element;
    }

    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return arr.getLast();
    }

    // display is now optional as we can directly print the stack
    public void display() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        for (int i = top; i >= 0; i--) {
            System.out.println(arr.get(i));
        }
    }

    private int getSize() {
        return top + 1;
    }

    private boolean isEmpty() {
        return top == -1 ? true : false;
    }

    @Override
    public String toString() {
        if (isEmpty()) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder("[");
        for (int i = top; i >= 0; i--) {
            sb.append(arr.get(i));
            if (i > 0) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
