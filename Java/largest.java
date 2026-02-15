import java.util.Scanner;
public class largest{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number:");
        int a =sc.nextInt();

        System.out.println("Enter the number:");
        int b =sc.nextInt();
        
        System.out.println("Enter the number:");
        int c =sc.nextInt();

        if(a>b && a>c){
            System.out.println("largest="+a);
        }else if{b>c}{
            System.out.println("largest="+b);
        }else{
            System.out.println("largest="+c);
            
        }
    }
}