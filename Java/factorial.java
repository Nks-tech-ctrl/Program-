import java.util.Scanner;
public class factorial{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number:");
        int n =sc.nextInt();

        int fact=1;

        while(n>0){
            fact=fact*n;
            n=n-1;

        }
        System.out.println("factorial="+fact);
    }
}