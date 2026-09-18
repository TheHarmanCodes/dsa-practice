package javaPrograms.ClassPrograms.gui;

import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AwtExample2 extends Frame implements ActionListener {
    AwtExample2() {
        Button b1 = new Button("Click Me!");
        b1.setBounds(260, 50, 80, 30);

        setTitle("Button Component demo");
        setSize(600, 400);
        setLocation(500, 300);
        setLayout(null);
        add(b1);
        b1.addActionListener(this);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        System.out.println("Button is clicked");
    }

    public static void main(String[] args) {
        new AwtExample2();
    }
}