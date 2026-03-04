import java.util.Scanner;
public class Temprature_Converter {
    public static void main(String args[]){
    Scanner sc =new Scanner(System.in);
    double Temp;
    double newTemp;
    String unit;

    System.out.println("Enter the temprature: ");
    Temp = sc.nextDouble();

    System.out.println("Conver to celsius or fahrenheit?(C or F)");
    unit =sc.next().toUpperCase();

   newTemp =(unit.equals("c"))? (Temp-32)*5/9 :(Temp*5/9)+32;
   System.out.println(newTemp+"°"+unit);

   sc.close();
    }
}
