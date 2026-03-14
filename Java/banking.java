import java.util.Scanner;

public class banking {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double balance = 0.00;
        boolean isRunning = true;

        int choice;

        while (isRunning) {

            System.out.println("***********************");
            System.out.println("Banking Management");
            System.out.println("***********************");

            System.out.println("1. Showing Balance");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Exit");
            System.out.println("***********************");

            System.out.print("Enter your choice(1-4):");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> showBalance(balance);
                case 2 -> balance = balance + deposit();
                case 3 -> balance = balance -withdraw(balance);
                case 4 -> isRunning = false;
                default -> System.out.println("Invalid input!");
            }

        }

    }

    static void showBalance(double balance) {
        System.out.printf("$%.2f \n", balance);
    }

    static double deposit() {
        double amount;

        System.out.print("Enter amount to deposit: ");
        amount = sc.nextDouble();

        if (amount < 0) {
            System.out.println("Amount cannot be negative");
            return 0;
        } else {
            return amount;
        }
    }

    static double withdraw(double balance) {
        double amount;
        System.out.println("Enter amount to withdraw:");
        amount = sc.nextDouble();
        if (amount > balance) {
            System.out.println("Insufficent balance!");
            return 0;
        } else if (amount < 0) {
            System.out.println("Amount can't be Negative!");
            return 0;
        } else {

            return amount;
        }

    }
    
}
