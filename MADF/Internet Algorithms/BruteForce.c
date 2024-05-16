#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define nline printf("\n") 

bool BruteForce(char* T, char* P, int n, int m) {
    for(int i = 0; i < n - m + 1; i++){
        int j = 0;
        while(j < m && T[i + j] == P[j]){
            j++;
        }
        if(j == m){
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);                                // Can randomly enter length not necessarily length T
    getchar();
    char* T = (char*)malloc((n + 1) * sizeof(char));
    int n_ = 0;
    printf("Reading T:\n");
    for(int i = 0; i < n; i++){
        scanf("%c", &T[i]);
        if(T[i] == '\n'){
            T[i] = '\0';
            break;
        }
        printf("T[%d] = %c\n", i, T[i]);
        n_++;
    }
    int m;
    scanf("%d", &m);
    getchar();
    char* P = (char*)malloc((m + 1) * sizeof(char));
    int m_ = 0;
    printf("Reading P:\n");
    for(int i = 0; i < m; i++){
        scanf("%c", &P[i]);
        if(P[i] == '\n'){
            P[i] = '\0';
            break;
        } 
        printf("P[%d] = %c\n", i, P[i]);
        m_++; 
    }
    n = n_;                                                    
    m = m_;
    T[n] = '\0';
    P[m] = '\0';
    printf("%s \n", T);
    printf("%s \n", P);
    printf("%s\n", (BruteForce(T, P, n, m) ? "Yes" : "No"));
    free(T);
    free(P);
    return 0;
}
