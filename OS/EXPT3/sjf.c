#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process {
    int id;
    int at;   
    int bt;   
    int ct;   
    int tat;  
    int wt;   
    bool vis; 
    int idx;  
};

void sortByBt(struct process *queue, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (queue[i].bt > queue[j].bt || (queue[i].bt == queue[j].bt && queue[i].idx > queue[j].idx)) {
                struct process t = queue[j];
                queue[j] = queue[i];
                queue[i] = t;
            }
        }
    }
}

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

void printQ(int n, struct process *p) {
    printf("Processes\tArrival Time\tBurst Time\tIndex\n");
    for (int i = 0; i < n; i++) {
        printf("Process: %d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].idx);
    }
}

void printSol(int n, struct process *p) {
    printf("Processes\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("Process: %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printGanttChart(n, p);
}

void sort(int n, struct process *p) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct process t = p[j];
                p[j] = p[i];
                p[i] = t;
            }
        }
    }
}

void sjf(int n, struct process *p) {
    struct process queue[n];
    int q_size = 0;
    int r = p[0].at;
    for (int i = 0; i < n; i++) {
        if (p[i].at <= r) {
            queue[q_size++] = p[i];
            p[i].vis = true;
        }
    }
    sortByBt(queue, q_size);
    int idx = 0;
    while (idx < n) {
        struct process curr = queue[0];
        for (int i = 0; i < q_size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        q_size--;
        int i = curr.idx;
        p[i].ct = r + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        r = p[i].ct;
        for (int j = 0; j < n; j++) {
            if (!p[j].vis && p[j].at <= r) {
                queue[q_size++] = p[j];
                p[j].vis = true;
            }
        }
        sortByBt(queue, q_size);
        idx++;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].vis = false;
    }
    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].at);
    }
    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
    }
    sort(n, p);
    for (int i = 0; i < n; i++) {
        p[i].idx = i;
    }
    sjf(n, p);
    printf("\n\n");
    printSol(n, p);
    free(p);
    return 0;
}

/*
OUTPUT:
Enter the number of processes: 4
Enter the arrival times: 0 2 4 5
Enter the burst times: 7 4 1 4


Processes       Arrival Time    Burst Time      Completion Time Turnaround Time Waiting Time
Process: 1              0               7               7               7               0
Process: 2              2               4               12              10              6
Process: 3              4               1               8               4               3
Process: 4              5               4               16              11              7

Gantt Chart:
 -------------- -- -------- -------- 
|      P1      |P3|   P2   |   P4   |
 -------------- -- -------- -------- 
0              7  8        12        16


CONCLUSION - Shortest Job First (SJF) Scheduling Algorithm code was studied and implemented in C and Gantt chart
was displayed along with turnaround time, waiting time, average waiting time and average
turnaround time.
*/