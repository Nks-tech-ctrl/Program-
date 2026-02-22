import java.util.Scanner;
 class midLibs{
    public static void main(String[]args){
        Scanner sc =new Scanner(System.in);

        String adjective1;
        String noun1;
        String adjective2;
        String verb1;
        String adjective3;

        System.out.println("Enter an adjective(description):");
        adjective1 =sc.nextLine();
        System.out.println("enter a noun(animal or person):");
        noun1 =sc.nextLine();
        System.out.println("enter an adjective (Description):");
        adjective2 =sc.nextLine();
        System.out.println("enter a verb with -ing(action): ");
        verb1 =sc.nextLine();
        System.out.println("Enter an adjective(description:");
        adjective3 =sc.nextLine();

    System.out.println("\ntoday i went ta a"+ adjective1+"zoo");
    System.out.println("In a exhibition ,I saw a"+noun1+".");
    System.out.println(noun1+"was"+adjective2+"and"+verb1+"!");
    System.out.println("I was"+adjective3+"!");

    sc.close();
    }
}