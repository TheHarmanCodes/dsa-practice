package javaPrograms.ClassPrograms.gui;

import java.awt.event.*;
import javax.swing.*;

public class SwingEx1 extends JFrame implements ActionListener {
    JButton b1;

    SwingEx1() {
        b1 = new JButton("Click Me");
        b1.setBounds(360, 50, 80, 40);
        add(b1);
        setTitle("My first swing application");
        setLocation(200, 100);
        setSize(800, 600);
        b1.addActionListener(this);
        setLayout(null);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        b1.setText("clicked");
        System.out.println("Button is clicked");
    }

    public static void main(String[] args) {
        new SwingEx1();
    }
}