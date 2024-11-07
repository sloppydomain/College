#include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void printGanttChart(int n, struct process *p) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", p[i].id);
    }
    printf("|\n%d", p[0].at);
    for (int i = 0; i < n; i++) {
        printf("   %d", p[i].ct);
    }
    printf("\n");
}

void printSol(int n, struct process *p) {
    printf("Processes\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        printf("Process: %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printGanttChart(n, p);
}

void sort(int n, struct process *p) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].at > p[j].at) {
                struct process t = p[j];
                p[j] = p[i];
                p[i] = t;
            }
        }
    }
}

void fcfs(int n, struct process *p) {
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;
    int w = p[0].wt;
    int ct = p[0].ct;
    int it = 0; 
    for(int i = 1; i < n; i++) {
        if(ct >= p[i].at) {
            p[i].ct = ct + p[i].bt;
            ct = p[i].ct;
        } else {
            it += (p[i].at - ct);
            ct = p[i].at;
            p[i].ct = ct + p[i].bt;
            ct = p[i].ct;
        }
        p[i].tat = p[i].ct - p[i].at;
        if(p[i].tat - p[i].bt > 0) {
            w = p[i].tat - p[i].bt;
        }
        p[i].wt = w;
    }
    printf("Total Idle-Time: %d\n", it);
    printSol(n, p);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
    }
    int at[n];
    printf("Enter the arrival times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i].at);
    }
    printf("Enter the burst times: ");
    int bt[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
    }
    sort(n, p);
    fcfs(n, p);
    return 0;
}