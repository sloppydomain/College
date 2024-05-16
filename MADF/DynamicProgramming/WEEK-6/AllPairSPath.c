/*
    Author - Yash Malviya
    Title - All Pair Shortest Paths (Floyd-Warshall)
*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

void printa(int **a, bool **c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == INT_MAX)
                printf("INF\t");
            else if(c[i][j])
                printf("[%d]\t", a[i][j]);
            else
                printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void printp(int **p, bool **c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                printf("-\t");
            else if(c[i][j])
                printf("[%d]\t", p[i][j]);
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}

void printPaths(int **p, int i, int j){
    if(p[i][j] == i)
        return;
    else{
        printPaths(p, i, p[i][j]);
    }
    printf("%d -> ", p[i][j]);
}

void apsp(int **cost, int **a, int **p, int n)
{
    bool **c = (bool **)malloc((n + 1) * sizeof(bool*));
    for(int i = 1; i <= n; i++){
        c[i] = (bool *)malloc(n * sizeof(bool));
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            c[i][j] = false;
        }
    }
    printf("\n[A^0]:\n");
    printa(a, c, n);
    printf("\n[P^0]:\n");
    printp(p, c, n);
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((a[i][k] != INT_MAX && a[k][j] != INT_MAX) && a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = p[k][j];
                    c[i][j] = true;
                }
            }
        }
        printf("\n[A^%d]:\n", k);
        printa(a, c, n);
        printf("\n[P^%d]:\n", k);
        printp(p, c, n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                c[i][j] = false;
            }
        }
    }
    printf("Shortest distances between every pair of vertices: \n\n[A^%d]:\n", n);
    printa(a, c, n);
    printf("\nSource\t   Destination\t      Length\t\t\tPath\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j){
                printf("%d\t\t%d\t\t%d\t\t", i, j, a[i][j]);
                printf("%d -> ", i);
                printPaths(p, i, j);
                printf("%d\n", j);
            }
        }
    }
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
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INT_MAX;
        }
    }
    int x, b, wt;
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
    }
    int **p = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        p[i] = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                p[i][j] = -1;
            else
                p[i][j] = i;
        }
    }
    int **a = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        a[i] = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = cost[i][j];
        }
    }
    apsp(cost, a, p, n);
    for (int i = 0; i <= n; i++)
        free(cost[i]);
    free(cost);
    return 0;
}

/*
OUTPUT:
Enter the number of vertices : 5
Enter Edges (-1 -1 to Quit) : 
1 2 8
1 3 3
1 5 -4
2 1 2
2 3 -2
2 4 4
2 5 7
3 2 2
3 4 6
4 1 -2
4 3 -5
4 5 -2
5 4 6
5 1 6
-1 -1 -1

[A^0]:
0       8       3       INF     -4
2       0       -2      4       7
INF     2       0       6       INF
-2      INF     -5      0       -2
6       INF     INF     6       0

[P^0]:
-       1       1       1       1
2       -       2       2       2
3       3       -       3       3
4       4       4       -       4
5       5       5       5       -

[A^1]:
0       8       3       INF     -4
2       0       -2      4       [-2]
INF     2       0       6       INF
-2      [6]     -5      0       [-6]
6       [14]    [9]     6       0

[P^1]:
-       1       1       1       1
2       -       2       2       [1]
3       3       -       3       3
4       [1]     4       -       [1]
5       [1]     [1]     5       -

[A^2]:
0       8       3       [12]    -4
2       0       -2      4       -2
[4]     2       0       6       [0]
-2      6       -5      0       -6
6       14      9       6       0

[P^2]:
-       1       1       [2]     1
2       -       2       2       1
[2]     3       -       3       [1]
4       1       4       -       1
5       1       1       5       -

[A^3]:
0       [5]     3       [9]     -4
2       0       -2      4       -2
4       2       0       6       0
-2      [-3]    -5      0       -6
6       [11]    9       6       0

[P^3]:
-       [3]     1       [3]     1
2       -       2       2       1
2       3       -       3       1
4       [3]     4       -       1
5       [3]     1       5       -

[A^4]:
0       5       3       9       -4
2       0       -2      4       -2
4       2       0       6       0
-2      -3      -5      0       -6
[4]     [3]     [1]     6       0

[P^4]:
-       3       1       3       1
2       -       2       2       1
2       3       -       3       1
4       3       4       -       1
[4]     [3]     [4]     5       -

[A^5]:
0       [-1]    [-3]    [2]     -4
2       0       -2      4       -2
4       2       0       6       0
-2      -3      -5      0       -6
4       3       1       6       0

[P^5]:
-       [3]     [4]     [5]     1
2       -       2       2       1
2       3       -       3       1
4       3       4       -       1
4       3       4       5       -
Shortest distances between every pair of vertices:

[A^5]:
0       -1      -3      2       -4
2       0       -2      4       -2
4       2       0       6       0
-2      -3      -5      0       -6
4       3       1       6       0

Source     Destination        Length                    Path
1               2               -1              1 -> 5 -> 4 -> 3 -> 2
1               3               -3              1 -> 5 -> 4 -> 3
1               4               2               1 -> 5 -> 4
1               5               -4              1 -> 5
2               1               2               2 -> 1
2               3               -2              2 -> 3
2               4               4               2 -> 4
2               5               -2              2 -> 1 -> 5
3               1               4               3 -> 2 -> 1
3               2               2               3 -> 2
3               4               6               3 -> 4
3               5               0               3 -> 2 -> 1 -> 5
4               1               -2              4 -> 1
4               2               -3              4 -> 3 -> 2
4               3               -5              4 -> 3
4               5               -6              4 -> 1 -> 5
5               1               4               5 -> 4 -> 1
5               2               3               5 -> 4 -> 3 -> 2
5               3               1               5 -> 4 -> 3
5               4               6               5 -> 4
*/