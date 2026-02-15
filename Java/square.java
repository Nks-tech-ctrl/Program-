import java.util.Scanner;
class square{
    public static void main(String args[]){
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter the number: ");
        int n = sc.nextInt();

        int square=n*n;

        System.out.println("square ="+square);
    }
}