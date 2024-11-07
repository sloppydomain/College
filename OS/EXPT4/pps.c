#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
const int N = 1e5 + 5;

struct process {
    int id;
    int at;   
    int bt;   
    int ct;   
    int tat;  
    int wt; 
    int rt; 
    int priority;
    bool completed;
};

struct ganttchart {
    int idx;
    int ct;
};

// void sortByBt(struct process *queue, int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (queue[i].bt > queue[j].bt || (queue[i].bt == queue[j].bt && queue[i].idx > queue[j].idx)) {
//                 struct process t = queue[j];
//                 queue[j] = queue[i];
//                 queue[i] = t;
//             }
//         }
//     }
// }

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

void sortByAt(int n, struct process *p) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at || (p[i].at == p[j].at && p[i].bt > p[j].bt)) {
                struct process t = p[j];
                p[j] = p[i];
                p[i] = t;
            }
        }
    }
}

void printSol(int n, struct process *p) {
    printf("Processes\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("Process: %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

// void printGanttChart(int n, struct ganttchart *p, struct process* fine) {
//     sortByCt(fine, n);
//     printf("\nGantt Chart:\n");
//     printf(" ");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < p[i].ct; j++) printf("--");
//         printf(" ");
//     }
//     printf("\n|");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < p[i].ct - 1; j++) printf(" ");
//         printf("P%d", p[i].idx);
//         for (int j = 0; j < p[i].ct - 1; j++) printf(" ");
//         printf("|");
//     }
//     printf("\n ");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < p[i].ct; j++) printf("--");
//         printf(" ");
//     }
//     printf("\n");
//     sortByAt(n, fine);
//     printf("%d", fine[0].at);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < p[i].ct; j++) printf("  ");
//         printf("%d", p[i].ct);
//     }
//     printf("\n");
// }

void printGanttChart(int n, struct ganttchart *p, struct process* fine) {
    sortByCt(fine, n);
    printf("\nGantt Chart:\n");
    printf(" ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].ct; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].ct - 1; j++) printf(" ");
        printf("P%d", p[i].idx);
        for (int j = 0; j < p[i].ct - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].ct; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    sortByAt(n, fine);
    printf("%d", fine[0].at);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].ct; j++) printf("  ");
        printf("%d", p[i].ct);
    }
    printf("\n");
}

void pps(int n, struct process* p) {
    sortByAt(n, p);
    struct ganttchart g[N];
    int cnt = 0, curr = 0;
    int k = -1, previ = -1;
    while(cnt < n) {
        int idx = -1;
        int max_pt = -1;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= curr && p[i].priority > max_pt) {
                max_pt = p[i].priority;
                idx = i;
            }
        }
        if(idx == -1) {
            curr += 1;
            continue;
        }
        p[idx].rt -= 1;
        curr += 1;
        if (p[idx].rt == 0) {
            p[idx].completed = true;
            if(previ != idx) {
                k += 1;
            }
            g[k].idx = p[idx].id;
            g[k].ct = curr;
            cnt += 1;
            previ = idx;
            p[idx].ct = curr;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        } else if(previ == idx) {
            g[k].idx = p[idx].id;
            g[k].ct = curr;
        } else if(previ != idx) {
            k += 1;
            g[k].idx = p[idx].id;
            g[k].ct = curr;
            previ = idx;
        }
    }
    printf("\n\n");
    printSol(n, p);
    printGanttChart(k + 1, g, p);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].completed = false;
    }
    printf("Enter the priority: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].priority);
    }
    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].at);
    }
    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }
    pps(n, p);
    free(p);
    return 0;
}

/*
OUTPUT:
Enter the number of processes: 5
Enter the priority: 3 2 4 6 10
Enter the arrival times: 0 1 2 3 5
Enter the burst times: 3 4 6 4 2


Processes       Arrival Time    Burst Time      Completion Time Turnaround Time Waiting Time
Process: 1              0               3               15              15              12
Process: 2              1               4               19              18              14
Process: 3              2               6               14              12              6
Process: 4              3               4               9               6               2
Process: 5              5               2               7               2               0

Gantt Chart:
 ---- ------ ---------- -------------- ------------------ ---------------------------- ------------------------------ -------------------------------------- 
| P1 |  P3  |    P4    |      P5      |        P4        |             P3             |              P1              |                  P2                  |
 ---- ------ ---------- -------------- ------------------ ---------------------------- ------------------------------ -------------------------------------- 
0    2      3          5              7                  9                            14                              15                                      19
*/