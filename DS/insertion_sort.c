#include<stdio.h>
int main(){
    int a[10],n,i,j,m;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter the elements:\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for ( i = 1; i < n; i++)
    {
        m=a[i];
        j=i-1;

        while (j>=0 && a[j]>m)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=m;
        
    }
    
    printf("Sorted array:\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d  ",a[i]);
    }
    
    return 0;
}