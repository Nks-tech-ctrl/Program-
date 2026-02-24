#include <stdio.h>

int main() {
    int n, i, temp_n, time = 0, qt, rem_bt[20], wt[20], tat[20], bt[20];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    temp_n = n; 

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Keep track of remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &qt);

    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for(i = 0; temp_n != 0;) {
        if(rem_bt[i] <= qt && rem_bt[i] > 0) {
            time += rem_bt[i];
            rem_bt[i] = 0;
            temp_n--; // Process finished
            
            tat[i] = time;
            wt[i] = tat[i] - bt[i];
            printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
            awt += wt[i];
            atat += tat[i];
        } 
        else if(rem_bt[i] > 0) {
            rem_bt[i] -= qt;
            time += qt;
        }

        if(i == n - 1) i = 0; // Loop back to start
        else i++;
    }

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);

    return 0;
}