package gui;

import javax.swing.*;
import java.awt.event.*;

public class Circle extends JFrame implements ActionListener {
    MyFrame f1;
    JLabel l1, l2, l3;
    JTextField tf1, tf2, tf3;

    JButton btn;

    Circle(MyFrame ob1) {
        f1 = ob1;
        setSize(400, 400);
        setTitle("Circle");
        setLocation(200, 200);
        setLayout(null);
        l1 = new JLabel("X:");
        l2 = new JLabel("Y:");
        l3 = new JLabel("Radius:");

        tf1 = new JTextField();
        tf2 = new JTextField();
        tf3 = new JTextField();

        l1.setBounds(150, 50, 40, 40);
        tf1.setBounds(200, 50, 40, 40);

        l2.setBounds(150, 100, 40, 40);
        tf2.setBounds(200, 100, 40, 40);

        l3.setBounds(120, 150, 60, 40);
        tf3.setBounds(200, 150, 40, 40);

        btn = new JButton("Submit");
        btn.setBounds(150, 250, 100, 30);
        add(l1);
        add(tf1);
        add(l2);
        add(tf2);
        add(l3);
        add(tf3);
        add(btn);
        btn.addActionListener(this);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        f1.x1 = Integer.parseInt(tf1.getText());
        f1.y1 = Integer.parseInt(tf2.getText());
        f1.r = Float.parseFloat(tf3.getText());
        f1.isLine = false;
        f1.repaint();
        dispose();
    }
}
