/*
    author - Yash Malviya
    title - Kruskal's Algorithm
*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

void Display1(int **a, int n)
{
    printf("\nCost Matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == INT_MAX)
                printf(" INF ");
            else
                printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void restoreDown(int *a, int i, int n)
{
    int l = 2 * i;
    int r = l + 1;
    int num = a[i];
    while (l <= n)
    {
        int minChild;
        if (r <= n && a[r] < a[l])
            minChild = r;
        else
            minChild = l;

        if (num <= a[minChild])
            break;

        a[i] = a[minChild];
        i = minChild;
        l = 2 * i;
        r = l + 1;
    }
    a[i] = num;
}

int del_min(int *a, int *n)
{
    int min = a[1];
    a[1] = a[*n];
    (*n)--;
    restoreDown(a, 1, *n);
    return min;
}

void heapify(int *a, int n)
{
    for (int i = n / 2; i >= 1; i--)
        restoreDown(a, i, n);
}

int findParent(int *parent, int u)
{
    while (parent[u] != -1)
        u = parent[u];
    return u;
}
void unionNodes(int *parent, int u, int v)
{
    parent[u] = v;
}

int kruskal(int **cost, int n, int **t, int *a, int m)
{
    int *parent = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
        parent[i] = -1;
    bool **status = (bool **)malloc((n + 1) * sizeof(bool *));
    for (int i = 1; i <= n; i++)
        status[i] = (bool *)malloc((n + 1) * sizeof(bool));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            status[i][j] = false;
    }
    int i = 1;
    int mincost = 0;
    while (i <= n - 1 && m > 0)
    {
        heapify(a, m);
        int min = del_min(a, &m);
        // printf("Minimum Weight %d = %d", i, min);
        int u = -1, v = -1;
        int tcost = 0;
        for (int l = 1; l <= n; l++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[l][j] != INT_MAX && cost[l][j] == min && !status[l][j])
                {
                    u = l;
                    v = j;
                    status[l][j] = true;
                    status[j][l] = true;
                    break;
                }
            }
            if (u != -1 && v != -1)
                break;
        }
        if (u == -1 || v == -1)
        {
            printf("\nNo spanning Tree... u = %d and v = %d\n", u, v);
            return -1;
        }
        int j = findParent(parent, u);
        int k = findParent(parent, v);
        if (j != k)
        {
            t[i][1] = u;
            t[i][2] = v;
            mincost = mincost + cost[u][v];
            unionNodes(parent, j, k);
            printf("Parent : [");
            for (int q = 1; q <= n; q++)
                printf("%d ", parent[q]);
            printf("]\nThe Edge is [%d -> %d]\n", u, v);
            printf("Step %d MST: \n", i);
            printf("Source\tDestination\n");
            for (int q = 1; q <= i; q++)
                printf("%d\t\t%d\n", t[q][1], t[q][2]);
            printf("Mincost = %d\n", mincost);
            i++;
        }
        printf("\n");
    }
    if (i != n)
        printf("No spanning Tree...\n");
    else
        return mincost;
}

int main()
{
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    int **cost = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        cost[i] = (int *)malloc((n + 1) * sizeof(int));
    int mxEdges = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INT_MAX;
        }
    }
    int *a = (int *)malloc((mxEdges + 1) * sizeof(int));
    int edgeCount = 0;
    int x, b, wt;
    for (int i = 1; i <= mxEdges; i++)
    {
        printf("Enter Edge %d (-1 -1 to Quit) : ", i);
        printf("\nEnter Source: ");
        scanf("%d", &x);
        printf("Enter Destination : ");
        scanf("%d", &b);
        if (x == -1 || b == -1)
            break;
        else if (x <= 0 || x > n || b <= 0 || b > n)
        {
            printf("Invalid Input. Vertices are numbered from 1 to %d\n", n);
            i--;
            continue;
        }
        printf("Enter Weight : ");
        scanf("%d", &wt);
        cost[x][b] = wt;
        cost[b][x] = wt;
        a[i] = wt;
        edgeCount++;
    }
    Display1(cost, n);
    int **t = (int **)malloc(n * sizeof(int *));
    for (int i = 1; i <= n - 1; i++)
        t[i] = (int *)malloc(3 * sizeof(int));
    int min_cost = kruskal(cost, n, t, a, edgeCount);
    printf("\nEdges in Spanning tree are : ");
    printf("\nSource\tDestination\tWeight\n");
    for (int i = 1; i <= n - 1; i++)
    {
        printf("%4d\t\t%d\t%5d\n", t[i][1], t[i][2], cost[t[i][1]][t[i][2]]);
    }
    printf("\nMinimum Cost : %d", min_cost);
    free(a);
    for (int i = 0; i <= n; i++)
        free(cost[i]);
    free(cost);
    for (int i = 0; i <= n - 1; i++)
        free(t[i]);
    free(t);
    return 0;
}

/*
OUTPUT:
Enter the number of vertices : 8
Enter Edge 1 (-1 -1 to Quit) :
Enter Source: 1
Enter Destination : 2
Enter Weight : 2
Enter Edge 2 (-1 -1 to Quit) :
Enter Source: 1
Enter Destination : 3
Enter Weight : 2
Enter Edge 3 (-1 -1 to Quit) :
Enter Source: 1
Enter Destination : 4
Enter Weight : 1
Enter Edge 4 (-1 -1 to Quit) :
Enter Source: 1
Enter Destination : 5
Enter Weight : 1
Enter Edge 5 (-1 -1 to Quit) :
Enter Source: 2
Enter Destination : 3
Enter Weight : 2
Enter Edge 6 (-1 -1 to Quit) :
Enter Source: 2
Enter Destination : 4
Enter Weight : 1
Enter Edge 7 (-1 -1 to Quit) :
Enter Source: 3
Enter Destination : 4
Enter Weight : 3
Enter Edge 8 (-1 -1 to Quit) :
Enter Source: 3
Enter Destination : 6
Enter Weight : 2
Enter Edge 9 (-1 -1 to Quit) :
Enter Source: 4
Enter Destination : 8
Enter Weight : 1
Enter Edge 10 (-1 -1 to Quit) :
Enter Source: 5
Enter Destination : 6
Enter Weight : 1
Enter Edge 11 (-1 -1 to Quit) :
Enter Source: 5
Enter Destination : 7
Enter Weight : 3
Enter Edge 12 (-1 -1 to Quit) :
Enter Source: 6
Enter Destination : 7
Enter Weight : 2
Enter Edge 13 (-1 -1 to Quit) :
Enter Source: 6
Enter Destination : 8
Enter Weight : 3
Enter Edge 14 (-1 -1 to Quit) :
Enter Source: 7
Enter Destination : 8
Enter Weight : 1
Enter Edge 15 (-1 -1 to Quit) :
Enter Source: -1
Enter Destination : -1

Cost Matrix:
 INF   2   2   1   1  INF  INF  INF
  2  INF   2   1  INF  INF  INF  INF
  2   2  INF   3  INF   2  INF  INF
  1   1   3  INF  INF  INF  INF   1
  1  INF  INF  INF  INF   1   3  INF
 INF  INF   2  INF   1  INF   2   3
 INF  INF  INF  INF   3   2  INF   1
 INF  INF  INF   1  INF   3   1  INF

Parent : [4 -1 -1 -1 -1 -1 -1 -1 ]
The Edge is [1 -> 4]
Step 1 MST:
Source  Destination
1               4
Mincost = 1

Parent : [4 -1 -1 5 -1 -1 -1 -1 ]
The Edge is [1 -> 5]
Step 2 MST:
Source  Destination
1               4
1               5
Mincost = 2

Parent : [4 5 -1 5 -1 -1 -1 -1 ]
The Edge is [2 -> 4]
Step 3 MST:
Source  Destination
1               4
1               5
2               4
Mincost = 3

Parent : [4 5 -1 5 8 -1 -1 -1 ]
The Edge is [4 -> 8]
Step 4 MST:
Source  Destination
1               4
1               5
2               4
4               8
Mincost = 4

Parent : [4 5 -1 5 8 -1 -1 6 ]
The Edge is [5 -> 6]
Step 5 MST:
Source  Destination
1               4
1               5
2               4
4               8
5               6
Mincost = 5

Parent : [4 5 -1 5 8 -1 6 6 ]
The Edge is [7 -> 8]
Step 6 MST:
Source  Destination
1               4
1               5
2               4
4               8
5               6
7               8
Mincost = 6


Parent : [4 5 -1 5 8 3 6 6 ]
The Edge is [1 -> 3]
Step 7 MST:
Source  Destination
1               4
1               5
2               4
4               8
5               6
7               8
1               3
Mincost = 8


Edges in Spanning tree are :
Source  Destination     Weight
   1            4           1
   1            5           1
   2            4           1
   4            8           1
   5            6           1
   7            8           1
   1            3           2

Minimum Cost : 8
*/