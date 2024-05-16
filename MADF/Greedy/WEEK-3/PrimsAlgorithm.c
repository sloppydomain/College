/*
    author - Yash Malviya
    title - Prim's Algorithm
*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

void Display1(int **a, int n)
{
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
}

void Display2(int *near, int **cost, int n, int min, int k, int l)
{
    printf("\n\t  near[k]\t cost[k, near[k]]");
    for (int i = 1; i <= n; i++)
    {
        printf("\nnear[%d] : %3d", i, near[i]);
        if (cost[i][near[i]] == min && i == k && near[i] == l)
            printf("\t\t\t[%d]", min);
        else if (cost[i][near[i]] == INT_MAX)
            printf("\t\t\tINF");
        else if (near[i] == -1)
            printf("\t\t\t- ");
        else
            printf("\t\t\t%d", cost[i][near[i]]);
    }
}

void Display3(int **t, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            if (t[i][j] == INT_MAX)
                printf(" INF ");
            else
                printf("%3d ", t[i][j]);
        }
        printf("\n");
    }
}

int prim(int **cost, int n, int **t, int *near)
{
    int k = 0, l = 0;
    int min = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cost[i][j] > 0)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    k = i;
                    l = j;
                }
            }
        }
    }
    t[1][1] = k;
    t[1][2] = l;
    int mincost = cost[k][l];
    printf("\nk = %d\tl = %d\n", k, l);
    for (int i = 1; i <= n; i++)
    {
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    int s = 0;
    printf("\nSTEP %d MST: \n", ++s);
    Display3(t, s);
    printf("\nMinimum Cost = %d\n\n", mincost);
    near[k] = -1;
    near[l] = -1;
    for (int i = 2; i <= n - 1; i++)
    {
        int j;
        int min = INT_MAX;
        for (int m = 1; m <= n; m++)
        {
            if (near[m] != -1 && (cost[m][near[m]]) < min)
            {
                min = cost[m][near[m]];
                j = m;
            }
        }
        t[i][1] = j;
        t[i][2] = near[j];
        mincost += min;
        Display2(near, cost, n, min, j, near[j]);
        printf("\n\nSTEP %d MST: \n", ++s);
        Display3(t, s);
        printf("\nMinimum Cost = %d\n", mincost);
        near[j] = -1;
        for (int k = 1; k <= n; k++)
        {
            if (near[k] != -1 && (cost[k][near[k]]) > cost[k][j])
                near[k] = j;
        }
    }
    return mincost;
}

int main()
{
    int n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    int near[n + 1];
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
        cost[b][a] = wt;
    }
    printf("\nCost Matrix:\n");
    Display1(cost, n);
    int **t = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i <= n - 1; i++)
        t[i] = (int *)malloc(3 * sizeof(int));
    int min_cost = prim(cost, n, t, near);
    printf("\n\nEdges in Spanning tree are : ");
    printf("\nSource\tDestination\tWeight\n");
    for (int i = 1; i <= n - 1; i++)
        printf("%4d\t\t%d\t%5d\n", t[i][1], t[i][2], cost[t[i][1]][t[i][2]]);
    printf("\nMinimum Cost : %d", min_cost);
    for (int i = 0; i <= n; i++)
        free(cost[i]);
    free(cost);
    for (int i = 1; i <= n - 1; i++)
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

k = 1   l = 4

STEP 1 MST:
  1   4

Minimum Cost = 1


          near[k]        cost[k, near[k]]
near[1] :  -1                   -
near[2] :   4                   [1]
near[3] :   1                   2
near[4] :  -1                   -
near[5] :   1                   1
near[6] :   4                   INF
near[7] :   4                   INF
near[8] :   4                   1

STEP 2 MST:
  1   4
  2   4

Minimum Cost = 2

          near[k]        cost[k, near[k]]
near[1] :  -1                   -
near[2] :  -1                   -
near[3] :   1                   2
near[4] :  -1                   -
near[5] :   1                   [1]
near[6] :   4                   INF
near[7] :   4                   INF
near[8] :   4                   1

STEP 3 MST:
  1   4
  2   4
  5   1

Minimum Cost = 3

          near[k]        cost[k, near[k]]
near[1] :  -1                   -
near[2] :  -1                   -
near[3] :   1                   2
near[4] :  -1                   -
near[5] :  -1                   -
near[6] :   5                   [1]
near[7] :   5                   3
near[8] :   4                   1

STEP 4 MST:
  1   4
  2   4
  5   1
  6   5

Minimum Cost = 4

          near[k]        cost[k, near[k]]
near[1] :  -1                   -
near[2] :  -1                   -
near[3] :   1                   2
near[4] :  -1                   -
near[5] :  -1                   -
near[6] :  -1                   -
near[7] :   6                   2
near[8] :   4                   [1]

STEP 5 MST:
  1   4
  2   4
  5   1
  6   5
  8   4

Minimum Cost = 5

          near[k]        cost[k, near[k]]
near[1] :  -1                   -
near[2] :  -1                   -
near[3] :   1                   2
near[4] :  -1                   -
near[5] :  -1                   -
near[6] :  -1                   -
near[7] :   8                   [1]
near[8] :  -1                   -

STEP 6 MST:
  1   4
  2   4
  5   1
  6   5
  8   4
  7   8

Minimum Cost = 6

          near[k]        cost[k, near[k]]
near[1] :  -1                   -
near[2] :  -1                   -
near[3] :   1                   [2]
near[4] :  -1                   -
near[5] :  -1                   -
near[6] :  -1                   -
near[7] :  -1                   -
near[8] :  -1                   -

STEP 7 MST:
  1   4
  2   4
  5   1
  6   5
  8   4
  7   8
  3   1

Minimum Cost = 8


Edges in Spanning tree are :
Source  Destination     Weight
   1            4           1
   2            4           1
   5            1           1
   6            5           1
   8            4           1
   7            8           1
   3            1           2

Minimum Cost : 8
*/