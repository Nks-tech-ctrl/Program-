import java.util.Scanner;

public class Calculator {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double num1;
        double num2;

        double result;

        int choice;

        System.out.println("===Calculator===");
        System.out.println("1. Add");
        System.out.println("2. Subtract");
        System.out.println("3. Multiply");
        System.out.println("4. Divide");

        System.out.println("Choose Option!");
        choice = sc.nextInt();

        if (choice == 1) {
            System.out.print("Enter num1:");
            num1 = sc.nextDouble();

            System.out.print("Enter num2:");
            num2 = sc.nextDouble();

            result = num1 + num2;

            System.out.println(result);

        }

        else if (choice == 2) {
            System.out.print("Enter num1:");
            num1 = sc.nextDouble();

            System.out.print("Enter num2:");
            num2 = sc.nextDouble();

            result = num1 - num2;

            System.out.println(result);

        }

        else if (choice == 3) {
            System.out.print("Enter num1:");
            num1 = sc.nextDouble();

            System.out.print("Enter num2:");
            num2 = sc.nextDouble();

            result = num1 * num2;

            System.out.println(result);

        } else if (choice == 4) {
            System.out.print("Enter num1:");
            num1 = sc.nextDouble();

            System.out.print("Enter num2:");
            num2 = sc.nextDouble();

            result = num1 / num2;

            System.out.println(result);

        } else {
            System.out.println("Invalid Choice!");
        }

        sc.close();
    }
}
