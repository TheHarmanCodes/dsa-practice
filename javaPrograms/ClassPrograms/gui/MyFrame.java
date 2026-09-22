package gui;

import javax.swing.*;

import java.awt.Graphics;
import java.awt.event.*;

public class MyFrame extends JFrame implements ActionListener {
    JButton btn1, btn2;
    int x1, x2, y1, y2;
    float r;
    boolean isLine = true;

    MyFrame() {
        setSize(700, 600);
        setTitle("Data Flow in Multiple Frames");
        setLayout(null);
        setLocation(100, 100);

        btn1 = new JButton("Line");
        btn2 = new JButton("Circle");

        btn1.setBounds(200, 50, 80, 40);
        btn2.setBounds(400, 50, 80, 40);
        add(btn1);
        add(btn2);
        setVisible(true);

        btn1.addActionListener(this);
        btn2.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btn1) {
            new Line(this);
        } else {
            new Circle(this);
        }
    }

    public void paint(Graphics g) {
        super.paint(g);
        if (isLine)
            g.drawLine(x1, y1, x2, y2);
        else
            g.drawOval(x1, y1, (int) r, (int) r);
    }

    public static void main(String[] args) {
        MyFrame f1 = new MyFrame();
    }
}
