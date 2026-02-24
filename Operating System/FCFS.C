#include <stdio.h>

int main() {
    int n, i;
    int bt[20], at[20], ct[20], tat[20], wt[20];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d] AT: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] BT: ", i + 1);
        scanf("%d", &bt[i]);
    }

    
    for(i = 0; i < n; i++) {
        if (i == 0) {
            ct[i] = at[i] + bt[i];
        } else {
            
            if (at[i] > ct[i-1]) {
                ct[i] = at[i] + bt[i];
            } else {
                ct[i] = ct[i-1] + bt[i];
            }
        }
        
        
        tat[i] = ct[i] - at[i];  // TAT = CT - AT
        wt[i] = tat[i] - bt[i];   // WT = TAT - BT
        
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);

    return 0;
}