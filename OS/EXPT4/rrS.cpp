#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

struct process {
    int id;
    int at;   
    int bt;   
    int ct;   
    int tat;  
    int wt; 
    int rt; 
    bool completed;
};

struct process ganttchart {
    int start;
    int end;
    int idx;
};

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

void printGanttChart(int n, struct ganttchart *p, struct process* fine) {
    sortByCt(fine, n);
    printSol(n, fine);
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    struct process p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i].at;
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i].bt;
    }
    int tq;
    cin >> tq;
    int curr = 0;
    int k = 0;
    int g = 0;
    struct process gant[N];
    queue<pair<int, int>> rq;
    vector<bool> inrq(n, false);
    while(k < n) {
        if(queue.empty()) {
            curr = p[k].at;
            for(int i = 0; i < n; i++) {
                if(p[i].at <= curr && !p[i].completed && !inrq[i]) {
                    rq.push({i, p[i].rt});
                    inrq[i] = true;
                }
            }
        }
        pair<int, int> f = rq.front();
        rq.pop();
        int idx = f.first;
        int rem = f.second;
        if(rem > tq) {
            gant[g].start = curr;
            rem -= tq;
            curr += tq;
            for(int i = 0; i < n; i++) {
                if(p[i].at <= curr && !p[i].completed && !inrq[i]) {
                    rq.push({i, p[i].rt});
                    inrq[i] = true;
                }
            }
            gant[g].end = curr;
            gant[g].idx = idx;
            p[i].tc
            rq.push({idx, rem});
            g += 1;
        } else {
            gant[g].start = curr
            rem = 0;
            curr += rem;
            for(int i = 0; i < n; i++) {
                if(p[i].at <= curr && !p[i].completed && !inrq[i]) {
                    rq.push({i, p[i].rt});
                    inrq[i] = true;
                }
            }
            p[idx].completed = true;
            gant[g].end = curr;
            gant[g].idx = idx;
            g += 1;
            k++;
        }
    }
    return 0;
}