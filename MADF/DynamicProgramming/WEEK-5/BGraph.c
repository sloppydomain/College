/*
    author - Yash Malviya
    title  - Backward Graph
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

void BGraph(int **c, int k, int n, int *p)
{
    int *cost = (int *)malloc((n + 1) * sizeof(int));
    int *d = (int *)malloc((n + 1) * sizeof(int));
    int *s = (int *)malloc((n + 1) * sizeof(int));
    int *a = (int *)malloc((n + 1) * sizeof(int));
    for(int i = 0; i <= n; i++){
        a[i] = -1;
    }
    s[1] = 1;
    cost[1] = 0;
    printf("\nStage - 1:\n\tCost[1, 1]:\tmin{%d}\n\t\t\t= %d", cost[1], cost[1]);
    for (int i = 2; i <= n; i++)
    {
        cost[i] = INT_MAX;
        int r;
        int l = 0;
        int min;
        for (int j = i - 1; j >= 1; j--)
        {
            if (c[j][i] != INT_MAX)
            {
                s[i] = s[j] + 1;
                bool ok = false;
                if (c[j][i] + cost[j] < cost[i])
                {
                    cost[i] = c[j][i] + cost[j];
                    ok = true;
                    min = cost[i];
                    r = j;
                }
                if(ok){
                    a[l++] = cost[i];
                }
                else{
                    a[l++] = cost[j] + c[j][i];
                }
            }
        }
        if(s[i] != s[i - 1])
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
    printf("\n");
    for (int i = k - 1; i >= 2; i--){
        p[i] = d[p[i + 1]];
        printf("\nd[%d] = %d", p[i + 1], p[i]);
        if(i == 2){
            printf("\nd[%d] = %d", p[i], p[i - 1]);
        }
    }
    printf("\n\nMinimum Cost of BGraph is : %d\n", cost[n]);
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
        if (wt <= 0)
        {
            printf("Enter a non-zero and a non negative weight...\n");
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
    BGraph(cost, k, n, p);
    printf("\nBGraph Path: \n");
    for (int i = 1; i <= k; i++)
    {
        printf("%d", p[i]);
        if (i != k)
            printf(" <- ");
    }
    free(cost);
    for(int i = 1; i <= n; i++)
        free(cost[i]);
    return 0;
}
/*
OUTPUT:
Enter the number of vertices : 14
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

Stage - 1:
        Cost[1, 1]:     min{0}
                        = 0

Stage - 2:
        Cost[2, 2]:     min{13}
                        = 13            d[2] = 1
        Cost[2, 3]:     min{11}
                        = 11            d[3] = 1
        Cost[2, 4]:     min{12}
                        = 12            d[4] = 1
        Cost[2, 5]:     min{10}
                        = 10            d[5] = 1

Stage - 3:
        Cost[3, 6]:     min{16, 20, 18}
                        = 16            d[6] = 5
        Cost[3, 7]:     min{18, 18, 21}
                        = 18            d[7] = 5
        Cost[3, 8]:     min{17, 17, 19}
                        = 17            d[8] = 5
        Cost[3, 9]:     min{19, 19, 20}
                        = 19            d[9] = 4

Stage - 4:
        Cost[4, 10]:    min{32, 31, 27}
                        = 27            d[10] = 6
        Cost[4, 11]:    min{29, 29, 28}
                        = 28            d[11] = 6
        Cost[4, 12]:    min{31, 28, 30}
                        = 28            d[12] = 8
        Cost[4, 13]:    min{30, 30, 29}
                        = 29            d[13] = 6

Stage - 5:
        Cost[5, 14]:    min{40, 41, 40, 37}
                        = 37            d[14] = 10
d[14] = 10
d[10] = 6
d[6] = 5
d[5] = 1

Minimum Cost of BGraph is : 37

BGraph Path:
1 <- 5 <- 6 <- 10 <- 14
*/