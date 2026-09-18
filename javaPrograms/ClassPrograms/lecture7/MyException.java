package lecture7;

public class MyException extends Exception {
    MyException(String msg) {
        super(msg);
    }
}

/* Exception - (extends) -> Throwable - (implements) -> Serializable */

// public class MyException extends Throwable {
// private static String err;

// MyException(String msg) {
// err = msg;
// }

// public static void showError() {
// System.out.println(err);
// }

// @Override
// public String toString() {
// return err;
// }
// }
