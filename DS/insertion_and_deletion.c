#include <stdio.h>
int main()
{
    int A[10], n, i, position, value, choice;

    printf("Enter no of elements:");
    scanf("%d", &n);

    printf("Enter %d elements : \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\n1. Insert\n2. Delete\nEnter your choice:");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter position to insert element:", n + 1);
        scanf("%d", &position);

        printf("Enter value to insert element :");
        scanf("%d", &value);

        if (position<1||position> n+1)
        {
            printf("invalid position!\n");
        }else{
            for ( i = n; i >=position; i--)
            {
                A[i]=A[i-1];
            }
            A[position-1]=value;
            n++;

            printf("Array after insertion:\n");
            for ( i = 0; i < n; i++)
            {
                printf("%d  ",A[i]);
            }
            
            
        }
        
    }
    else if (choice==2)
    {
        printf("enter position to delete:",n);
        scanf("%d",&position);

        if(position<1||position>n){
            printf("invalid position!");
        }else{
               for ( i = n; i,n-1; i++)
               {
                A[i]=A[i+1];
               }
               n--;

               printf("Array after deletion:\n");
               for ( i = 0; i < n; i++)
               {
                printf("%d  ",A[i]);
               }
               
               
        }
    }else{
        printf("Invalid choice!");
    }
    

    return 0;
}