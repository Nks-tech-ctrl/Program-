//MVT
#include <stdio.h>

void main() {
    int ms, i, ps[20], n = 0, temp;
    char ch = 'y';

    printf("\nEnter the total memory available (in Bytes): ");
    scanf("%d", &ms);
    temp = ms;

    for (i = 0; ch == 'y'; i++) {
        printf("\nEnter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &ps[i]);

        if (ps[i] <= temp) {
            printf("Memory is allocated for Process %d", i + 1);
            temp = temp - ps[i];
            n++;
        } else {
            printf("Memory is Full");
            break;
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);
    }

    printf("\n\nTotal Memory Available: %d", ms);
    printf("\n\nProcess\t\tMemory Allocated");
    for (i = 0; i < n; i++)
        printf("\n %d\t\t%d", i + 1, ps[i]);

    printf("\n\nTotal Memory Allocated is %d", ms - temp);
    printf("\nTotal External Fragmentation is %d", temp);
}