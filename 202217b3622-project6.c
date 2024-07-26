#include <stdio.h>

void calculate_average_times(int n, int a[], int b[], float *awt, float *att) {
    int g[n], w[n], t[n], i;

    // Initialize completion time for the first process
    g[0] = 0;

    // Calculate completion times for all processes
    for (i = 1; i < n; i++) {
        g[i] = g[i - 1] + b[i - 1];
    }

    // Calculate waiting times and turnaround times
    for (i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
    }

    // Calculate average waiting time and average turnaround time
    *awt = 0.0;
    *att = 0.0;
    for (i = 0; i < n; i++) {
        *awt += w[i];
        *att += t[i];
    }
    *awt /= n;
    *att /= n;
}

int main() {
    int n, i;
    float awt, att;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int a[n], b[n];  // Arrays to store arrival and burst times

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    calculate_average_times(n, a, b, &awt, &att);

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", i, a[i], b[i]);
    }

    printf("\nAverage waiting time = %.2f\n", awt);
    printf("Average turnaround time = %.2f\n", att);

    return 0;
}
