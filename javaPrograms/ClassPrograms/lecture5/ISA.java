package lecture5;

// Upcasting , Downcasting
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

/**
 * SOLID principal
 * S - SRP, single responsibility principle
 * O - Open Closed principle
 * L - Liskov substitution principle
 */

class Summary {
    String title;
    String desc;
    int amount;
    // constructor methods and so on..
    // getter , setter ...
}

class AdvanceSummary extends Summary {
    String dayWise;
    String MonthWise;
}

class Account {
    int id;
    String name;

    void deposit() {
        System.out.println("Account deposit...");
    }

    void withDraw() {
        System.out.println("Account withDraw...");
    }

    Summary roi() throws Exception {
        System.out.println("Account ROI...");
        Summary summary = new Summary();
        summary.title = "ROI Report";
        summary.desc = "Jan - March";
        summary.amount = 30000;
        return summary;
    }

}

class SavingAccount extends Account {
    void limit() {
        System.out.println("SavingAccount Daily limit of 25 Lakh");
    }

    // polymorphism
    @Override // run time polymorphism
    protected AdvanceSummary roi() throws Exception { // we can only increase the visibility
        // super.roi();
        System.out.println("Saving account 5% ROI");
        AdvanceSummary summary = new AdvanceSummary();
        // do something
        return summary;
    } // covariant return type
}

class CurrentAccount extends Account {
    void odLimit() {
        System.out.println("current Account No Limit Extra Limit");
    }
}

class AccountCaller {
    // polymorphic function
    void call(Account account) throws Exception {
        // common code
        // it can only call common methods and features at parent level
        account.deposit();
        account.withDraw();
        account.roi();

        if (account instanceof SavingAccount) {
            ((SavingAccount) account).limit(); // Downcasting
        } else if (account instanceof CurrentAccount) {
            ((CurrentAccount) account).odLimit(); // Downcasting
        }
        System.out.println("***************************");
    }
}

// Parent - child relationship
public class ISA {

    static void print(List<Integer> list) {
        // it can implement all the functions
        // run the common function as per the object passed
    }

    public static void main(String[] args) throws Exception {
        print(new ArrayList<Integer>()); // Upcasting
        print(new LinkedList<Integer>()); // Upcasting
        print(new Vector<Integer>()); // Upcasting

        AccountCaller ac = new AccountCaller();
        // SavingAccount sa = new SavingAccount();

        // child is Upcasted to parent so now it can only use features which parent have
        // Account account = new SavingAccount(); // Upcasting
        ac.call(new SavingAccount());
        ac.call(new CurrentAccount());

        // below are some repeated work [it breaks DRY principle]
        // sa.deposit();
        // sa.withDraw();
        // sa.roi();
        // sa.limit();
        // System.out.println("***************************");

        // CurrentAccount ca = new CurrentAccount();
        // ca.deposit();
        // ca.withDraw();
        // ca.roi();
        // ca.odLimit();
    }
}