#include <stdio.h>

int main()
{
    int r, c;

    printf("Enter rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);

    int A[r][c], B[r][c], sum[r][c], subtract[r][c];

    // Input first matrix
    printf("Enter elements of 1st matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    // Input second matrix
    printf("Enter elements of 2nd matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &B[i][j]);

    // Addition and subtraction
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
            subtract[i][j] = A[i][j] - B[i][j];
        }
    }

    //  sum matrix
    printf("\nSum Matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");  
    }

    //  subtraction matrix
    printf("\nSubtract Matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", subtract[i][j]);   
        }
        printf("\n");  
    }

    return 0;
}