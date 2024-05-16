/*
    author - Yash Malviya
    title - Bellman Ford Algorithm
*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#define line printf("\n-------------------------------------------------------------------------")

void findPath(int n, int s, int d, int *pred)
{
    int cnt = 0;
    int *path = (int *)malloc(n * sizeof(int));
    int u;
    while (s != d)
    {
        path[cnt] = d;
        u = pred[d];
        d = u;
        cnt++;
    }
    path[cnt] = s;
    for (int i = cnt; i >= 0; i--)
    {
        printf("%d", path[i]);
        if (i != 0)
            printf(" -> ");
    }
    printf("\n");
}

void print1(int **c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (c[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}

void print2(int *d, int v){
    printf("\nVertex\tDistance from source\n");
    for(int i = 1; i <= v; i++){
        printf("%d\t\t%3d\n", i, d[i]);
    }
}

void print3(int *pred, int *p, int n, int s)
{
    printf("\nSource To Destination\tDistance\tPath\n");
    for (int i = 1; i <= n; i++)
    {
        if (s == i)
            continue;
        printf("\t%d to %d\t\t   %3d\t\t", s, i, p[i]);
        findPath(n, s, i, pred);
    }
}

bool incoming(int **cost, int u, int v){
    for(int i = 1; i <= v; i++){
        if(i != u && cost[i][u] != INT_MAX)
            return true;
    }
    return false;
}

void bellmanFord(int **cost, int EdgeCount, int n, int src){
    int *prev = (int *)malloc(sizeof(int) * (n + 1));
    int *curr = (int *)malloc(sizeof(int) * (n + 1));
    int *pred = (int *)malloc(sizeof(int) * (n + 1));
    bool *c = (bool *)malloc((n + 1) * sizeof(bool));
    for(int i = 1; i <= n; i++){
        prev[i] = INT_MAX;
        curr[i] = INT_MAX;
        c[i] = false;
        pred[i] = -1;
    }
    prev[src] = 0;
    curr[src] = 0;
    c[src] = true;
    for(int i = 1; i <= n - 1; i++){    // Atleat one edge is relaxed in one iteration if edges are randomly taken
        for(int v = 1; v <= n; v++){
            if(v != src && incoming(cost, v, n)){
                curr[v] = prev[v];
                for(int u = 1; u <= n; u++){
                    if(cost[u][v] != INT_MAX && prev[u] != INT_MAX){
                        if(curr[v] > prev[u] + cost[u][v]){
                            curr[v] = prev[u] + cost[u][v];
                            pred[v] = u;
                            c[v] = true;
                        }
                    }
                }
            }
        }
        printf("\n");
        line;
        printf("\nk = %d:\n", i);
        printf("\t\t");
        for(int i = 1; i <= n; i++){
            printf("[%d]\t", i);
        }
        printf("\nDist  :\t\t");
        for(int i = 1; i <= n; i++){
            if(curr[i] == INT_MAX)
                printf("INF\t");
            else if(c[i])   
                printf("[%d]\t", curr[i]);
            else    
                printf("%d\t", curr[i]);
        }
        printf("\n(U, I):\t\t");
        for(int i = 1; i <= n; i++){
            if(c[i])
                printf("(%d, %d)\t", i, pred[i]);
            else
                printf("\t");
        }
        printf("\nPred  :\t\t");
        for(int i = 1; i <= n; i++){
            if(c[i])
                printf("[%d]\t", pred[i]);
            else
                printf("%d\t", pred[i]);
        }
        int *t = curr;
        curr = prev;
        prev = t;
        for(int i = 1; i <= n; i++){
            c[i] = false;
        }
    }
    line;
    for(int i = 1; i <= n - 1; i++){                  
        for(int v = 1; v <= n; v++){
            if(v != src && incoming(cost, v, n)){
                for(int u = 1; u <= n; u++){
                    if(cost[u][v] != INT_MAX && prev[u] != INT_MAX){
                        if(prev[v] > prev[u] + cost[u][v]){
                            printf("Graph contains negative weight cycle...\n");
                            return;
                        }
                    }
                }
            }
        }
    }
    printf("\n\nGraph is correct. No Negative Cycle detected...\n");
    print2(prev, n);
    printf("\n");
    print3(pred, prev, n, src);
}
int main()
{
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    int **cost = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        cost[i] = (int *)malloc((n + 1) * sizeof(int));
    int mxEdges = n * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++){
            cost[i][j] = INT_MAX;
        }
    }
    int x, b, wt, EdgeCnt = 0;
    printf("Enter Edges (-1 -1 to Quit) : \n");
    for (int i = 1; i <= mxEdges; i++)
    {
        // printf("\nEnter Source: ");
        scanf("%d", &x);
        // printf("Enter Destination : ");
        scanf("%d", &b);
        scanf("%d", &wt);
        if (x == -1 || b == -1)
            break;
        else if (x <= 0 || x > n || b <= 0 || b > n)
        {
            printf("Invalid Input. Vertices are numbered from 1 to %d\n", n);
            i--;
            continue;
        }
        // printf("Enter Weight : ");
        cost[x][b] = wt;
        EdgeCnt++;
    }
    int s;
    printf("Enter Source Vertex: ");
    scanf("%d", &s);
    bellmanFord(cost, EdgeCnt, n, s);
    for (int i = 0; i <= n; i++)
        free(cost[i]);
    free(cost);
    return 0;
}
/*
OUTPUT:
Enter the number of vertices : 7
Enter Edges (-1 -1 to Quit) : 
1 2 4
1 4 7
1 5 -3
1 7 4
2 1 6
2 3 -2
2 4 6
2 6 1
3 1 4
3 2 3
3 5 1
3 6 4
4 1 3
4 3 3
4 6 5
4 7 5
5 2 4
5 4 2
6 1 -1
6 2 2
6 3 -2
6 5 -2
6 7 1
7 4 6
7 5 -2
7 6 -1
-1 -1 -1
Enter Source Vertex: 1


-------------------------------------------------------------------------
k = 1:
                [1]     [2]     [3]     [4]     [5]     [6]     [7]
Dist  :         [0]     [4]     INF     [7]     [-3]    INF     [4]
(U, I):         (1, -1) (2, 1)          (4, 1)  (5, 1)          (7, 1)
Pred  :         [-1]    [1]     -1      [1]     [1]     -1      [1]

-------------------------------------------------------------------------
k = 2:
                [1]     [2]     [3]     [4]     [5]     [6]     [7]
Dist  :         0       [1]     [2]     [-1]    -3      [3]     4
(U, I):                 (2, 5)  (3, 2)  (4, 5)          (6, 7)
Pred  :         -1      [5]     [2]     [5]     1       [7]     1

-------------------------------------------------------------------------
k = 3:
                [1]     [2]     [3]     [4]     [5]     [6]     [7]
Dist  :         0       1       [-1]    -1      -3      [2]     4
(U, I):                         (3, 2)                  (6, 2)
Pred  :         -1      5       [2]     5       1       [2]     1

-------------------------------------------------------------------------
k = 4:
                [1]     [2]     [3]     [4]     [5]     [6]     [7]
Dist  :         0       1       -1      -1      -3      2       [3]
(U, I):                                                         (7, 6)
Pred  :         -1      5       2       5       1       2       [6]

-------------------------------------------------------------------------
k = 5:
                [1]     [2]     [3]     [4]     [5]     [6]     [7]
Dist  :         0       1       -1      -1      -3      2       3
(U, I):
Pred  :         -1      5       2       5       1       2       6

-------------------------------------------------------------------------
k = 6:
                [1]     [2]     [3]     [4]     [5]     [6]     [7]
Dist  :         0       1       -1      -1      -3      2       3
(U, I):
Pred  :         -1      5       2       5       1       2       6
-------------------------------------------------------------------------

Graph is correct. No Negative Cycle detected...

Vertex  Distance from source
1                 0
2                 1
3                -1
4                -1
5                -3
6                 2
7                 3


Source To Destination   Distance        Path
        1 to 2               1          1 -> 5 -> 2
        1 to 3              -1          1 -> 5 -> 2 -> 3
        1 to 4              -1          1 -> 5 -> 4
        1 to 5              -3          1 -> 5
        1 to 6               2          1 -> 5 -> 2 -> 6
        1 to 7               3          1 -> 5 -> 2 -> 6 -> 7
*/