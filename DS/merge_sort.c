#include <stdio.h>
int main()
{
    int a[10], b[10], c[20];
    int n1, n2, i;

    printf("Enter size of 1st array: ");
    scanf("%d", &n1);

    printf("Enter the elements of 1st array:");

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter size of 2nd array: ");
    scanf("%d", &n2);

    printf("Enter the elements of 2nd array:");

    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n1; i++)
    {
        c[i] = a[i];
    }

    for (i = 0; i < n2; i++)
    {
        c[n1 + i] = b[i];
    }

    printf("Merge array:\n");
    for (i = 0; i < n1 + n2; i++)
    {
        printf("%d  ", c[i]);
    }

    return 0;
}