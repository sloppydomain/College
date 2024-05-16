/*
    author - Yash Malviya
    title  - Forward Graph
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void display_c(int **c, int n)
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

void FGraph(int **c, int k, int n, int *p)
{
    int *cost = (int *)malloc((n + 1) * sizeof(int));
    int *d = (int *)malloc((n + 1) * sizeof(int));
    int *s = (int *)malloc((n + 1) * sizeof(int));
    int *a = (int *)malloc((n + 1) * sizeof(int));
    for(int i = 0; i <= n; i++){
        a[i] = -1;
    }
    s[n] = k;
    cost[n] = 0;
    printf("\nStage - %d:\n\tCost[%d, %d]:\tmin{%d}\n\t\t\t= %d", s[n], s[n], n, cost[n], cost[n]);
    for (int i = n - 1; i >= 1; i--)
    {
        cost[i] = INT_MAX;
        int r;
        int l = 0;
        int min;
        for (int j = i + 1; j <= n; j++)
        {
            if (c[i][j] != INT_MAX)
            {
                s[i] = s[j] - 1;
                bool ok = false;
                if (c[i][j] + cost[j] < cost[i])
                {
                    cost[i] = c[i][j] + cost[j];
                    ok = true;
                    min = cost[i];
                    r = j;
                }
                if(ok){
                    a[l++] = cost[i];
                }
                else{
                    a[l++] = cost[j] + c[i][j];
                }
            }
        }
        if(s[i] != s[i + 1])
            printf("\n\nStage - %d:", s[i]);
        printf("\n\tCost[%d, %d]:\tmin", s[i], i);
        printf("{");
        for(int i = 0; i < l; i++){
            if(a[i] > 0){
                printf("%d", a[i]);
                if(i != l - 1){
                    printf(", ");
                }
            }
        }
        printf("}\n");
        printf("\t\t\t= %d\t\td[%d] = %d", min, i, r);
        for(int i = 0; i <= n; i++)
            a[i] = -1;
        d[i] = r;
    }
    p[1] = 1;
    p[k] = n;
    for (int i = 2; i <= k - 1; i++){
        p[i] = d[p[i - 1]];
        printf("\nd[%d] = %d", p[i - 1], p[i]);
        if(i == k - 1){
            printf("\nd[%d] = %d", p[i], p[i + 1]);
        }
    }
    printf("\nMinimum Cost of FGraph is : %d\n", cost[1]);
    printf("FGraph Path: ");
    printf("[");
    for (int i = 1; i <= k; i++)
    {
        printf("%d", p[i]);
        if (i != k)
            printf(" -> ");
    }
    printf("]");
    free(cost);
    free(d);
}

int main()
{
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    int **cost = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++)
        cost[i] = (int *)malloc((n + 1) * sizeof(int));
    int mxEdges = n * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INT_MAX;
        }
    }
    printf("Enter the Edges (-1 -1) to quit: \n");
    for (int i = 1; i <= mxEdges; i++)
    {
        int a, b, wt;
        // printf("Enter Edge %d (-1 -1 to Quit) : ", i);
        // printf("\nEnter Source: ");
        scanf("%d", &a);
        // printf("Enter Destination : ");
        scanf("%d", &b);
        scanf("%d", &wt);
        if (a == -1 || b == -1)
            break;
        else if (a > n || b > n || a <= 0 || b <= 0)
        {
            printf("Invalid Input. %d Vertices are numbered from 1 to %d\n", n, n);
            i--;
            continue;
        }
        // printf("Enter Weight : ");
        if (wt == 0)
        {
            printf("Enter a non-zero weight...\n");
            i--;
            continue;
        }
        cost[a][b] = wt;
    }
    printf("\nCost Matrix: \n");
    display_c(cost, n);
    int k;
    printf("\nEnter the number of stages : ");
    scanf("%d", &k);
    int *p = (int *)malloc((n + 1) * sizeof(int));
    FGraph(cost, k, n, p);
    free(p);
    free(cost);
    for(int i = 1; i <= n + 1; i++){
        free(cost[i]);
    }
    return 0;
}
/*
OUTPUT;
Enter the number of vertices : 14
Enter the Edges (-1 -1) to quit: 
1 2 13
1 3 11
1 4 12
1 5 10
2 7 8
2 8 6
2 9 7
3 6 7
3 8 6
3 9 8
4 6 8
4 7 6
4 9 7
5 6 6
5 7 8
5 8 7
6 10 11
6 11 12
6 13 13
7 10 13
7 11 11
7 12 12
8 11 12
8 12 11
8 13 13
9 10 13
9 12 12
9 13 11
10 14 10
11 14 12
12 14 13
13 14 11
-1 -1 -1

Cost Matrix:
INF     13      11      12      10      INF     INF     INF     INF     INF     INF     INF     INF     INF
INF     INF     INF     INF     INF     INF     8       6       7       INF     INF     INF     INF     INF
INF     INF     INF     INF     INF     7       INF     6       8       INF     INF     INF     INF     INF
INF     INF     INF     INF     INF     8       6       INF     7       INF     INF     INF     INF     INF
INF     INF     INF     INF     INF     6       8       7       INF     INF     INF     INF     INF     INF
INF     INF     INF     INF     INF     INF     INF     INF     INF     11      12      INF     13      INF
INF     INF     INF     INF     INF     INF     INF     INF     INF     13      11      12      INF     INF
INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     12      11      13      INF
INF     INF     INF     INF     INF     INF     INF     INF     INF     13      INF     12      11      INF
INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     10
INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     12
INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     13
INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     11
INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF     INF

Enter the number of stages : 5

Stage - 5:
        Cost[5, 14]:    min{0}
                        = 0

Stage - 4:
        Cost[4, 13]:    min{11}
                        = 11            d[13] = 14
        Cost[4, 12]:    min{13}
                        = 13            d[12] = 14
        Cost[4, 11]:    min{12}
                        = 12            d[11] = 14
        Cost[4, 10]:    min{10}
                        = 10            d[10] = 14

Stage - 3:
        Cost[3, 9]:     min{23, 25, 22}
                        = 22            d[9] = 13
        Cost[3, 8]:     min{24, 24, 24}
                        = 24            d[8] = 11
        Cost[3, 7]:     min{23, 23, 25}
                        = 23            d[7] = 10
        Cost[3, 6]:     min{21, 24, 24}
                        = 21            d[6] = 10

Stage - 2:
        Cost[2, 5]:     min{27, 31, 31}
                        = 27            d[5] = 6
        Cost[2, 4]:     min{29, 29, 29}
                        = 29            d[4] = 6
        Cost[2, 3]:     min{28, 30, 30}
                        = 28            d[3] = 6
        Cost[2, 2]:     min{31, 30, 29}
                        = 29            d[2] = 9

Stage - 1:
        Cost[1, 1]:     min{42, 39, 41, 37}
                        = 37            d[1] = 5
d[1] = 5
d[5] = 6
d[6] = 10
d[10] = 14
Minimum Cost of FGraph is : 37
FGraph Path: [1 -> 5 -> 6 -> 10 -> 14]
*/