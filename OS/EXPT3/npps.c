#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int pri;
    bool completed;
};

void sortByCt(struct process *queue, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (queue[i].ct > queue[j].ct) {
                struct process t = queue[i];
                queue[i] = queue[j];
                queue[j] = t;
            }
        }
    }
}

void printGanttChart(int n, struct process *p) {
    sortByCt(p, n);
    printf("\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt - 1; j++) printf(" ");
        printf("P%d", p[i].id);
        for (int j = 0; j < p[i].bt - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    printf("%d", p[0].at);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) printf("  ");
        printf("%d", p[i].ct);
    }
    printf("\n");
}

void sortByPt(int n, struct process *p) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].pri > p[j].pri || (p[i].pri == p[j].pri && p[i].at > p[j].at)) {
                struct process t = p[j];
                p[j] = p[i];
                p[i] = t;
            }
        }
    }
}

int findNextProcess(int n, struct process *p, int curr_time) {
    int min_priority = INT_MAX; 
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (!p[i].completed && p[i].at <= curr_time) {
            if (p[i].pri < min_priority || (p[i].pri == min_priority && p[i].at < p[idx].at)) {
                min_priority = p[i].pri;
                idx = i;
            }
        }
    }
    return idx;
}

void npps(int n, struct process *p) {
    int curr_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        int idx = findNextProcess(n, p, curr_time);
        if (idx == -1) {
            curr_time++;
        } else {
            p[idx].ct = curr_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = true;

            curr_time = p[idx].ct;
            completed_processes++;
        }
    }
}

void printSolution(int n, struct process* p) {
    printf("Processes\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        printf("Process: %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].pri, p[i].ct, p[i].tat, p[i].wt);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].completed = false;
    }
    printf("Enter the arrival times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i].at);
    }
    printf("Enter the burst times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
    }
    printf("Enter the priority: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i].pri);
    }
    npps(n, p);
    printSolution(n, p);
    printGanttChart(n, p);
    free(p);
    return 0;
}

/*
OUTPUT:
Enter the number of processes: 4
Enter the arrival times: 0 1 2 3
Enter the burst times: 4 3 1 2
Enter the priority: 2 1 4 3
Processes       Arrival Time    Burst Time      Priority        Completion Time Turnaround Time Waiting Time
Process: 1              0               4               2               4               4               0
Process: 2              1               3               1               10              9               6
Process: 3              2               1               4               5               3               2
Process: 4              3               2               3               7               4               2

Gantt Chart:
 -------- -- ---- ------ 
|   P1   |P3| P4 |  P2  |
 -------- -- ---- ------ 
0        4  5    7      10
*/