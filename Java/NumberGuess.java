import java.util.Random;
import java.util.Scanner;

public class NumberGuess {
    public static void main(String args[]) {
        Random rd = new Random();

        Scanner sc = new Scanner(System.in);

        int guess;
        int attempts = 0;
        int randomNumber = rd.nextInt(1, 11);

        System.out.println("===Number Guess Game===");
        System.out.println("Guess number between 1-10:");

        do {
            System.out.print("Enter a Guess number: ");
            guess = sc.nextInt();
            attempts++;
            if (guess < randomNumber) {
                System.out.println("Too Low try again");
            } else if (guess > randomNumber) {
                System.out.println("guess too high try again");
            } else {
                System.out.println("Correct! number was" + randomNumber);
                System.out.println("# of attempts:" + attempts);
            }
        } while (guess != randomNumber);

        sc.close();
    }
}
