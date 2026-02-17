import  java.util.Scanner;
public class Product{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number : ");
        int a =  sc.nextInt();

        System.out.print("Enter the Second number : ");
        int b = sc.nextInt();

        int product = a * b;

        System.out.println("Product="+product);

    }
}