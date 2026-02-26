import java.util.Scanner;
public class ShoppingCart{
    public static void main(String args[]){
        Scanner sc =new Scanner(System.in);

        String item;
        double price;
        int quantity;
        char currency='$';
        double total;

        System.out.print("What item you like to buy:");
        item=sc.nextLine();

        System.out.print("What is price for each?:");
        price=sc.nextDouble();

        System.out.print("What is quantity:");
        quantity=sc.nextInt();

        total =price*quantity;

        System.out.println("\n you have bought"+quantity+""+item);
        System.out.println("Your total is"+currency+total);
        sc.close();
    }

}