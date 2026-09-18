package gui;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import java.awt.event.*;

public class SwingEx3 extends JFrame implements ActionListener {
    JLabel l1, l2, l3, l4, l5;
    JTextField tf1, tf2, tf3, tf4, tf5;
    JButton btn;

    SwingEx3() {
        setSize(700, 750);
        setTitle("Grades Calculator");
        setLayout(null);
        l1 = new JLabel("Marks 1:");
        l2 = new JLabel("Marks 2:");
        l3 = new JLabel("Marks 3:");
        l4 = new JLabel("Percentage:");
        l5 = new JLabel("Grades");
        tf1 = new JTextField();
        tf2 = new JTextField();
        tf3 = new JTextField();
        tf4 = new JTextField();
        tf5 = new JTextField();
        btn = new JButton("Compute");

        l1.setBounds(100, 50, 50, 40);
        tf1.setBounds(200, 50, 200, 40);

        l2.setBounds(100, 100, 50, 40);
        tf2.setBounds(200, 100, 200, 40);

        l3.setBounds(100, 150, 50, 40);
        tf3.setBounds(200, 150, 200, 40);

        l4.setBounds(100, 200, 80, 40);
        tf4.setBounds(200, 200, 200, 40);

        l5.setBounds(100, 300, 50, 40);
        tf5.setBounds(200, 300, 200, 40);
        btn.setBounds(150, 380, 120, 40);

        add(l1);
        add(l2);
        add(l3);
        add(l4);
        add(l5);
        add(tf1);
        add(tf2);
        add(tf3);
        add(tf4);
        add(tf5);
        add(btn);
        btn.addActionListener(this);
        tf4.setEditable(false);
        tf5.setEditable(false);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            if (tf1.getText().trim().isEmpty() || tf2.getText().trim().isEmpty() || tf3.getText().trim().isEmpty()) {
                throw new Exception("No input is supplied");
            }

            int m1 = Integer.parseInt(tf1.getText().trim());
            int m2 = Integer.parseInt(tf2.getText().trim());
            int m3 = Integer.parseInt(tf3.getText().trim());

            if (m1 < 0 || m2 < 0 || m3 < 0) {
                throw new Exception("Negative marks are applied");
            }

            int total = m1 + m2 + m3;
            double pa = total / 3.0;
            String grade;

            if (pa < 50) {
                grade = "C";
            } else if (pa < 75) {
                grade = "B";
            } else {
                grade = "A";
            }

            tf4.setText(String.format("%.2f", pa));
            tf5.setText(grade);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Invalid input is provided");
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage());
        }
    }

    public static void main(String[] args) {
        new SwingEx3();
    }
}
