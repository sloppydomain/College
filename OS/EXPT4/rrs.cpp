#include <stdio.h>
#include <stdlib.h>

struct node {
    char pname;
    int btime;
    int atime;
    int restime;
    int ctime;
    int wtime;
} a[100], b[100], c[100];

void insert(int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf(" %c", &a[i].pname);
        scanf("%d", &a[i].atime);
        scanf("%d", &a[i].btime);
        a[i].wtime = -a[i].atime;
    }
}

int btimeSort(const void *x, const void *y) {
    return ((struct node *)x)->btime - ((struct node *)y)->btime;
}

int atimeSort(const void *x, const void *y) {
    return ((struct node *)x)->atime - ((struct node *)y)->atime;
}

int k = 0, f = 0, r = 0;

void disp(int nop, int qt) {
    int n = nop, q;
    qsort(a, n, sizeof(struct node), atimeSort);
    int ttime = 0, i;
    int j, tArray[n];
    int alltime = 0;
    int moveLast = 0;
    for (i = 0; i < n; i++) {
        alltime += a[i].btime;
    }
    alltime += a[0].atime;
    for (i = 0; ttime <= alltime;) {
        j = i;
        while (a[j].atime <= ttime && j != n) {
            b[r] = a[j];
            j++;
            r++;
        }
        if (r == f) {
            c[k].pname = 'i';
            c[k].btime = a[j].atime - ttime;
            c[k].atime = ttime;
            ttime += c[k].btime;
            k++;
            continue;
        }
        i = j;
        if (moveLast == 1) {
            b[r] = b[f];
            f++;
            r++;
        }
        j = f;
        if (b[j].btime > qt) {
            c[k] = b[j];
            c[k].btime = qt;
            k++;
            b[j].btime -= qt;
            ttime += qt;
            moveLast = 1;
            for (q = 0; q < n; q++) {
                if (b[j].pname != a[q].pname) {
                    a[q].wtime += qt;
                }
            }
        } else {
            c[k] = b[j];
            k++;
            f++;
            ttime += b[j].btime;
            moveLast = 0;
            for (q = 0; q < n; q++) {
                if (b[j].pname != a[q].pname) {
                    a[q].wtime += b[j].btime;
                }
            }
        }
        if (f == r && i >= n)
            break;
    }
    tArray[i] = ttime;
    ttime += a[i].btime;
    int rtime = 0;
    for (j = 0; j < n && j < 6; j++) {
        rtime = 0;
        for (i = 0; i < k; i++) {
            if (c[i].pname == a[j].pname) {
                a[j].restime = rtime;
                break;
            }
            rtime += c[i].btime;
        }
    }
    float averageWaitingTime = 0;
    float averageResponseTime = 0;
    float averageTAT = 0;
    printf("\nGantt Chart\n");
    rtime = 0;
    for (i = 0; i < k + 1 && i < 20; i++) {
        if (i != k)
            printf("|   %c   ", c[i].pname);
        rtime += c[i].btime;
        for (j = 0; j < 6; j++) {
            if (a[j].pname == c[i].pname)
                a[j].ctime = rtime;
        }
    }
    printf("|\n");
    rtime = 0;
    for (i = 0; i < k + 1 && i < 20; i++) {
        printf("%d\t", rtime);
        tArray[i] = rtime;
        rtime += c[i].btime;
    }
    printf("\n");
    printf("\n");
    printf("P.Name  AT\tBT\tCT\tTAT\tWT\t\n");
    for (i = 0; i < 6 && i < nop && a[i].pname != 'i'; i++) {
        if (a[i].pname == '\0')
            break;
        printf("%c\t", a[i].pname);
        printf("%d\t", a[i].atime);
        printf("%d\t", a[i].btime);
        printf("%d\t", a[i].ctime);
        printf("%d\t", a[i].wtime + a[i].ctime - rtime + a[i].btime);
        averageTAT += a[i].wtime + a[i].ctime - rtime + a[i].btime;
        printf("%d\t", a[i].wtime + a[i].ctime - rtime);
        averageWaitingTime += a[i].wtime + a[i].ctime - rtime;
        averageResponseTime += a[i].restime - a[i].atime;
        printf("\n");
    }
    printf("Average Waiting time: %.2f\n", averageWaitingTime / n);
    printf("Average TA time: %.2f\n", averageTAT / n);
}

int main() {
    int nop, qt;
    printf("Enter number of processes: ");
    scanf("%d", &nop);
    printf("Enter time quantum: ");
    scanf("%d", &qt);
    insert(nop);
    disp(nop, qt);
    return 0;
}
/*
OUTPUT:
Enter number of processes: 4
Enter time quantum: 2
1 0 5
2 1 4
3 2 2
4 4 1

Gantt Chart
|   1   |   2   |   3   |   1   |   4   |   2   |   1   |
0       2       4       6       8       9       11      12

P.Name  AT      BT      CT      TAT     WT
1       0       5       12      12      7
2       1       4       11      10      6
3       2       2       6       4       2
4       4       1       9       5       4
Average Waiting time: 4.75
Average TA time: 7.75
*/