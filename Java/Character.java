import java.util.Scanner;

class Character{
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int characters = 0;
        int words = 0;
        int lines = 0;

        System.out.println("Enter text (type 'End' on a new line to stop):");

        while (true) {
            String line = sc.nextLine();

            if (line.equals("End"))
                break;

            lines++;
            characters += line.length();

            String[] wordArray = line.trim().split("\\s+");

            if (!line.trim().isEmpty())
                words += wordArray.length;
        }

        System.out.println("\nTotal Lines: " + lines);
        System.out.println("Total Words: " + words);
        System.out.println("Total Characters: " + characters);

        sc.close();
    }
}