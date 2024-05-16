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
    s[n] = n;
    cost[n] = 0;
    printf("\nStage - %d:\n\tCost[1, 1]:\tmin{%d}\n\t\t\t= %d", cost[1], cost[1]);
    for (int i = n - 1; i >= 1; i--)
    {
        cost[i] = INT_MAX;
        int r;
        int l = 0;
        int min;
        for (int j = i; j <= n; j++)
        {
            if (c[i][j] != INT_MAX)
            {
                s[i] = s[j] + 1;
                if (c[i][j] + cost[j] < cost[i])
                {
                    cost[i] = c[i][j] + cost[j];
                    min = cost[i];
                    r = j;
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
        printf("\t\t\t= %d", min);
        for(int i = 0; i <= n; i++)
            a[i] = -1;
        d[i] = r;
        printf("\nVertex %d: \n", i);
        printf("Cost[%d] = %d\nd[%d] = %d\n", i, cost[i], i, d[i]);
    }
    p[1] = 1;
    p[k] = n;
    for (int i = 2; i <= k - 1; i++)
        p[i] = d[p[i - 1]];
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

void BGraph(int **c, int k, int n, int *p)
{
    int *cost = (int *)malloc((n + 1) * sizeof(int));
    int *d = (int *)malloc((n + 1) * sizeof(int));
    cost[1] = 0;
    printf("\n\nVertex 1: \nCost[1] = %d\nd[1] = -1\n", cost[1]);
    for (int i = 2; i <= n; i++)
    {
        cost[i] = INT_MAX;
        int r;
        for (int j = i - 1; j >= 1; j--)
        {
            if (c[j][i] != INT_MAX)
            {
                if (c[j][i] + cost[j] < cost[i])
                {
                    cost[i] = c[j][i] + cost[j];
                    r = j;
                }
            }
        }
        d[i] = r;
        printf("\nVertex %d: \n", i);
        printf("Cost[%d] = %d\nd[%d] = %d\n", i, cost[i], i, d[i]);
    }
    p[1] = 1;
    p[k] = n;
    for (int i = k - 1; i >= 2; i--)
        p[i] = d[p[i + 1]];
    printf("\n\nMinimum Cost of BGraph is : %d\n", cost[n]);
    printf("BGraph Path is : \n");
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
    BGraph(cost, k, n, p);
    free(cost);
    for (int i = 1; i <= n; i++)
        free(cost[i]);
    return 0;
}