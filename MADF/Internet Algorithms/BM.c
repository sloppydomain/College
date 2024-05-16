/*
    author - Yash Malviya
    title  - Boyer Moore
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define nline printf("\n") 

int min(int a, int b) {
    return (a > b ? b : a);
}

void printS(char *s, int n) {
    printf("|");
    for(int i = 0; i < n; i++) {
        printf(" %c |", s[i]);
    }
}

void spaces(int n) {
    if(n == 0) {
        return;
    }
    for(int i = 0; i < 2 * n; i++) {
        printf("  ");
    }
}

int lastOccurrence(char* a, char c, int m) {
    for(int i = m - 1; i >= 0; i--) {
        if(a[i] == c) {
            return i;
        }
    }
    return -1;
}

int BM(char *T, char* P, int n, int m) {
    int i = m - 1;
    int j = m - 1;
    int cnt = 0;
    printS(T, n);
    do {
        cnt++;
        if(i == m - 1) {
            nline;
            printS(P, m);
            spaces(n - i + 1);
            printf("[i = %d, j = %d]\n", i, j);
        }
        if(T[i] == P[j]) {
            if(j == 0) {
                spaces(i);
                int t = cnt;
                for(int k = j; k < m; k++) {
                    printf("  %2d",t--);
                }
                nline;
                printf("\nTotal number of comparisons: %d.", cnt);
                return i;
            }
            else {
                i--;
                j--;
            }
        }
        else {
            spaces(i);
            int t = cnt;
            for(int k = j; k < m; k++) {
                printf("  %2d",t--);
            }
            nline;
            int l = lastOccurrence(P, T[i], m);
            i = i + m - min(j, l + 1);
            j = m - 1;
            spaces(i - m + 1);
            printS(P, m);
            spaces(n - i + 1);
            printf("[i = %d, j = %d]\n", i, j);
        }
    } while(i < n);
    return -1;
}

int main() {
    int n;
    // printf("Enter the length of text: ");
    scanf("%d", &n);                              
    getchar();
    char* T = (char*)malloc((n + 1) * sizeof(char));
    int n_ = 0;
    // printf("Enter the text: ");
    for(int i = 0; i < n; i++){
        scanf("%c", &T[i]);
        if(T[i] == '\n'){
            T[i] = '\0';
            break;
        }
        n_++;
    }
    int m;
    // printf("Enter the length of pattern: ");
    scanf("%d", &m);
    getchar();
    char* P = (char*)malloc((m + 1) * sizeof(char));
    int m_ = 0;
    // printf("Enter the pattern: ");
    for(int i = 0; i < m; i++){
        scanf("%c", &P[i]);
        if(P[i] == '\n'){
            P[i] = '\0';
            break;
        } 
        m_++; 
    }
    n = n_;                                                    
    m = m_;
    T[n] = '\0';
    P[m] = '\0';
    printf("%s \n", T);
    printf("%s \n", P);
    int ans = BM(T, P, n, m);
    if(ans == -1) {
        printf("\nString %s not found...", P);
        return 0;
    }
    printf("\nString %s found at index %d.", P, ans);
    free(T);
    free(P);
    return 0;
}

/*
OUTPUT:
24
122312113312313213112132
5
12132
122312113312313213112132 
12132 
| 1 | 2 | 2 | 3 | 1 | 2 | 1 | 1 | 3 | 3 | 1 | 2 | 3 | 1 | 3 | 2 | 1 | 3 | 1 | 1 | 2 | 1 | 3 | 2 |
| 1 | 2 | 1 | 3 | 2 |                                                                                    [i = 4, j = 4]
                   1
        | 1 | 2 | 1 | 3 | 2 |                                                                            [i = 6, j = 4]
                           2
                | 1 | 2 | 1 | 3 | 2 |                                                                    [i = 8, j = 4]
                                   3
                    | 1 | 2 | 1 | 3 | 2 |                                                                [i = 9, j = 4]
                                       4
                        | 1 | 2 | 1 | 3 | 2 |                                                            [i = 10, j = 4]
                                           5
                                | 1 | 2 | 1 | 3 | 2 |                                                    [i = 12, j = 4]
                                                   6
                                    | 1 | 2 | 1 | 3 | 2 |                                                [i = 13, j = 4]
                                                       7
                                            | 1 | 2 | 1 | 3 | 2 |                                        [i = 15, j = 4]
                                                  11  10   9   8
                                                | 1 | 2 | 1 | 3 | 2 |                                    [i = 16, j = 4]
                                                                  12
                                                        | 1 | 2 | 1 | 3 | 2 |                            [i = 18, j = 4]
                                                                          13
                                                                | 1 | 2 | 1 | 3 | 2 |                    [i = 20, j = 4]
                                                                              15  14
                                                                    | 1 | 2 | 1 | 3 | 2 |                [i = 21, j = 4]
                                                                                      16
                                                                            | 1 | 2 | 1 | 3 | 2 |        [i = 23, j = 4]
                                                                              21  20  19  18  17

Total number of comparisons: 21.
String 12132 found at index 19.
*/