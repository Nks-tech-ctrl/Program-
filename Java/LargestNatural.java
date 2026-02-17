import java.util.Scanner;

class LargestNatural {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        System.out.print("How many numbers: ");
        int n = sc.nextInt();

        int max = 0;

         System.out.println("Enter the numbers:");

        for (int i = 1; i <= n; i++) {

            int num = sc.nextInt();

            if (num > max) {
                max = num;
            }
        }

        System.out.println("Largest natural number: " + max);

        sc.close();
    }
}
