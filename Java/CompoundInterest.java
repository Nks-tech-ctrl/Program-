import java.util.Scanner;

public class CompoundInterest {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double principal;
        double rate;
        int timesCompounded;
        int years;
        double amount;

        System.out.print("Enter the principal amount:");
        principal = sc.nextDouble();

        System.out.print("Enter the interest rate:");
        rate = sc.nextDouble() / 100;

        System.out.print("Enter the no of times compounded yearly:");
        timesCompounded = sc.nextInt();

        System.out.print("Enetr the no of years:");
        years = sc.nextInt();

        amount = principal * Math.pow(1 + rate / timesCompounded, timesCompounded * years);

        System.out.printf("the amount after %d years is %.2f",years,amount);

        sc.close();
    }
}
