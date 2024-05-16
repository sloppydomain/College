/*
    author - Yash Malviya
    title - Graph Colouring
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define nline printf("\n")

int max(int a, int b){
    return (a > b ? a : b);
}

int min(int a, int b){
    return (a < b ? a : b);
}

int c = 0;
int minC = 0;
int node = 0;

void printSolution(int *x, int n, bool ok){
    if(node == 0){
        printf("Node %d: Root Node\n", ++node);
    }
    printf("Leaf Node %d: ", ++node);
    for(int i = 1; i <= n; i++){
        printf("x[%d] = %d%s", i, x[i], (i != n ? ", " : "  "));
    }
    if(!ok) {
        printf("(Bound)");
    } else {
        printf(" (Solution)");
    }
    nline;
}

void nextValue(int k, int n, int m, bool **g, int *x){
    while(1){
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0){
            return;
        }
        int j;
        for(j = 1; j <= n; j++){
            if(g[k][j] && x[k] == x[j]){
                printSolution(x, k, false);
                break;
            }
        }
        if(j == n + 1){
            return;
        }
    }
}

void mColouring(int k, int n, int *m, bool **g, int *x){
    while(1){
        nextValue(k, n, (*m), g, x);
        if(x[k] == 0){
            return;
        }
        if(k == n){
            printf("\nSolution %d: ", ++c);
            printSolution(x, k, true);
            nline;
            if(c == 1){
                int *f = (int *)malloc(((*m) + 1) * sizeof(int));
                for(int i = 1; i <= (*m); i++){
                    f[i] = 0;
                }
                for(int i = 1; i <= n; i++){
                    f[x[i]]++;
                }
                for(int i = 1; i <= (*m); i++){
                    if(f[i]){
                        minC++;
                    }
                }
                (*m) = minC;
            }
        }
        else{
            mColouring(k + 1, n, m, g, x);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    bool **g = (bool **)malloc((n + 1) * sizeof(bool *));
    for (int i = 0; i <= n; i++)
        g[i] = (bool *)malloc((n + 1) * sizeof(bool));
    int mxEdges = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            g[i][j] = false;
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
        g[a][b] = true;
        g[b][a] = true;
    }
    int maxC = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(g[i][j]){
                cnt++;
            }
        }
        maxC = max(maxC, cnt);
    }
    printf("\nDegree of Graph: %d\n", maxC);
    // printf("Enter the number of colours: ");
    // scanf("%d", &m);
    int *x = (int *)malloc((n + 1) * sizeof(int)); 
    for(int i = 0; i <= n; i++){
        x[i] = 0;
    }
    nline;
    mColouring(1, n, &maxC, g, x);
    printf("\nTotal solutions: %d\nChromatic Number: %d\n", c, minC);
    free(g);
    for(int i = 0; i <= n; i++){
        free(g[i]);
    }
    free(x);
    return 0;   
}

/*
OUTPUT:
Enter the number of vertices : 9
Enter the edges:
1 2
1 4
1 3
2 4
2 5
2 6
3 4
3 5
3 7
4 5
5 6
5 7
5 8
6 8
6 9
7 8
8 9
-1 -1

Degree of Graph: 6

Node 1: Root Node
Leaf Node 2: x[1] = 1, x[2] = 1  (Bound)
Leaf Node 3: x[1] = 1, x[2] = 2, x[3] = 1  (Bound)
Leaf Node 4: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 1  (Bound)
Leaf Node 5: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 2  (Bound)
Leaf Node 6: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 1  (Bound)
Leaf Node 7: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 2  (Bound)
Leaf Node 8: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 3, x[7] = 1  (Bound)
Leaf Node 9: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 3, x[7] = 2  (Bound)
Leaf Node 10: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 3, x[7] = 3, x[8] = 1  (Bound)

Solution 1: Leaf Node 11: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 3, x[7] = 3, x[8] = 2, x[9] = 1   (Solution)

Leaf Node 12: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 3, x[7] = 3, x[8] = 2, x[9] = 2  (Bound)
Leaf Node 13: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 3, x[7] = 3, x[8] = 2, x[9] = 3  (Bound)
Leaf Node 14: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 1, x[6] = 3, x[7] = 3, x[8] = 3  (Bound)
Leaf Node 15: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 2  (Bound)
Leaf Node 16: x[1] = 1, x[2] = 2, x[3] = 2, x[4] = 3, x[5] = 3  (Bound)
Leaf Node 17: x[1] = 1, x[2] = 2, x[3] = 3, x[4] = 1  (Bound)
Leaf Node 18: x[1] = 1, x[2] = 2, x[3] = 3, x[4] = 2  (Bound)
Leaf Node 19: x[1] = 1, x[2] = 2, x[3] = 3, x[4] = 3  (Bound)
Leaf Node 20: x[1] = 1, x[2] = 3, x[3] = 1  (Bound)
Leaf Node 21: x[1] = 1, x[2] = 3, x[3] = 2, x[4] = 1  (Bound)
Leaf Node 22: x[1] = 1, x[2] = 3, x[3] = 2, x[4] = 2  (Bound)
Leaf Node 23: x[1] = 1, x[2] = 3, x[3] = 2, x[4] = 3  (Bound)
Leaf Node 24: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 1  (Bound)
Leaf Node 25: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 1  (Bound)
Leaf Node 26: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 2, x[7] = 1  (Bound)
Leaf Node 27: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 2, x[7] = 2, x[8] = 1  (Bound)
Leaf Node 28: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 2, x[7] = 2, x[8] = 2  (Bound)

Solution 2: Leaf Node 29: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 2, x[7] = 2, x[8] = 3, x[9] = 1   (Solution)

Leaf Node 30: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 2, x[7] = 2, x[8] = 3, x[9] = 2  (Bound)
Leaf Node 31: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 2, x[7] = 2, x[8] = 3, x[9] = 3  (Bound)
Leaf Node 32: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 2, x[7] = 3  (Bound)
Leaf Node 33: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 1, x[6] = 3  (Bound)
Leaf Node 34: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 2  (Bound)
Leaf Node 35: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 2, x[5] = 3  (Bound)
Leaf Node 36: x[1] = 1, x[2] = 3, x[3] = 3, x[4] = 3  (Bound)
Leaf Node 37: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 1  (Bound)
Leaf Node 38: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 2  (Bound)
Leaf Node 39: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 1  (Bound)
Leaf Node 40: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 1  (Bound)
Leaf Node 41: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 2  (Bound)
Leaf Node 42: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 3, x[7] = 1  (Bound)
Leaf Node 43: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 3, x[7] = 2  (Bound)
Leaf Node 44: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 3, x[7] = 3, x[8] = 1, x[9] = 1  (Bound)

Solution 3: Leaf Node 45: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 3, x[7] = 3, x[8] = 1, x[9] = 2   (Solution)

Leaf Node 46: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 3, x[7] = 3, x[8] = 1, x[9] = 3  (Bound)
Leaf Node 47: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 3, x[7] = 3, x[8] = 2  (Bound)
Leaf Node 48: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 2, x[6] = 3, x[7] = 3, x[8] = 3  (Bound)
Leaf Node 49: x[1] = 2, x[2] = 1, x[3] = 1, x[4] = 3, x[5] = 3  (Bound)
Leaf Node 50: x[1] = 2, x[2] = 1, x[3] = 2  (Bound)
Leaf Node 51: x[1] = 2, x[2] = 1, x[3] = 3, x[4] = 1  (Bound)
Leaf Node 52: x[1] = 2, x[2] = 1, x[3] = 3, x[4] = 2  (Bound)
Leaf Node 53: x[1] = 2, x[2] = 1, x[3] = 3, x[4] = 3  (Bound)
Leaf Node 54: x[1] = 2, x[2] = 2  (Bound)
Leaf Node 55: x[1] = 2, x[2] = 3, x[3] = 1, x[4] = 1  (Bound)
Leaf Node 56: x[1] = 2, x[2] = 3, x[3] = 1, x[4] = 2  (Bound)
Leaf Node 57: x[1] = 2, x[2] = 3, x[3] = 1, x[4] = 3  (Bound)
Leaf Node 58: x[1] = 2, x[2] = 3, x[3] = 2  (Bound)
Leaf Node 59: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 1  (Bound)
Leaf Node 60: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 1, x[7] = 1, x[8] = 1  (Bound)
Leaf Node 61: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 1, x[7] = 1, x[8] = 2  (Bound)
Leaf Node 62: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 1, x[7] = 1, x[8] = 3, x[9] = 1  (Bound)

Solution 4: Leaf Node 63: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 1, x[7] = 1, x[8] = 3, x[9] = 2   (Solution)

Leaf Node 64: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 1, x[7] = 1, x[8] = 3, x[9] = 3  (Bound)
Leaf Node 65: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 1, x[7] = 2  (Bound)
Leaf Node 66: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 1, x[7] = 3  (Bound)
Leaf Node 67: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 2  (Bound)
Leaf Node 68: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 2, x[6] = 3  (Bound)
Leaf Node 69: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 1, x[5] = 3  (Bound)
Leaf Node 70: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 2  (Bound)
Leaf Node 71: x[1] = 2, x[2] = 3, x[3] = 3, x[4] = 3  (Bound)
Leaf Node 72: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 1  (Bound)
Leaf Node 73: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 1  (Bound)
Leaf Node 74: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 2  (Bound)
Leaf Node 75: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 1  (Bound)
Leaf Node 76: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 2, x[7] = 1  (Bound)
Leaf Node 77: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 2, x[7] = 2, x[8] = 1, x[9] = 1  (Bound)
Leaf Node 78: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 2, x[7] = 2, x[8] = 1, x[9] = 2  (Bound)

Solution 5: Leaf Node 79: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 2, x[7] = 2, x[8] = 1, x[9] = 3   (Solution)

Leaf Node 80: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 2, x[7] = 2, x[8] = 2  (Bound)
Leaf Node 81: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 2, x[7] = 2, x[8] = 3  (Bound)
Leaf Node 82: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 2, x[7] = 3  (Bound)
Leaf Node 83: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 2, x[5] = 3, x[6] = 3  (Bound)
Leaf Node 84: x[1] = 3, x[2] = 1, x[3] = 1, x[4] = 3  (Bound)
Leaf Node 85: x[1] = 3, x[2] = 1, x[3] = 2, x[4] = 1  (Bound)
Leaf Node 86: x[1] = 3, x[2] = 1, x[3] = 2, x[4] = 2  (Bound)
Leaf Node 87: x[1] = 3, x[2] = 1, x[3] = 2, x[4] = 3  (Bound)
Leaf Node 88: x[1] = 3, x[2] = 1, x[3] = 3  (Bound)
Leaf Node 89: x[1] = 3, x[2] = 2, x[3] = 1, x[4] = 1  (Bound)
Leaf Node 90: x[1] = 3, x[2] = 2, x[3] = 1, x[4] = 2  (Bound)
Leaf Node 91: x[1] = 3, x[2] = 2, x[3] = 1, x[4] = 3  (Bound)
Leaf Node 92: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 1  (Bound)
Leaf Node 93: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 2  (Bound)
Leaf Node 94: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 1, x[7] = 1, x[8] = 1  (Bound)
Leaf Node 95: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 1, x[7] = 1, x[8] = 2, x[9] = 1  (Bound)
Leaf Node 96: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 1, x[7] = 1, x[8] = 2, x[9] = 2  (Bound)

Solution 6: Leaf Node 97: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 1, x[7] = 1, x[8] = 2, x[9] = 3   (Solution)

Leaf Node 98: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 1, x[7] = 1, x[8] = 3  (Bound)
Leaf Node 99: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 1, x[7] = 2  (Bound)
Leaf Node 100: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 1, x[7] = 3  (Bound)
Leaf Node 101: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 2  (Bound)
Leaf Node 102: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 1, x[5] = 3, x[6] = 3  (Bound)
Leaf Node 103: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 2  (Bound)
Leaf Node 104: x[1] = 3, x[2] = 2, x[3] = 2, x[4] = 3  (Bound)
Leaf Node 105: x[1] = 3, x[2] = 2, x[3] = 3  (Bound)
Leaf Node 106: x[1] = 3, x[2] = 3  (Bound)

Total solutions: 6
Chromatic Number: 3
*/