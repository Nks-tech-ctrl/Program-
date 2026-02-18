import java.util.Scanner;

class Student {
    String usn;
    String name;
    String branch;
    String phone;
    double percentage;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Student s1 = new Student();

        System.out.print("Enter USN: ");
        s1.usn = sc.nextLine();

        System.out.print("Enter Name: ");
        s1.name = sc.nextLine();

        System.out.print("Enter Branch: ");
        s1.branch = sc.nextLine();

        System.out.print("Enter Phone: ");
        s1.phone = sc.nextLine();

        System.out.print("Enter Percentage: ");
        s1.percentage = sc.nextDouble();

        System.out.println("\nStudent Details");
        System.out.println("USN: " + s1.usn);
        System.out.println("Name: " + s1.name);
        System.out.println("Branch: " + s1.branch);
        System.out.println("Phone: " + s1.phone);
        System.out.println("Percentage: " + s1.percentage);

        sc.close();
    }
}
