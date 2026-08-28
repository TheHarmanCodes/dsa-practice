package lecture7;

public class ExceptionHandling1 {
    public static void main(String[] arr) {
        int mo, mm, pa;

        try {
            mo = Integer.parseInt(arr[0]);
            mm = Integer.parseInt(arr[1]);
            pa = (mo * 100) / mm;
            System.out.println("Percentage: " + pa);
        } catch (ArrayIndexOutOfBoundsException e) { // java.lang
            System.out.println("please enter at least 2 numbers");
        } catch (NumberFormatException e) {
            System.out.println("enter valid integer inputs");
        } catch (ArithmeticException e) {
            System.out.println("Maximum marks value must be non zero");
        }
    }
}
