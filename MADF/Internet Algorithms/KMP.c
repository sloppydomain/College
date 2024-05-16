/*
    author - Yash Malviya
    title  - KMP
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define nline printf("\n") 

void KMPFailureFunction(char* P, int* f, int m) {
    int i = 1;
    int j = 0;
    f[0] = 0;
    while(i < m) {
        if(P[j] == P[i]) {
            f[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0) {
            j = f[j - 1];
        }
        else {
            f[i] = 0;
            i++;
        }
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

void printS(char *s, bool *cmp, int n) {
    printf("| ");
    for(int i = 0; i < n; i++) {
        if(cmp[i]) {
            printf("\033[4m%c\033[0m", s[i]);
        }
        else {
            printf("%c", s[i]);
        }
        printf(" | ");
    }
}

int KMP(char *T, char* P, int m, int n) {
    int* f = (int *)malloc(m * (sizeof(int)));
    KMPFailureFunction(P, f, m);
    int i = 0;
    int j = 0;
    bool *cmp = (bool *)malloc(m * sizeof(bool));
    for(int i = 0; i < m; i++) {
        cmp[i] = false;
    }
    printf("| ");
    for(int i = 0; i < n; i++) {
        printf("%c | ", T[i]);
    }
    nline;
    int s = 0;
    int cnt = 0;
    while(i < n) {
        if(P[j] == T[i]) {
            cmp[j] = true;
            if(j == m - 1) {
                spaces(s);
                printS(P, cmp, m);
                spaces(n - s - 1);
                printf("[i = %d, j = %d]\n", i, j);
                spaces(s);
                int h = 0;
                while(cmp[h]) {
                    printf("%4d", ++cnt);
                    h++;
                }
                printf("\nTotal Number of comparisons: %d.", cnt);
                return (i - m + 1);
            }
            i++;
            j++;
        }
        else if(j > 0) {
            cmp[j] = true;
            spaces(s);
            printS(P, cmp, m);
            spaces(n - s - 1);
            printf("[i = %d, j = %d]\n", i, j);
            spaces(s);
            int h = 0;
            while(cmp[h]) {
                printf("%4d", ++cnt);
                h++;
            }
            j = f[j - 1];
            nline;
            s = i;
            for(int k = 0; k < m; k++) {
                cmp[k] = false;
            }
        }
        else {
            cmp[j] = true;
            spaces(s);
            printS(P, cmp, m);
            spaces(n - s - 1);
            printf("[i = %d, j = %d]\n", i, j);
            spaces(s);
            int h = 0;
            while(cmp[h]) {
                printf("%4d", ++cnt);
                h++;
            }
            nline;
            i++;
            s = i;
            for(int k = 0; k < m; k++) {
                cmp[k] = false;
            }
        }
    }    
    return -1;
}

int main() {
    int n;
    // printf("Enter length of text: ");
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
    int ans = KMP(T, P, m, n);
    if(ans == -1) {
        printf("String %s not found.", P);
        return 0;
    }
    printf("\nString %s found at index %d.", P, ans);
    free(T);
    free(P);
    return 0;
}

/*
OUTPUT:
22
dbbdabdcdabbbdbacdabba
5
dabba  
dbbdabdcdabbbdbacdabba 
dabba 
| d | b | b | d | a | b | d | c | d | a | b | b | b | d | b | a | c | d | a | b | b | a | 
| d | a | b | b | a |                                                                                     [i = 1, j = 1]
   1   2
    | d | a | b | b | a |                                                                                 [i = 1, j = 0]
       3
        | d | a | b | b | a |                                                                             [i = 2, j = 0]
           4
            | d | a | b | b | a |                                                                         [i = 6, j = 3]
               5   6   7   8
                        | d | a | b | b | a |                                                             [i = 7, j = 1]
                           9  10
                            | d | a | b | b | a |                                                         [i = 7, j = 0]
                              11
                                | d | a | b | b | a |                                                     [i = 12, j = 4]
                                  12  13  14  15  16
                                                | d | a | b | b | a |                                     [i = 12, j = 0]
                                                  17
                                                    | d | a | b | b | a |                                 [i = 14, j = 1]
                                                      18  19
                                                        | d | a | b | b | a |                             [i = 14, j = 0]
                                                          20
                                                            | d | a | b | b | a |                         [i = 15, j = 0]
                                                              21
                                                                | d | a | b | b | a |                     [i = 16, j = 0]
                                                                  22
                                                                    | d | a | b | b | a |                 [i = 21, j = 4]
                                                                      23  24  25  26  27
Total Number of comparisons: 27.
String dabba found at index 17.
*/