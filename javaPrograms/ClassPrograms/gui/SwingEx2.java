package gui;

import javax.swing.*;
import java.awt.event.*;

public class SwingEx2 extends JFrame implements ActionListener {
    JButton b1, b2;

    SwingEx2() {
        b1 = new JButton("OK");
        b2 = new JButton("close");
        b1.setBounds(280, 80, 80, 40);
        b2.setBounds(380, 80, 80, 40);

        setTitle("Multiple Buttons Handling demo");
        setSize(800, 400);
        setLayout(null);
        setLocation(100, 80);
        add(b1);
        add(b2);
        b1.addActionListener(this);
        b2.addActionListener(this);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b1) {
            System.out.println("OK button pressed");
        }
        if (e.getSource() == b2) {
            System.out.println("Close button pressed\n Window closed");
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new SwingEx2();
    }
}
