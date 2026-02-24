#include<stdio.h>

int main() {
    int fragment[20], b[20], p[20];
    int i, j, nb, np;
    int lowest, temp;
    int barray[20] = {0};    
    int parray[20] = {0};     

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("\nEnter the size of blocks:\n");
    for(i = 0; i < nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of processes:\n");
    for(i = 0; i < np; i++) {
        printf("Process %d: ", i);
        scanf("%d", &p[i]);
    }

    
    for(i = 0; i < np; i++) {
        lowest = 9999;

        for(j = 0; j < nb; j++) {
            if(barray[j] == 0) {
                temp = b[j] - p[i];

                if(temp >= 0 && temp < lowest) {
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }

        if(lowest != 9999) {
            fragment[i] = lowest;
            barray[parray[i]] = 1;
        } else {
            parray[i] = -1;   
            fragment[i] = -1;
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\tBlock Size\tFragment\n");

    for(i = 0; i < np; i++) {
        if(parray[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                   i, p[i], parray[i], b[parray[i]], fragment[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i, p[i]);
    }

    return 0;
}