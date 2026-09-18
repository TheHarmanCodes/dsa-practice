package lecture7;

public class ExceptionHandling3 {
    public static void main(String[] s) {
        int mm = 0, mo = 0, pa;
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
                if (mo < 0 || mm < 0) {
                    throw new MyException("Marks can not be negative");
                }
                if (mm == 0) {
                    throw new MyException("Maximum Marks can not be zero");
                }
                if (mo > mm) {
                    throw new MyException("Marks Obtained can not be greater than Maximum Marks");
                }
                pa = (mo * 100) / mm;
                System.out.println("Percentage: " + pa);
            } catch (MyException e) {
                // MyException.showError();
                System.out.println(e.getMessage());
            } catch (ArithmeticException e) {
                System.out.println("maximum marks must not be zero.");
            }

        } catch (Exception e) {
            System.out.println(e.getMessage() + "\n");
            e.printStackTrace();
        }
    }
}
