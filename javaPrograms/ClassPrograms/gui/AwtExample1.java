package javaPrograms.ClassPrograms.gui;

import java.awt.*;

// using Inheritance, our class inherits Frame class
public class AwtExample1 extends Frame {
    AwtExample1() {
        Button b1 = new Button("Click Me!");
        // setting button position on screen
        // (x, y, width, height)
        b1.setBounds(260, 185, 80, 30);

        // setting the frame title
        setTitle("My First Frame");
        setSize(600, 400); // setting frame size (width, height)
        // set the first display position of frame, from top left corner of screen
        setLocation(500, 300); // axis - (x,y);
        setLayout(null);
        // adding the button to frame
        add(b1);
        // set the frame to be visible, by default frame is not visible
        setVisible(true);
    }

    public static void main(String[] args) {
        new AwtExample1();
    }
}