/*
    author - Yash Malviya
    title - NQueen's Algorithm
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define nline printf("\n")

void printSolution(int *x, int n){
    int k = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(x[i] == j){
                printf("Q ");
            }
            else{
                printf("- ");
            }
        }
        nline;
    }
    printf("Solution vector: ");
    printf("[");
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
        if(i != n){
            printf(", ");
        }
    }
    printf("]\n");
}

bool isSafe(int k, int i, int *x){
    for(int j = 1; j <= k - 1; j++){                      
        if(x[j] == i || (abs(x[j] - i) == abs(j - k))){   
            return false;                                 
        }                                                 
    }                                                    
    return true;
}

void nqueen(int k, int n, int *x, int *t){           
    for(int i = 1; i <= n; i++){
        if(isSafe(k, i, x)){
            x[k] = i;
            if(k >= n){
                ++(*t);
                if((*t) == 1){
                    printf("Solution %d for %d-Queen's: \n", (*t), n);
                    printSolution(x, n);
                }
            } 
            else{
                nqueen(k + 1, n, x, t);
            }
        }
    }
}

int main(){
    int m = 12;
    for(int q = 1; q <= m; q++){
        int *x = (int *)malloc((q + 1) * sizeof(int));
        for(int i = 1; i <= q; i++) 
            x[i] = -1;
        int t = 0;
        nqueen(1, q, x, &t);
        if(t == 0){
            printf("Total solutions for %d-Queen's: %d\n", q, t);
            printf("No solution possible...\n\n");
        }
        else{
            printf("Total solutions for %d-Queen's: %d\n\n", q, t);
        }
    }
    return 0;
}

/*
OUTPUT:
Solution 1 for 1-Queen's: 
Q 
Solution vector: [1]
Total solutions for 1-Queen's: 1

Total solutions for 2-Queen's: 0
No solution possible...

Total solutions for 3-Queen's: 0
No solution possible...

Solution 1 for 4-Queen's: 
- Q - - 
- - - Q 
Q - - - 
- - Q - 
Solution vector: [2, 4, 1, 3]
Total solutions for 4-Queen's: 2

Solution 1 for 5-Queen's: 
Q - - - - 
- - Q - -
- - - - Q
- Q - - -
- - - Q -
Solution vector: [1, 3, 5, 2, 4]
Total solutions for 5-Queen's: 10

Solution 1 for 6-Queen's: 
- Q - - - -
- - - Q - -
- - - - - Q
Q - - - - -
- - Q - - -
- - - - Q -
Solution vector: [2, 4, 6, 1, 3, 5]
Total solutions for 6-Queen's: 4

Solution 1 for 7-Queen's:
Q - - - - - - 
- - Q - - - -
- - - - Q - - 
- - - - - - Q
- Q - - - - -
- - - Q - - -
- - - - - Q -
Solution vector: [1, 3, 5, 7, 2, 4, 6]
Total solutions for 7-Queen's: 40

Solution 1 for 8-Queen's: 
Q - - - - - - -
- - - - Q - - -
- - - - - - - Q
- - - - - Q - -
- - Q - - - - -
- - - - - - Q -
- Q - - - - - -
- - - Q - - - -
Solution vector: [1, 5, 8, 6, 3, 7, 2, 4]
Total solutions for 8-Queen's: 92

Solution 1 for 9-Queen's:
Q - - - - - - - -
- - Q - - - - - -
- - - - - Q - - -
- - - - - - - Q -
- Q - - - - - - - 
- - - Q - - - - -
- - - - - - - - Q
- - - - - - Q - -
- - - - Q - - - -
Solution vector: [1, 3, 6, 8, 2, 4, 9, 7, 5]
Total solutions for 9-Queen's: 352

Solution 1 for 10-Queen's:
Q - - - - - - - - - 
- - Q - - - - - - -
- - - - - Q - - - -
- - - - - - - Q - -
- - - - - - - - - Q
- - - - Q - - - - -
- - - - - - - - Q -
- Q - - - - - - - -
- - - Q - - - - - - 
- - - - - - Q - - -
Solution vector: [1, 3, 6, 8, 10, 5, 9, 2, 4, 7]
Total solutions for 10-Queen's: 724

Solution 1 for 11-Queen's:
Q - - - - - - - - - -
- - Q - - - - - - - -
- - - - Q - - - - - -
- - - - - - Q - - - -
- - - - - - - - Q - -
- - - - - - - - - - Q
- Q - - - - - - - - - 
- - - Q - - - - - - -
- - - - - Q - - - - -
- - - - - - - Q - - -
- - - - - - - - - Q -
Solution vector: [1, 3, 5, 7, 9, 11, 2, 4, 6, 8, 10]
Total solutions for 11-Queen's: 2680

Solution 1 for 12-Queen's:
Q - - - - - - - - - - -
- - Q - - - - - - - - -
- - - - Q - - - - - - -
- - - - - - - Q - - - -
- - - - - - - - - Q - -
- - - - - - - - - - - Q
- - - - - Q - - - - - -
- - - - - - - - - - Q -
- Q - - - - - - - - - -
- - - - - - Q - - - - -
- - - - - - - - Q - - - 
- - - Q - - - - - - - -
Solution vector: [1, 3, 5, 8, 10, 12, 6, 11, 2, 7, 9, 4]
Total solutions for 12-Queen's: 14200
*/