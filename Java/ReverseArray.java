import java.util.Scanner;
class ReverseArray{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no of elements:");
        int n=sc.nextInt();
        int arr[]=new int[n];
         System.out.println("Enter" +n+"elements:");
         for( int i=0;i<n;i++){
            arr[i]=sc.nextInt();
         }

         System.out.println("Array elemnts in reverse order:");
         for(int i=n-1;i>=0;i--){
            System.out.println(arr[i]+"");
         }

         sc.close();
    }
}