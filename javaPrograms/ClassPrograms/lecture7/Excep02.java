package lecture7;

class Excep02 {
	public static void main(String s[]) {
		int mo, mm, p;
		try {
			mo = Integer.parseInt(s[0]);
			System.out.println("\n\tMarks obtained is okay");
			mm = Integer.parseInt(s[1]);
			System.out.println("\n\tMax Marks is okay");
			p = (mo * 100) / mm;
			System.out.println("\n\tpercentage : " + p);
		} catch (Exception ex) {
			System.out.println("\n\t\tException found : " + ex);
		}
		System.out.print("\n\n\tREst of the code");
	}
}
