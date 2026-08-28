package lecture2;

class Stud {
	String nm, sub;
	int roll, mo;

	Stud() {
		System.out.print("\n\tdefault constructor is called");
	}

	Stud(String a, String b, int c, int d) {
		nm = a;
		sub = b;
		roll = c;
		mo = d;
		System.out.print("\n\tArgument constructor is called");
	}

	Stud(Stud x) {
		nm = x.nm;
		sub = x.sub;
		roll = x.roll;
		mo = x.mo;
		System.out.print("\n\tCopy constructor is called");
	}

	public void show() {
		System.out.print("\n\t" + nm + "\t" + sub + "\t" + roll + "\t" + mo);
	}
}

class A5 {
	public static void main(String s[]) {
		Stud s1 = new Stud();
		Stud s2 = new Stud("Amit", "Math", 54, 78);
		Stud s3 = new Stud("arun", "cse", 43, 48);
		Stud s4 = new Stud(s2);
		s1.show();
		s2.show();
		s3.show();
		s4.show();
		Stud s5 = s2; // s5 and s2 both are referring to same memory location

		if (s2 == s5) {
			System.out.print("\n\n\tsame");
		} else {
			System.out.print("\n\tnot same");
		}
	}
}
