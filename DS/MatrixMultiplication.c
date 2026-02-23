#include <stdio.h>

int main()
{
    int r1, r2, c1, c2;

    printf("Enter rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Multiplication not possible!\n");
        return 0;
    }

    int first[r1][c1], second[r2][c2], result[r1][c2];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    printf("Enter first matrix elements:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &first[i][j]);

    
    printf("Enter second matrix elements:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &second[i][j]);

    
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    
    printf("Result matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}