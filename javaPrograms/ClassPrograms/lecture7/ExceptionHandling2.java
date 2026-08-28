package lecture7;

public class ExceptionHandling2 {
    static int a = 10;

    public static void main(String[] s) {
        int mm = 0, mo = 0, pa;
        System.out.println(a);
        try {
            try {
                mo = Integer.parseInt(s[0]);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Please enter marks obtained");
            } catch (NumberFormatException e) {
                System.out.println("please enter valid number value for mo");
            }
            try {
                mm = Integer.parseInt(s[1]);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Please enter maximum marks");
            } catch (NumberFormatException e) {
                System.out.println("please enter valid number value for mm");
            }
            try {
                pa = (mo * 100) / mm;
                System.out.println("Percentage: " + pa);
            } catch (ArithmeticException e) {
                System.out.println("maximum marks must not be zero.");
            }

        } catch (Exception e) {
            System.out.println(e.getMessage() + "\n");
            e.printStackTrace();
        }
    }
}
