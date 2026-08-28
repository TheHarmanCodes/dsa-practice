package lecture5;

import java.util.*;

class Student {
	private String nm, sub;
	private int roll, mo;

	public void input() {
		Scanner sc = new Scanner(System.in);
		System.out.print("\n\tenter name, subject, roll no and marks : ");
		nm = sc.nextLine();
		sub = sc.next();
		roll = sc.nextInt();
		mo = sc.nextInt();
		sc.close();
	}

	@Override
	public String toString() {
		String a = "\n\tName : " + nm;
		a += "\n\tSubject : " + sub;
		a += "\n\tRoll NO : " + roll;
		a += "\n\tMarks : " + mo;

		return a;
	}

	public void output() {
		System.out.print("\n\t" + nm + "\t" + sub + "\t" + roll + "\t" + mo);
	}

}

public class ToStringOverride {
	public static void main(String s[]) {
		Student s1 = new Student();
		s1.input();
		System.out.println(s1);
		String str = "Record : " + s1;
		System.out.println(str);
	}
}