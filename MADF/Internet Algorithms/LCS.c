/*
    author - Yash Malviya
    title  - LCS (Longest Common Subsequence)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define UP_LEFT 1
#define UP 2
#define LEFT 3
#define nline printf("\n")

int max(int a, int b) {
    return (a > b ? a : b);
}

void prints(char *a, int n) {
    for(int i = 1; i <= n; i++) {
        printf("%c", a[i]);
    }
    nline;
}

void printM(char *X, char *Y, int **lcs, int **sign, int m, int n) {
    printf("\t\t");
    for(int i = 1; i <= n; i++) {
        printf("\t%2c", Y[i]);
    }
    nline;
    printf("\tY[i]");
    for(int i = 0; i <= n; i++) {
        printf("\t[%d]", i - 1);
    }
    nline;
    for(int i = 0; i <= m; i++) {
        if(i == 0) {
            printf("X[i]\t[-1]");
        }
        if(i > 0) {
            printf("%2c\t[%d]", X[i], i - 1);
        }
        for(int j = 0; j <= n; j++) {
            if(sign[i][j] == UP_LEFT) {
                printf("\033[1m\t\\%2d\033[0m", lcs[i][j]);
            }
            else if(sign[i][j] == UP) {
                printf("\033[1m\t^%2d\033[0m", lcs[i][j]);
            }
            else if(sign[i][j] == LEFT) {
                printf("\033[1m\t<%2d\033[0m", lcs[i][j]);
            }
            else {
                printf("\t%2d", lcs[i][j]);
            }
        }
        nline;
    }
}

void LCS(char *X, char *Y, int **lcs, int m, int n) {
    for(int i = 0; i <= n; i++) {
        lcs[0][i] = 0;
    }
    for(int j = 0; j <= m; j++) {
        lcs[j][0] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(X[i] == Y[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
}

void ans(char *X, char *Y, int **lcs, int m, int n) {
    int **sign = (int **)malloc((m + 1) * (sizeof(int *)));
    for(int i = 0; i <= m; i++) {
        sign[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            sign[i][j] = 0;
        }
    }
    int i = m;
    int j = n;
    int k = lcs[i][j];
    char *a = (char *)malloc(k * sizeof(char));
    k--;
    while(i > 0 && j > 0) {
        if(X[i] == Y[j]) {
            sign[i][j] = UP_LEFT;
            a[k] = X[i];
            i--;
            j--;
            k--;
        }
        else {
            if(lcs[i - 1][j] > lcs[i][j - 1]) {
                sign[i][j] = UP;
                i--;
            }
            else {
                sign[i][j] = LEFT;
                j--;
            }
        }
    }
    printf("\nLCS Matrix: \n");
    printM(X, Y, lcs, sign, m, n);
    printf("\nLongest Common Subsequence: ");
    for(int i = 0; i < lcs[m][n]; i++) {
        printf("%c", a[i]);
    }
    nline;
}

int main() {
    int n;
    printf("Enter the length of text: ");
    scanf("%d", &n);                           
    getchar();
    char* T = (char*)malloc((n + 2) * sizeof(char));
    int n_ = 0;
    printf("Enter the text: ");
    for(int i = 1; i <= n; i++){
        scanf("%c", &T[i]);
        if(T[i] == '\n'){
            T[i] = '\0';
            break;
        }
        n_++;
    }
    int m;
    printf("Enter the length of pattern: ");
    scanf("%d", &m);
    getchar();
    char* P = (char*)malloc((m + 2) * sizeof(char));
    int m_ = 0;
    printf("Enter the pattern: ");
    for(int i = 1; i <= m; i++){
        scanf("%c", &P[i]);
        if(P[i] == '\n'){
            P[i] = '\0';
            break;
        } 
        m_++; 
    }
    n = n_;                                                    
    m = m_;
    T[n + 1] = '\0';
    P[m + 1] = '\0';
    int **lcs = (int **)malloc((m + 1) * (sizeof(int *)));
    for(int i = 0; i <= m; i++) {
        lcs[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    LCS(P, T, lcs, m, n);
    ans(P, T, lcs, m, n);
    free(T);
    free(P);
    return 0;
}

/*
OUTPUT:
Enter the length of text: 16
Enter the text: TCATTGATTACCAGTA
Enter the length of pattern: 12
Enter the pattern: GTCCTATTAGTA

LCS Matrix:
                         T       C       A       T       T       G       A       T       T       A       C       C       A       G       T       A
        Y[i]    [-1]    [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]     [8]     [9]     [10]    [11]    [12]    [13]    [14]    [15]
X[i]    [-1]     0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0
 G      [0]      0       0       0       0       0       0       1       1       1       1       1       1       1       1       1       1       1
 T      [1]      0      \ 1      1       1       1       1       1       1       2       2       2       2       2       2       2       2       2
 C      [2]      0      ^ 1      2       2       2       2       2       2       2       2       2       3       3       3       3       3       3
 C      [3]      0       1      \ 2     < 2     < 2      2       2       2       2       2       2       3       4       4       4       4       4
 T      [4]      0       1       2       2       3      \ 3     < 3      3       3       3       3       3       4       4       4       5       5
 A      [5]      0       1       2       3       3       3       3      \ 4      4       4       4       4       4       5       5       5       6
 T      [6]      0       1       2       3       4       4       4       4      \ 5      5       5       5       5       5       5       6       6
 T      [7]      0       1       2       3       4       5       5       5       5      \ 6     < 6     < 6     < 6      6       6       6       6
 A      [8]      0       1       2       3       4       5       5       6       6       6       7       7       7      \ 7      7       7       7
 G      [9]      0       1       2       3       4       5       6       6       6       6       7       7       7       7      \ 8      8       8
 T      [10]     0       1       2       3       4       5       6       6       7       7       7       7       7       7       8      \ 9      9
 A      [11]     0       1       2       3       4       5       6       7       7       7       8       8       8       8       8       9      \10

Longest Common Subsequence: TCTATTAGTA
*/