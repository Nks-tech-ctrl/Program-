import java.util.Scanner;
public class circumfrence {
    public static void main(String args[]){
     Scanner sc =new Scanner(System.in);
        
     double radius;
     double circumfrence;

     System.out.println("Enter the radius:");
     radius =sc.nextDouble();

     circumfrence =  2*Math.PI*radius;

     System.out.println(circumfrence);

     sc.close();
    }
}
