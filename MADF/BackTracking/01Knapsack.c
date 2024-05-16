/*
    author - Yash Malviya
    title  - 0/1 Knapsack (Backtracking)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define nline printf("\n")

struct PAIR{
    double p;
    double w;
    double pw;
};

int n;
double fp = -1;
double fw = -1;
double m;
double *p, *w;
int *x, *y;

void print(int *a, int n){
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    nline;
}

void sort(){
    struct PAIR *pairs = (struct PAIR *)malloc((n + 1) * sizeof(struct PAIR));
    for(int i = 1; i <= n; i++){
        pairs[i].p = p[i];
        pairs[i].w = w[i];
        pairs[i].pw = p[i] / (double)w[i];
    }
    for(int i = 1; i <= n - 1; i++){                        // Bubble Sort
        int p = 0;
        for(int j = 1; j <= n - i; j++){
            if(pairs[j].pw < pairs[j + 1].pw){
                struct PAIR t = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = t; 
                p++;
            }
        }
        if(p == 0){
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        p[i] = pairs[i].p;
        w[i] = pairs[i].w;
    }
}

double Bound(int k, double cp, double cw){
    double a = cp;
    double b = cw;
    for(int i = k + 1; i <= n; i++){
        b += w[i]; 
        if(b < m){
            a += p[i];
        }
        else{
            return a + (w[i] - (b - m)) * p[i] / w[i];          
        }
    }
    return a;
}

void O1Knapsack(int k, double cp, double cw){
    static int s = 0;
    if(cw + w[k] <= m){
        y[k] = 1;                                   // Left Child, include weight w[k]
        if(k < n){
            O1Knapsack(k + 1, cp + p[k], cw + w[k]);
        }
        if(cp + p[k] > fp && k == n){               // if profit at current end is greater than the profit obtained in previous solution (if any)
            fp = cp + p[k];
            fw = cw + w[k];
            for(int i = 1; i <= k; i++){
                x[i] = y[i];
            }
            printf("Feasible solution %d: \n[k, cp, cw] = [%d, %d, %d]\nSolution Vector: ", ++s, k + 1, (int)fp, (int)fw);
            printf("[");
            for(int i = 1; i <= k; i++){
                printf("%d%s", x[i], (i == k) ? "]\n" : ", ");
            }
        }
    }                                               // Bound is the profit of remaining objects when u exclude a particular object, to determine if after this object there can still be a better solution later with more profit
    if(Bound(k, cp, cw) >= fp){                     // Right Child, exclude weight w[k]
        y[k] = 0;
        if(k < n){
            O1Knapsack(k + 1, cp, cw);              // Bound >= fp doesnt necessarily mean bound is the new max profit because it also includes fraction part which isnt 0/1 :)
        }
        if(cp > fp && k == n){
            fp = cp;
            fw = cw;
            for(int i = 1; i <= k; i++){
                x[i] = y[i];
            }
            printf("Feasible solution %d: \n[k, cp, cw] = [%d, %d, %d]\nSolution Vector: ", ++s, k + 1, (int)fp, (int)fw);
            printf("[");
            for(int i = 1; i <= k; i++){
                printf("%d%s", x[i], (i == k) ? "]\n" : ", ");
            }
        }
    }
}

int main(){
    printf("Enter the number of Objects: ");
    scanf("%d", &n);
    p = (double *)malloc((n + 1) * sizeof(double));
    printf("Enter the profits of Objects: ");
    for(int i = 1; i <= n; i++){
        scanf("%lf", &p[i]);
    }
    w = (double *)malloc((n + 1) * sizeof(double));
    printf("Enter the weights of Objects: ");
    for(int i = 1; i <= n; i++){
        scanf("%lf", &w[i]);
    }
    printf("Enter the size of the knapsack: ");
    scanf("%lf", &m);
    x = (int *)malloc((n + 1) * sizeof(int));
    y = (int *)malloc((n + 1) * sizeof(int));
    sort();
    nline;
    O1Knapsack(1, 0.0, 0.0);
    printf("\nFinal Optimal solution: \n[k, cp, cw] = [%d, %d, %d]\nSolution Vector: ", n + 1, (int)fp, (int)fw);
    printf("[");
    for(int i = 1; i <= n; i++){
        printf("%d%s", x[i], (i == n) ? "]\n" : ", ");
    }
    return 0;
}

/*
OUTPUT:
Enter the number of Objects: 5
Enter the profits of Objects: 43 38 30 23 14
Enter the weights of Objects: 9 8 7 6 5
Enter the size of the knapsack: 13

Feasible solution 1: 
[k, cp, cw] = [6, 43, 9]
Solution Vector: [1, 0, 0, 0, 0]
Feasible solution 2: 
[k, cp, cw] = [6, 52, 13]
Solution Vector: [0, 1, 0, 0, 1]
Feasible solution 3: 
[k, cp, cw] = [6, 53, 13]
Solution Vector: [0, 0, 1, 1, 0]

Final Optimal solution: 
[k, cp, cw] = [6, 53, 13]
Solution Vector: [0, 0, 1, 1, 0]
*/