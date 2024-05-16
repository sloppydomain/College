/*
    author - Yash Malviya
    title - Hamiltonian Cycle
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define nline printf("\n")

int solutionCount = 1;
int solutionCount_ = 1;
int sol[100][100];
int sol_[100][100];

void insert(int *a, int n) {
    for(int i = 1; i <= n; i++) {
        sol[solutionCount][i] = a[i];
    }
    sol[solutionCount][n + 1] = a[1];
}

void insert_(int *a, int n) {
    for(int i = 1; i <= n; i++) {
        sol_[solutionCount_][i] = a[i];
    }
    sol_[solutionCount_][n + 1] = a[1];
}

bool check(int *a, int n) {
    for(int i = 1; i <= solutionCount; i++) {
        int s = 0;
        bool ok1 = false, ok2 = false;
        for(int j = 1; j <= n; j++) {
            if(sol[i][j] == a[1]) {
                s = j;
                break;
            } 
        }
        int s1 = (s == n ? 1 : s + 1);
        for(int j = 2; j <= n; j++) {
            if(a[j] != sol[i][s1]) {
                ok1 = true;
                break;
            }
            s1 = (s1 == n ? 1 : s1 + 1);
        }
        int s2 = (s == 1 ? n : s - 1);
        for(int j = 2; j <= n; j++) {
            if(a[j] != sol[i][s2]) {
                ok2 = true;
                break;
            }
            s2 = (s2 == 1 ? n : s2 - 1);
        }
        if(!ok1 || !ok2) {
            return false;
        }
    }
    return true;
}

int lc = 0;
void printSolution(int *path, int x, int n, bool ok){
    if(ok) {
        nline;
    }
    printf("Leaf Node %d: [", ++lc);
    for(int i = 1; i <= n; i++){
        printf("%d", path[i]);
        if(i != n){
            printf(" -> ");
        }
    }
    if(x != -1){
        printf(" -> %d] %s", x, (ok ? "Solution" : "Bound"));
    }
    else{
        printf("] Bound");
    }
    nline;
}

void nextValue(int n, int k, bool **graph, int *x){
    while(1){
        x[k] = (x[k] + 1) % (n + 1);
        if(x[k] == 0){
            return;
        }
        if(graph[x[k - 1]][x[k]]){
            bool ok = false;
            for(int i = 1; i <= k - 1; i++){
                if(x[i] == x[k]){
                    ok = true;
                    break;
                }
            }
            if(ok && x[1] == 1){
                printSolution(x, -1, k, false);
            }
            if(!ok){
                // if(k < n && graph[x[k]][x[1]]){
                //     printSolution(x, x[1], k, false);
                // }
                if(k < n || (k == n && graph[x[n]][x[1]])){
                    return;
                }
            }
        }
    }
}

void hamiltonian(bool **graph, int *x, int k, int n){
    while(1){
        nextValue(n, k, graph, x);
        if(x[k] == 0){
            return;
        }
        if(k == n){
            bool ok = false;
            if(check(x, n)) {
                insert(x, n);
                solutionCount++;
                ok = true;
            }
            insert_(x, n);
            solutionCount_++;
            if(x[1] == 1) {
                printSolution(x, x[1], n, ok);
                nline;
            }
        }
        else{
            hamiltonian(graph, x, k + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    bool **graph = (bool **)malloc((n + 1) * sizeof(bool *));
    for (int i = 0; i <= n; i++)
        graph[i] = (bool *)malloc((n + 1) * sizeof(bool));
    int mxEdges = n * (n - 1);                              // Directed Graph...
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            graph[i][j] = false;
        }
    }
    int a, b;
    printf("Enter the edges: \n");
    for (int i = 1; i <= mxEdges; i++){
        // printf("Enter Edge %d (-1 -1 to Quit) : ", i);
        // printf("\nEnter Source: ");
        scanf("%d", &a);
        // printf("Enter Destination : ");
        scanf("%d", &b);
        if (a == -1 || b == -1)
            break;
        else if (a <= 0 || a > n || b <= 0 || b > n){
            printf("Invalid Input. Vertices are numbered from 1 to %d\n", n);
            i--;
            continue;
        }
        else if(a == b){
            printf("Vertex cannot have a self loop...\n");
            i--;
            continue;
        }
        graph[a][b] = true;
        graph[b][a] = true;
    }
    int *path = (int *)malloc((n + 1) * sizeof(int));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            path[j] = 0;
        }
        path[1] = i;
        if(i == 1) {
            printf("\nLeaf Nodes starting with vertex %d:\n", i);
        }
        hamiltonian(graph, path, 2, n);
        lc = 0;
    }
    int l = -1;
    printf("\n\nTotal Solutions: %d", --solutionCount_);
    for(int i = 1; i <= solutionCount_; i++) {
        nline;
        if(l != sol_[i][1]) {
            printf("\nSolutions for vertex %d:\n", sol_[i][1]);
            l = sol_[i][1];
        }
        printf("Solution %d: ", i);
        printf("[");
        for(int j = 1; j <= n; j++) {
            printf("%d", sol_[i][j]);
            if(j != n) {
                printf(" -> ");
            }
        }
        printf(" -> %d]", sol_[i][1]);
    }
    printf("\n\nTotal Unique Solutions: %d", --solutionCount);
    for(int i = 1; i <= solutionCount; i++) {
        nline;
        printf("Solution %d: ", i);
        printf("[");
        for(int j = 1; j <= n; j++) {
            printf("%d", sol[i][j]);
            if(j != n) {
                printf(" -> ");
            }
        }
        printf(" -> %d]", sol[i][1]);
    }
    free(graph);
    for(int i = 0; i <= n; i++){
        free(graph[i]);
    }
    free(path);
    return 0;   
}

/*
OUTPUT:
Enter the number of nodes: 8
Enter the edges:
1 2
1 4
1 3
2 6
2 8
3 4
3 5
4 6
5 6
5 7
6 8
7 8
-1 -1

Leaf Nodes starting with vertex 1:
Leaf Node 1: [1 -> 2 -> 1] Bound
Leaf Node 2: [1 -> 2 -> 6 -> 2] Bound
Leaf Node 3: [1 -> 2 -> 6 -> 4 -> 1] Bound
Leaf Node 4: [1 -> 2 -> 6 -> 4 -> 3 -> 1] Bound
Leaf Node 5: [1 -> 2 -> 6 -> 4 -> 3 -> 4] Bound
Leaf Node 6: [1 -> 2 -> 6 -> 4 -> 3 -> 5 -> 3] Bound
Leaf Node 7: [1 -> 2 -> 6 -> 4 -> 3 -> 5 -> 6] Bound
Leaf Node 8: [1 -> 2 -> 6 -> 4 -> 3 -> 5 -> 7 -> 5] Bound
Leaf Node 9: [1 -> 2 -> 6 -> 4 -> 6] Bound
Leaf Node 10: [1 -> 2 -> 6 -> 5 -> 3 -> 1] Bound
Leaf Node 11: [1 -> 2 -> 6 -> 5 -> 3 -> 4 -> 1] Bound
Leaf Node 12: [1 -> 2 -> 6 -> 5 -> 3 -> 4 -> 3] Bound
Leaf Node 13: [1 -> 2 -> 6 -> 5 -> 3 -> 4 -> 6] Bound
Leaf Node 14: [1 -> 2 -> 6 -> 5 -> 3 -> 5] Bound
Leaf Node 15: [1 -> 2 -> 6 -> 5 -> 6] Bound
Leaf Node 16: [1 -> 2 -> 6 -> 5 -> 7 -> 5] Bound
Leaf Node 17: [1 -> 2 -> 6 -> 5 -> 7 -> 8 -> 2] Bound
Leaf Node 18: [1 -> 2 -> 6 -> 5 -> 7 -> 8 -> 6] Bound
Leaf Node 19: [1 -> 2 -> 6 -> 5 -> 7 -> 8 -> 7] Bound
Leaf Node 20: [1 -> 2 -> 6 -> 8 -> 2] Bound
Leaf Node 21: [1 -> 2 -> 6 -> 8 -> 6] Bound
Leaf Node 22: [1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 3 -> 1] Bound

Leaf Node 23: [1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 3 -> 4 -> 1] Solution

Leaf Node 24: [1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 3 -> 5] Bound
Leaf Node 25: [1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 6] Bound
Leaf Node 26: [1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 7] Bound
Leaf Node 27: [1 -> 2 -> 6 -> 8 -> 7 -> 8] Bound
Leaf Node 28: [1 -> 2 -> 8 -> 2] Bound
Leaf Node 29: [1 -> 2 -> 8 -> 6 -> 2] Bound
Leaf Node 30: [1 -> 2 -> 8 -> 6 -> 4 -> 1] Bound
Leaf Node 31: [1 -> 2 -> 8 -> 6 -> 4 -> 3 -> 1] Bound
Leaf Node 32: [1 -> 2 -> 8 -> 6 -> 4 -> 3 -> 4] Bound
Leaf Node 33: [1 -> 2 -> 8 -> 6 -> 4 -> 3 -> 5 -> 3] Bound
Leaf Node 34: [1 -> 2 -> 8 -> 6 -> 4 -> 3 -> 5 -> 6] Bound
Leaf Node 35: [1 -> 2 -> 8 -> 6 -> 4 -> 6] Bound
Leaf Node 36: [1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 1] Bound
Leaf Node 37: [1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 4 -> 1] Bound
Leaf Node 38: [1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 4 -> 3] Bound
Leaf Node 39: [1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 4 -> 6] Bound
Leaf Node 40: [1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 5] Bound
Leaf Node 41: [1 -> 2 -> 8 -> 6 -> 5 -> 6] Bound
Leaf Node 42: [1 -> 2 -> 8 -> 6 -> 5 -> 7 -> 5] Bound
Leaf Node 43: [1 -> 2 -> 8 -> 6 -> 5 -> 7 -> 8] Bound
Leaf Node 44: [1 -> 2 -> 8 -> 6 -> 8] Bound
Leaf Node 45: [1 -> 2 -> 8 -> 7 -> 5 -> 3 -> 1] Bound
Leaf Node 46: [1 -> 2 -> 8 -> 7 -> 5 -> 3 -> 4 -> 1] Bound
Leaf Node 47: [1 -> 2 -> 8 -> 7 -> 5 -> 3 -> 4 -> 3] Bound
Leaf Node 48: [1 -> 2 -> 8 -> 7 -> 5 -> 3 -> 5] Bound
Leaf Node 49: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 2] Bound
Leaf Node 50: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 4 -> 1] Bound

Leaf Node 51: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 4 -> 3 -> 1] Solution

Leaf Node 52: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 4 -> 6] Bound
Leaf Node 53: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 5] Bound
Leaf Node 54: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 8] Bound
Leaf Node 55: [1 -> 2 -> 8 -> 7 -> 5 -> 7] Bound
Leaf Node 56: [1 -> 2 -> 8 -> 7 -> 8] Bound
Leaf Node 57: [1 -> 3 -> 1] Bound
Leaf Node 58: [1 -> 3 -> 4 -> 1] Bound
Leaf Node 59: [1 -> 3 -> 4 -> 3] Bound
Leaf Node 60: [1 -> 3 -> 4 -> 6 -> 2 -> 1] Bound
Leaf Node 61: [1 -> 3 -> 4 -> 6 -> 2 -> 6] Bound
Leaf Node 62: [1 -> 3 -> 4 -> 6 -> 2 -> 8 -> 2] Bound
Leaf Node 63: [1 -> 3 -> 4 -> 6 -> 2 -> 8 -> 6] Bound
Leaf Node 64: [1 -> 3 -> 4 -> 6 -> 2 -> 8 -> 7 -> 8] Bound
Leaf Node 65: [1 -> 3 -> 4 -> 6 -> 4] Bound
Leaf Node 66: [1 -> 3 -> 4 -> 6 -> 5 -> 3] Bound
Leaf Node 67: [1 -> 3 -> 4 -> 6 -> 5 -> 6] Bound
Leaf Node 68: [1 -> 3 -> 4 -> 6 -> 5 -> 7 -> 5] Bound
Leaf Node 69: [1 -> 3 -> 4 -> 6 -> 5 -> 7 -> 8 -> 2 -> 1] Bound

Leaf Node 70: [1 -> 3 -> 4 -> 6 -> 5 -> 7 -> 8 -> 6] Bound
Leaf Node 71: [1 -> 3 -> 4 -> 6 -> 5 -> 7 -> 8 -> 7] Bound
Leaf Node 72: [1 -> 3 -> 4 -> 6 -> 8 -> 2 -> 1] Bound
Leaf Node 73: [1 -> 3 -> 4 -> 6 -> 8 -> 2 -> 6] Bound
Leaf Node 74: [1 -> 3 -> 4 -> 6 -> 8 -> 2 -> 8] Bound
Leaf Node 75: [1 -> 3 -> 4 -> 6 -> 8 -> 6] Bound
Leaf Node 76: [1 -> 3 -> 4 -> 6 -> 8 -> 7 -> 5 -> 3] Bound
Leaf Node 77: [1 -> 3 -> 4 -> 6 -> 8 -> 7 -> 5 -> 6] Bound
Leaf Node 78: [1 -> 3 -> 4 -> 6 -> 8 -> 7 -> 5 -> 7] Bound
Leaf Node 79: [1 -> 3 -> 4 -> 6 -> 8 -> 7 -> 8] Bound
Leaf Node 80: [1 -> 3 -> 5 -> 3] Bound
Leaf Node 81: [1 -> 3 -> 5 -> 6 -> 2 -> 1] Bound
Leaf Node 82: [1 -> 3 -> 5 -> 6 -> 2 -> 6] Bound
Leaf Node 83: [1 -> 3 -> 5 -> 6 -> 2 -> 8 -> 2] Bound
Leaf Node 84: [1 -> 3 -> 5 -> 6 -> 2 -> 8 -> 6] Bound
Leaf Node 85: [1 -> 3 -> 5 -> 6 -> 2 -> 8 -> 7 -> 5] Bound
Leaf Node 86: [1 -> 3 -> 5 -> 6 -> 2 -> 8 -> 7 -> 8] Bound
Leaf Node 87: [1 -> 3 -> 5 -> 6 -> 4 -> 1] Bound
Leaf Node 88: [1 -> 3 -> 5 -> 6 -> 4 -> 3] Bound
Leaf Node 89: [1 -> 3 -> 5 -> 6 -> 4 -> 6] Bound
Leaf Node 90: [1 -> 3 -> 5 -> 6 -> 5] Bound
Leaf Node 91: [1 -> 3 -> 5 -> 6 -> 8 -> 2 -> 1] Bound
Leaf Node 92: [1 -> 3 -> 5 -> 6 -> 8 -> 2 -> 6] Bound
Leaf Node 93: [1 -> 3 -> 5 -> 6 -> 8 -> 2 -> 8] Bound
Leaf Node 94: [1 -> 3 -> 5 -> 6 -> 8 -> 6] Bound
Leaf Node 95: [1 -> 3 -> 5 -> 6 -> 8 -> 7 -> 5] Bound
Leaf Node 96: [1 -> 3 -> 5 -> 6 -> 8 -> 7 -> 8] Bound
Leaf Node 97: [1 -> 3 -> 5 -> 7 -> 5] Bound
Leaf Node 98: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 1] Bound
Leaf Node 99: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 2] Bound

Leaf Node 100: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 4 -> 1] Solution

Leaf Node 101: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 5] Bound
Leaf Node 102: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 8] Bound
Leaf Node 103: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 8] Bound
Leaf Node 104: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 2 -> 1] Bound
Leaf Node 105: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 2 -> 6] Bound
Leaf Node 106: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 2 -> 8] Bound
Leaf Node 107: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 4 -> 1] Bound
Leaf Node 108: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 4 -> 3] Bound
Leaf Node 109: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 4 -> 6] Bound
Leaf Node 110: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 5] Bound
Leaf Node 111: [1 -> 3 -> 5 -> 7 -> 8 -> 6 -> 8] Bound
Leaf Node 112: [1 -> 3 -> 5 -> 7 -> 8 -> 7] Bound
Leaf Node 113: [1 -> 4 -> 1] Bound
Leaf Node 114: [1 -> 4 -> 3 -> 1] Bound
Leaf Node 115: [1 -> 4 -> 3 -> 4] Bound
Leaf Node 116: [1 -> 4 -> 3 -> 5 -> 3] Bound
Leaf Node 117: [1 -> 4 -> 3 -> 5 -> 6 -> 2 -> 1] Bound
Leaf Node 118: [1 -> 4 -> 3 -> 5 -> 6 -> 2 -> 6] Bound
Leaf Node 119: [1 -> 4 -> 3 -> 5 -> 6 -> 2 -> 8 -> 2] Bound
Leaf Node 120: [1 -> 4 -> 3 -> 5 -> 6 -> 2 -> 8 -> 6] Bound
Leaf Node 121: [1 -> 4 -> 3 -> 5 -> 6 -> 4] Bound
Leaf Node 122: [1 -> 4 -> 3 -> 5 -> 6 -> 5] Bound
Leaf Node 123: [1 -> 4 -> 3 -> 5 -> 6 -> 8 -> 2 -> 1] Bound
Leaf Node 124: [1 -> 4 -> 3 -> 5 -> 6 -> 8 -> 2 -> 6] Bound
Leaf Node 125: [1 -> 4 -> 3 -> 5 -> 6 -> 8 -> 2 -> 8] Bound
Leaf Node 126: [1 -> 4 -> 3 -> 5 -> 6 -> 8 -> 6] Bound
Leaf Node 127: [1 -> 4 -> 3 -> 5 -> 6 -> 8 -> 7 -> 5] Bound
Leaf Node 128: [1 -> 4 -> 3 -> 5 -> 6 -> 8 -> 7 -> 8] Bound
Leaf Node 129: [1 -> 4 -> 3 -> 5 -> 7 -> 5] Bound
Leaf Node 130: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 2 -> 1] Bound
Leaf Node 131: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 2 -> 8] Bound
Leaf Node 132: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 6 -> 2 -> 1] Bound

Leaf Node 133: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 6 -> 4] Bound
Leaf Node 134: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 6 -> 5] Bound
Leaf Node 135: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 6 -> 8] Bound
Leaf Node 136: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 7] Bound
Leaf Node 137: [1 -> 4 -> 6 -> 2 -> 1] Bound
Leaf Node 138: [1 -> 4 -> 6 -> 2 -> 6] Bound
Leaf Node 139: [1 -> 4 -> 6 -> 2 -> 8 -> 2] Bound
Leaf Node 140: [1 -> 4 -> 6 -> 2 -> 8 -> 6] Bound
Leaf Node 141: [1 -> 4 -> 6 -> 2 -> 8 -> 7 -> 5 -> 3 -> 1] Bound

Leaf Node 142: [1 -> 4 -> 6 -> 2 -> 8 -> 7 -> 5 -> 6] Bound
Leaf Node 143: [1 -> 4 -> 6 -> 2 -> 8 -> 7 -> 5 -> 7] Bound
Leaf Node 144: [1 -> 4 -> 6 -> 2 -> 8 -> 7 -> 8] Bound
Leaf Node 145: [1 -> 4 -> 6 -> 4] Bound
Leaf Node 146: [1 -> 4 -> 6 -> 5 -> 3 -> 1] Bound
Leaf Node 147: [1 -> 4 -> 6 -> 5 -> 3 -> 4] Bound
Leaf Node 148: [1 -> 4 -> 6 -> 5 -> 3 -> 5] Bound
Leaf Node 149: [1 -> 4 -> 6 -> 5 -> 6] Bound
Leaf Node 150: [1 -> 4 -> 6 -> 5 -> 7 -> 5] Bound
Leaf Node 151: [1 -> 4 -> 6 -> 5 -> 7 -> 8 -> 2 -> 1] Bound
Leaf Node 152: [1 -> 4 -> 6 -> 5 -> 7 -> 8 -> 2 -> 6] Bound
Leaf Node 153: [1 -> 4 -> 6 -> 5 -> 7 -> 8 -> 2 -> 8] Bound
Leaf Node 154: [1 -> 4 -> 6 -> 5 -> 7 -> 8 -> 6] Bound
Leaf Node 155: [1 -> 4 -> 6 -> 5 -> 7 -> 8 -> 7] Bound
Leaf Node 156: [1 -> 4 -> 6 -> 8 -> 2 -> 1] Bound
Leaf Node 157: [1 -> 4 -> 6 -> 8 -> 2 -> 6] Bound
Leaf Node 158: [1 -> 4 -> 6 -> 8 -> 2 -> 8] Bound
Leaf Node 159: [1 -> 4 -> 6 -> 8 -> 6] Bound
Leaf Node 160: [1 -> 4 -> 6 -> 8 -> 7 -> 5 -> 3 -> 1] Bound
Leaf Node 161: [1 -> 4 -> 6 -> 8 -> 7 -> 5 -> 3 -> 4] Bound
Leaf Node 162: [1 -> 4 -> 6 -> 8 -> 7 -> 5 -> 3 -> 5] Bound
Leaf Node 163: [1 -> 4 -> 6 -> 8 -> 7 -> 5 -> 6] Bound
Leaf Node 164: [1 -> 4 -> 6 -> 8 -> 7 -> 5 -> 7] Bound
Leaf Node 165: [1 -> 4 -> 6 -> 8 -> 7 -> 8] Bound


Total Solutions: 48

Solutions for vertex 1:
Solution 1: [1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 3 -> 4 -> 1]
Solution 2: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 4 -> 3 -> 1]
Solution 3: [1 -> 3 -> 4 -> 6 -> 5 -> 7 -> 8 -> 2 -> 1]
Solution 4: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 4 -> 1]
Solution 5: [1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 6 -> 2 -> 1]
Solution 6: [1 -> 4 -> 6 -> 2 -> 8 -> 7 -> 5 -> 3 -> 1]

Solutions for vertex 2:
Solution 7: [2 -> 1 -> 3 -> 4 -> 6 -> 5 -> 7 -> 8 -> 2]
Solution 8: [2 -> 1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 6 -> 2]
Solution 9: [2 -> 6 -> 4 -> 1 -> 3 -> 5 -> 7 -> 8 -> 2]
Solution 10: [2 -> 6 -> 8 -> 7 -> 5 -> 3 -> 4 -> 1 -> 2]
Solution 11: [2 -> 8 -> 7 -> 5 -> 3 -> 1 -> 4 -> 6 -> 2]
Solution 12: [2 -> 8 -> 7 -> 5 -> 6 -> 4 -> 3 -> 1 -> 2]

Solutions for vertex 3:
Solution 13: [3 -> 1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 4 -> 3]
Solution 14: [3 -> 1 -> 4 -> 6 -> 2 -> 8 -> 7 -> 5 -> 3]
Solution 15: [3 -> 4 -> 1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 3]
Solution 16: [3 -> 4 -> 6 -> 5 -> 7 -> 8 -> 2 -> 1 -> 3]
Solution 17: [3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 4 -> 1 -> 3]
Solution 18: [3 -> 5 -> 7 -> 8 -> 6 -> 2 -> 1 -> 4 -> 3]

Solutions for vertex 4:
Solution 19: [4 -> 1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 3 -> 4]
Solution 20: [4 -> 1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 4]
Solution 21: [4 -> 3 -> 1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 4]
Solution 22: [4 -> 3 -> 5 -> 7 -> 8 -> 6 -> 2 -> 1 -> 4]
Solution 23: [4 -> 6 -> 2 -> 8 -> 7 -> 5 -> 3 -> 1 -> 4]
Solution 24: [4 -> 6 -> 5 -> 7 -> 8 -> 2 -> 1 -> 3 -> 4]

Solutions for vertex 5:
Solution 25: [5 -> 3 -> 1 -> 4 -> 6 -> 2 -> 8 -> 7 -> 5]
Solution 26: [5 -> 3 -> 4 -> 1 -> 2 -> 6 -> 8 -> 7 -> 5]
Solution 27: [5 -> 6 -> 4 -> 3 -> 1 -> 2 -> 8 -> 7 -> 5]
Solution 28: [5 -> 7 -> 8 -> 2 -> 1 -> 3 -> 4 -> 6 -> 5]
Solution 29: [5 -> 7 -> 8 -> 2 -> 6 -> 4 -> 1 -> 3 -> 5]
Solution 30: [5 -> 7 -> 8 -> 6 -> 2 -> 1 -> 4 -> 3 -> 5]

Solutions for vertex 6:
Solution 31: [6 -> 2 -> 1 -> 4 -> 3 -> 5 -> 7 -> 8 -> 6]
Solution 32: [6 -> 2 -> 8 -> 7 -> 5 -> 3 -> 1 -> 4 -> 6]
Solution 33: [6 -> 4 -> 1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6]
Solution 34: [6 -> 4 -> 3 -> 1 -> 2 -> 8 -> 7 -> 5 -> 6]
Solution 35: [6 -> 5 -> 7 -> 8 -> 2 -> 1 -> 3 -> 4 -> 6]
Solution 36: [6 -> 8 -> 7 -> 5 -> 3 -> 4 -> 1 -> 2 -> 6]

Solutions for vertex 7:
Solution 37: [7 -> 5 -> 3 -> 1 -> 4 -> 6 -> 2 -> 8 -> 7]
Solution 38: [7 -> 5 -> 3 -> 4 -> 1 -> 2 -> 6 -> 8 -> 7]
Solution 39: [7 -> 5 -> 6 -> 4 -> 3 -> 1 -> 2 -> 8 -> 7]
Solution 40: [7 -> 8 -> 2 -> 1 -> 3 -> 4 -> 6 -> 5 -> 7]
Solution 41: [7 -> 8 -> 2 -> 6 -> 4 -> 1 -> 3 -> 5 -> 7]
Solution 42: [7 -> 8 -> 6 -> 2 -> 1 -> 4 -> 3 -> 5 -> 7]

Solutions for vertex 8:
Solution 43: [8 -> 2 -> 1 -> 3 -> 4 -> 6 -> 5 -> 7 -> 8]
Solution 44: [8 -> 2 -> 6 -> 4 -> 1 -> 3 -> 5 -> 7 -> 8]
Solution 45: [8 -> 6 -> 2 -> 1 -> 4 -> 3 -> 5 -> 7 -> 8]
Solution 46: [8 -> 7 -> 5 -> 3 -> 1 -> 4 -> 6 -> 2 -> 8]
Solution 47: [8 -> 7 -> 5 -> 3 -> 4 -> 1 -> 2 -> 6 -> 8]
Solution 48: [8 -> 7 -> 5 -> 6 -> 4 -> 3 -> 1 -> 2 -> 8]

Total Unique Solutions: 3
Solution 1: [1 -> 2 -> 6 -> 8 -> 7 -> 5 -> 3 -> 4 -> 1]
Solution 2: [1 -> 2 -> 8 -> 7 -> 5 -> 6 -> 4 -> 3 -> 1]
Solution 3: [1 -> 3 -> 5 -> 7 -> 8 -> 2 -> 6 -> 4 -> 1]
*/