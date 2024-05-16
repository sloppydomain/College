/*
    author - Yash Malviya
    title - Single Source Shortest Path Algorithm (Dijkstra's Algo)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
struct path
{
    int *p;
    int n;
};
void display_cost(int **cost, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}
void display1(int **q, int *p, int n, int s, int t, struct path a[])
{
    printf("\nSource To Destination\tDistance\tPath\n");
    for (int i = 1; i <= n; i++)
    {
        if (s == i)
            continue;
        printf("\t%d to %d\t\t   %d\t\t", s, i, p[i]);
        for (int j = 1; j <= a[i].n; j++)
        {
            printf("%d", a[i].p[j]);
            if (j != a[i].n)
                printf(" -> ");
            else
                printf("\n");
        }
        printf("\n");
    }
}
void display2(bool *status, int *dist, int n, int s, int v)
{
    static int u = 0;
    printf("\nIteration %d : u = %d\nStatus : \n", ++u, v);
    for (int i = 1; i <= n; i++)
    {
        if (status[i])
        {
            if (i == v)
                printf("[ status[%d] = true ]", i);
            else
                printf("status[%d] = true", i);
        }
        else if (!status[i])
            printf("status[%d] = false", i);
        if (i != n)
            printf(", ");
        else
            printf("\n");
    }
    printf("Distances of all vertices from source %d : \n", s);
    for (int i = 1; i <= n; i++)
    {
        if (i == v)
            printf("[ Distance[%d] = %d ]", i, dist[i]);
        else if (dist[i] == INT_MAX)
            printf("Distance[%d] = INF", i);
        else
            printf("Distance[%d] = %d", i, dist[i]);
        if (i != n)
            printf(", ");
    }
    printf("\n");
}
int minv(int *dist, bool *status, int n)
{
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < min && status[i] == false)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int **cost, int *dist, int s, int n, struct path a[])
{
    bool *status = (bool *)malloc((n + 1) * sizeof(bool));
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
        status[i] = false;
    }
    dist[s] = 0;
    for (int j = 1; j <= n; j++)
    {
        int v = minv(dist, status, n);
        if (v == -1)
            return;
        status[v] = true;
        for (int u = 1; u <= n; u++)
        {
            int cnt = a[v].n;
            if (!status[u] && cost[v][u] != INT_MAX && dist[v] != INT_MAX && (dist[v] + cost[v][u]) < dist[u])
            {
                dist[u] = dist[v] + cost[v][u];
                cnt++;
                for (int i = 1; i <= a[v].n; i++)
                    a[u].p[i] = a[v].p[i];
                a[u].p[cnt] = u;
                a[u].n = cnt;
            }
        }
        display2(status, dist, n, s, v);
    }
}
int main()
{
    int n, s;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    int near[n];
    int **cost = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++)
        cost[i] = (int *)malloc((n + 1) * sizeof(int));
    int mxEdges = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INT_MAX;
        }
    }
    int *dist = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= mxEdges; i++)
    {
        int a, b, wt;
        printf("Enter Edge %d (-1 -1 to Quit) : ", i);
        printf("\nEnter Source: ");
        scanf("%d", &a);
        printf("Enter Destination : ");
        scanf("%d", &b);
        if (a == -1 || b == -1)
            break;
        else if (a > n || b > n || a <= 0 || b <= 0)
        {
            printf("Invalid Input. %d Vertices are numbered from 1 to %d\n", n, n);
            i--;
            continue;
        }
        printf("Enter Weight : ");
        scanf("%d", &wt);
        cost[a][b] = wt;
    }
    printf("\nCost Matrix: \n");
    display_cost(cost, n);
    printf("Enter source : ");
    scanf("%d", &s);
    struct path a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i].p = (int *)malloc((n + 1) * sizeof(int));
        a[i].p[1] = s;
        a[i].n = 1;
    }
    dijkstra(cost, dist, s, n, a);
    display1(cost, dist, n, s, 2, a);
    return 0;
}

/*
OUTPUT:
Enter the number of vertices : 6
Enter Edge 1 (-1 -1 to Quit) : 
Enter Source: 1
Enter Destination : 2
Enter Weight : 12
Enter Edge 2 (-1 -1 to Quit) : 
Enter Source: 1
Enter Destination : 3
Enter Weight : 5
Enter Edge 3 (-1 -1 to Quit) : 
Enter Source: 2
Enter Destination : 4
Enter Weight : 2
Enter Edge 4 (-1 -1 to Quit) :
Enter Source: 2
Enter Destination : 5
Enter Weight : 6
Enter Edge 5 (-1 -1 to Quit) :
Enter Source: 3
Enter Destination : 4
Enter Weight : 5
Enter Edge 6 (-1 -1 to Quit) :
Enter Source: 3
Enter Destination : 2
Enter Weight : 6
Enter Edge 7 (-1 -1 to Quit) :
Enter Source: 3
Enter Destination : 5
Enter Weight : 25
Enter Edge 8 (-1 -1 to Quit) :
Enter Source: 4
Enter Destination : 5
Enter Weight : 14
Enter Edge 9 (-1 -1 to Quit) :
Enter Source: 4
Enter Destination : 6
Enter Weight : 12
Enter Edge 10 (-1 -1 to Quit) :
Enter Source: 5
Enter Destination : 6 
Enter Weight : 6
Enter Edge 11 (-1 -1 to Quit) :
Enter Source: -1
Enter Destination : -1

Cost Matrix:
INF     12      5       INF     INF     INF
INF     INF     INF     2       6       INF
INF     6       INF     5       25      INF
INF     INF     INF     INF     14      12
INF     INF     INF     INF     INF     6
INF     INF     INF     INF     INF     INF
Enter source : 1

Iteration 1 : u = 1
Status :
[ status[1] = true ], status[2] = false, status[3] = false, status[4] = false, status[5] = false, status[6] = false
Distances of all vertices from source 1 :
[ Distance[1] = 0 ], Distance[2] = 12, Distance[3] = 5, Distance[4] = INF, Distance[5] = INF, Distance[6] = INF

Iteration 2 : u = 3
Status :
status[1] = true, status[2] = false, [ status[3] = true ], status[4] = false, status[5] = false, status[6] = false
Distances of all vertices from source 1 :
Distance[1] = 0, Distance[2] = 11, [ Distance[3] = 5 ], Distance[4] = 10, Distance[5] = 30, Distance[6] = INF

Iteration 3 : u = 4
Status :
status[1] = true, status[2] = false, status[3] = true, [ status[4] = true ], status[5] = false, status[6] = false
Distances of all vertices from source 1 :
Distance[1] = 0, Distance[2] = 11, Distance[3] = 5, [ Distance[4] = 10 ], Distance[5] = 24, Distance[6] = 22

Iteration 4 : u = 2
Status :
status[1] = true, [ status[2] = true ], status[3] = true, status[4] = true, status[5] = false, status[6] = false
Distances of all vertices from source 1 :
Distance[1] = 0, [ Distance[2] = 11 ], Distance[3] = 5, Distance[4] = 10, Distance[5] = 17, Distance[6] = 22

Iteration 5 : u = 5
Status :
status[1] = true, status[2] = true, status[3] = true, status[4] = true, [ status[5] = true ], status[6] = false
Distances of all vertices from source 1 :
Distance[1] = 0, Distance[2] = 11, Distance[3] = 5, Distance[4] = 10, [ Distance[5] = 17 ], Distance[6] = 22

Iteration 6 : u = 6
Status :
status[1] = true, status[2] = true, status[3] = true, status[4] = true, status[5] = true, [ status[6] = true ]
Distances of all vertices from source 1 :
Distance[1] = 0, Distance[2] = 11, Distance[3] = 5, Distance[4] = 10, Distance[5] = 17, [ Distance[6] = 22 ]

Source To Destination   Distance        Path
        1 to 2             11           1 -> 3 -> 2

        1 to 3             5            1 -> 3

        1 to 4             10           1 -> 3 -> 4

        1 to 5             17           1 -> 3 -> 2 -> 5

        1 to 6             22           1 -> 3 -> 4 -> 6
        

CONCLUSION - Greedy Method was studied .The Programs for Prim's, Kruskal's and single source shortest path algorithms were successfully studied and implemented.
*/