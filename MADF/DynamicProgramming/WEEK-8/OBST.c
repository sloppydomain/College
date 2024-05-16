/*
    Author - Yash Malviya
    Title - OBST (Optimal Binary Search Tree Algorithm)
*/
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#define nline printf("\n")

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

void printBinaryTree(char **idf, int **root, int i, int j, int depth, char edge) {
    if (root[i][j] == 0) {
        printSpaces(4 * depth);
        printf("\n");
        return;
    }
    printBinaryTree(idf, root, root[i][j], j, depth + 1, '/');
    printSpaces(4 * depth);
    printf("%c--%s\n", edge, idf[root[i][j]]);
    printBinaryTree(idf, root, i, root[i][j] - 1, depth + 1, '\\');
}

void preorder(char ** idf, int **r, int i, int j){
    if(r[i][j] == 0)
        return;
    printf("%s(k = %d) ", idf[r[i][j]], r[i][j]);
    preorder(idf, r, i, r[i][j] - 1);
    preorder(idf, r, r[i][j], j);
}

void inorder(char ** idf, int **r, int i, int j){
    if(r[i][j] == 0)
        return;
    preorder(idf, r, i, r[i][j] - 1);
    printf("%s(k = %d) ", idf[r[i][j]], r[i][j]);
    preorder(idf, r, r[i][j], j);
}

void postorder(char ** idf, int **r, int i, int j){
    if(r[i][j] == 0)
        return;
    preorder(idf, r, i, r[i][j] - 1);
    preorder(idf, r, r[i][j], j);
    printf("%s(k = %d) ", idf[r[i][j]], r[i][j]);
}

int find(int **c, int **r, int i, int j){
    int min = INT_MAX;
    int l;
    for(int m = r[i][j - 1]; m <= r[i + 1][j]; m++){
        if(c[i][m - 1] + c[m][j] < min){
            min = c[i][m - 1] + c[m][j];
            l = m;
        }
    }
    return l;
}

void print(int **w, int **c, int **r, int n){
    int j;
    for(int i = 0; i <= n; i++){
        printf("\t\t%d", i);
    }
    for(int d = 0; d <= n; d++){
        nline;
        nline;
        printf("[j - i] = %d", d);
        j = 0;
        printf("   w[%d][%d] = %3d", j, d, w[j][d]);
        j++;
        for(int i = d + 1; i <= n; i++){
            printf("   w[%d][%d] = %3d", j, i, w[j][i]);
            j++;
        }
        nline;
        j = 0;
        printf("              c[%d][%d] = %3d", j, d, c[j][d]);
        j++;
        for(int i = d + 1; i <= n; i++){
            printf("   c[%d][%d] = %3d", j, i, c[j][i]);
            j++;
        }
        nline;
        j = 0;
        printf("              r[%d][%d] = %3d", j, d, r[j][d]);
        j++;
        for(int i = d + 1; i <= n; i++){
            printf("   r[%d][%d] = %3d", j, i, r[j][i]);
            j++;
        }
    }
}

void obst(int *p, int *q, int *a, int n, char **idf){
    int **cost = (int **)malloc((n + 1) * sizeof(int *));
    for(int i = 0; i <= n; i++){
        cost[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    int **w = (int **)malloc((n + 1) * sizeof(int *));
    for(int i = 0; i <= n; i++){
        w[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    int **r = (int **)malloc((n + 1) * sizeof(int *));
    for(int i = 0; i <= n; i++){
        r[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for(int i = 0; i <= n - 1; i++){
        w[i][i] = q[i];
        cost[i][i] = 0;
        r[i][i] = 0;
        w[i][i + 1] = q[i] + p[i + 1] + q[i + 1];
        r[i][i + 1] = i + 1;
        cost[i][i + 1] = w[i][i + 1];
    }
    w[n][n] = q[n];
    cost[n][n] = 0;
    r[n][n] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            w[j][j + i] = w[j][j + i - 1] + p[j + i] + q[j + i];
            int k = find(cost, r, j, j + i);
            cost[j][j + i] = cost[j][k - 1] + cost[k][j + i] + w[j][j + i];
            r[j][j + i] = k;
        }
    }
    print(w, cost, r, n);
    nline;
    printf("\nw[0][%d] = %d\nc[0][%d] = %d\nr[0][%d] = %d", n, w[0][n], n, cost[0][n], n, r[0][n]); 
    printf("\nCost of Optimal Binary Search Tree: %d\n", cost[0][n]);
    printf("\nPreorder: ");
    preorder(idf, r, 0, n);
    printf("\nInorder: ");;
    inorder(idf, r, 0, n);
    printf("\nPostorder: ");
    postorder(idf, r, 0, n);
    printf("\nBinary Tree: \n");
    printBinaryTree(idf, r, 0, n, 0, '|');
}

int main(){
    int n;
    printf("Enter the number of distinct identifiers: ");
    scanf("%d", &n);
    int *a = (int *)malloc((n + 1) * sizeof(int));
    int *p = (int *)malloc((n + 1) * sizeof(int));
    int *q = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter distinct identifiers: ");
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    char **idf = (char **)malloc((n + 1) * sizeof(char*));
    for(int i = 1; i <= n; i++){
        idf[i] = (char *)malloc(20 * sizeof(char));
    }
    printf("Enter the names of identifiers: ");
    for(int i = 1; i <= n; i++){
        scanf("%s", idf[a[i]]);
    }
    printf("Enter successfull probabilities: ");
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
    }
    printf("Enter unsuccessfull probabilities: ");
    for(int i = 0; i <= n; i++){
        scanf("%d", &q[i]);
    }
    obst(p, q, a, n, idf);
    free(a);
    free(p);
    free(q);
    return 0;
}

/*
OUTPUT:
Enter the number of distinct identifiers: 5
Enter distinct identifiers: 1 2 3 4 5
Enter the names of identifiers: break const enum long start
Enter successfull probabilities: 6 4 3 6 7
Enter unsuccessfull probabilities: 5 7 5 5 5 4
                0               1               2               3               4               5

[j - i] = 0   w[0][0] =   5   w[1][1] =   7   w[2][2] =   5   w[3][3] =   5   w[4][4] =   5   w[5][5] =   4
              c[0][0] =   0   c[1][1] =   0   c[2][2] =   0   c[3][3] =   0   c[4][4] =   0   c[5][5] =   0
              r[0][0] =   0   r[1][1] =   0   r[2][2] =   0   r[3][3] =   0   r[4][4] =   0   r[5][5] =   0

[j - i] = 1   w[0][1] =  18   w[1][2] =  16   w[2][3] =  13   w[3][4] =  16   w[4][5] =  16
              c[0][1] =  18   c[1][2] =  16   c[2][3] =  13   c[3][4] =  16   c[4][5] =  16
              r[0][1] =   1   r[1][2] =   2   r[2][3] =   3   r[3][4] =   4   r[4][5] =   5

[j - i] = 2   w[0][2] =  27   w[1][3] =  24   w[2][4] =  24   w[3][5] =  27
              c[0][2] =  43   c[1][3] =  37   c[2][4] =  37   c[3][5] =  43
              r[0][2] =   1   r[1][3] =   2   r[2][4] =   4   r[3][5] =   4

[j - i] = 3   w[0][3] =  35   w[1][4] =  35   w[2][5] =  35
              c[0][3] =  66   c[1][4] =  67   c[2][5] =  64
              r[0][3] =   2   r[1][4] =   3   r[2][5] =   4

[j - i] = 4   w[0][4] =  46   w[1][5] =  46
              c[0][4] = 101   c[1][5] =  99
              r[0][4] =   2   r[1][5] =   4

[j - i] = 5   w[0][5] =  57
              c[0][5] = 139
              r[0][5] =   2

w[0][5] = 57
c[0][5] = 139
r[0][5] = 2
Cost of Optimal Binary Search Tree: 139

Preorder: const(k = 2) break(k = 1) long(k = 4) enum(k = 3) start(k = 5)
Inorder: break(k = 1) const(k = 2) long(k = 4) enum(k = 3) start(k = 5)
Postorder: break(k = 1) long(k = 4) enum(k = 3) start(k = 5) const(k = 2)
Binary Tree:
            
        /--start

    /--long

        \--enum

|--const

    \--break
*/