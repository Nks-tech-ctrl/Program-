import java.util.Scanner;

class MatrixMultiply {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int r1, r2, c1, c2;

        System.out.println("Enter rows and columns of 1st matrix:");
        r1 = sc.nextInt();
        c1 = sc.nextInt();

        System.out.println("Enter rows and columns of 2nd matrix:");
        r2 = sc.nextInt();
        c2 = sc.nextInt();

        
        if (c1 != r2) {
            System.out.println("Invalid matrix multiplication order.");
            return;
        }

        int a[][] = new int[r1][c1];
        int b[][] = new int[r2][c2];
        int result[][] = new int[r1][c2];

        
        System.out.println("Enter elements of 1st matrix:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        
        System.out.println("Enter elements of 2nd matrix:");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                b[i][j] = sc.nextInt();
            }
        }

        
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        
        System.out.println("Result matrix:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
