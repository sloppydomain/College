 /*
    author - Yash Malviya
    title  - 0/1 KnapSack
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define nline printf("\n")

struct PW{
    int p;
    int w;
};

void print1(struct PW *dp, int *b, int n){
    for(int i = 0; i <= n; i++){
        printf("S^%d:\t", i);
        printf("{ ");    //When i = n, b goes from n to n + 1, eg when n = 3 total three sets to print last set loop should go from b[3] to b[4]
        for(int j = b[i]; j < b[i + 1]; j++){
            printf("(%d, %d)", dp[j].p, dp[j].w);
            if(j != (b[i + 1] - 1))
                 printf(", ");
        }
        printf(" }\n");
    }
}

// int largest(struct PW *dp, int *w, int l, int r, int i, int m){
//     for(int j = l; j <= r; j++){
//         if(dp[j].w + w[i] > m){
//             return j - 1;
//         }
//     }
//     return r;
// }

int largest(struct PW *dp, int *w, int l, int r, int i, int m){
        while (l <= r) {
        int mid = l + (r - l) / 2;

        if (dp[mid].w + w[i] <= m) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

// void TraceBack(int *p, int *w, struct PW *dp, int *x, int m, int n, int *b){
//     int tp = dp[b[n + 1] - 1].p;
//     int tw = dp[b[n + 1] - 1].w;
//     for(int i = n - 1; i >= 0; i--){
//         bool ok = false;
//         for(int j = b[i]; j < b[i + 1]; j++){
//             if(dp[j].p == tp && dp[j].w == tw){
//                 ok = true;
//                 break;
//             }
//         }
//         if(!ok){
//             tp -= p[i + 1];
//             tw -= w[i + 1];
//             x[i + 1] = 1;
//         }
//     }
// }

void TraceBack(int *p, int *w, struct PW *dp, int *x, int m, int n, int *b){
    int tp = dp[b[n + 1] - 1].p;
    int tw = dp[b[n + 1] - 1].w;
    for(int i = n - 1; i >= 0; i--){
        bool ok = false;
        int l = b[i];
        int r = b[i + 1];
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(dp[mid].p < tp){
                l = mid + 1;
            }
            else if(dp[mid].p > tp){
                r = mid - 1;
            }
            else{
                ok = true;
                break;
            }
        }
        if(!ok){
            x[i + 1] = 1;
            tp -= p[i + 1];
            tw -= w[i + 1];
        }
    }
}

void O1KnapSack(struct PW *dp, int *p, int *w, int *x, int n, int m){
    int *b = (int *)malloc((n + 1) * sizeof(int));
    b[0] = 1;
    dp[1].p = 0;
    dp[1].w = 0;
    int t = 1;
    int h = 1;
    b[1] = 2;
    int next = 2;
    for(int i = 1; i <= n; i++){
        int k = t;
        int u = largest(dp, w, t, h, i, m);
        for(int j = t; j <= u; j++){
            int pp = dp[j].p + p[i];
            int ww = dp[j].w + w[i];
            while(k <= h && dp[k].w < ww){
                dp[next].p = dp[k].p;
                dp[next].w = dp[k].w;
                next++;
                k++;
            }
            if(k <= h && dp[k].w == ww){
                if(pp < dp[k].p){
                    pp = dp[k].p;
                }
                k++;
            }
            if(pp > dp[next - 1].p){
                dp[next].p = pp;
                dp[next].w = ww;
                next++;
            }
            while(k <= h && dp[k].p <= dp[next - 1].p)
                k++;
        }
        while(k <= h && dp[k].w <= m){
            dp[next].p = dp[k].p;
            dp[next].w = dp[k].w;  
            next++;
            k++;
        }
        t = h + 1;
        h = next - 1;
        b[i + 1] = next;
    }
    TraceBack(p, w, dp, x, m, n, b);
    print1(dp, b, n);
    printf("\nMaximum Profit: %d\nMaximum weight filled at: %d\n", dp[b[n + 1] - 1].p, dp[b[n + 1] - 1].w);
}

int main(){
    int n;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    int m;
    printf("Enter the KnapSack size: ");
    scanf("%d", &m);
    int *p = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter profit of objects: ");
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
    }
    int *w = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter weight of objects: ");
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    int *x = (int *)malloc((n + 1) * sizeof(int));
    for(int i = 0; i <= n; i++){
        x[i] = 0;
    }
    struct PW *dp = (struct PW *)malloc((pow(2, n) + 10) * sizeof(struct PW));
    O1KnapSack(dp, p, w, x, n, m);
    printf("\nObjects are: \n");
    for(int i = 1; i <= n; i++){
        printf("x[%d] = %d", i, x[i]);
        if(i != n)
            printf(", ");
    }
    free(dp);
    free(p);
    free(w);
    free(x);
    return 0;
}
/*
OUTPUT:
Enter the number of objects: 7
Enter the KnapSack size: 23
Enter profit of objects: 5 27 67 34 56 43 23
Enter weight of objects: 6 5 7 8 6 5 4
S^0:    { (0, 0) }
S^1:    { (0, 0), (5, 6) }
S^2:    { (0, 0), (27, 5), (32, 11) }
S^3:    { (0, 0), (27, 5), (67, 7), (94, 12), (99, 18) }
S^4:    { (0, 0), (27, 5), (67, 7), (94, 12), (101, 15), (128, 20) }
S^5:    { (0, 0), (27, 5), (56, 6), (67, 7), (83, 11), (94, 12), (123, 13), (150, 18), (157, 21) }
S^6:    { (0, 0), (43, 5), (56, 6), (67, 7), (70, 10), (99, 11), (110, 12), (123, 13), (126, 16), (137, 17), (166, 18), (193, 23) }
S^7:    { (0, 0), (23, 4), (43, 5), (56, 6), (67, 7), (79, 10), (99, 11), (110, 12), (123, 13), (133, 16), (146, 17), (166, 18), (189, 22), (193, 23) }

Maximum Profit: 193
Maximum weight filled at: 23

Objects are:
x[1] = 0, x[2] = 1, x[3] = 1, x[4] = 0, x[5] = 1, x[6] = 1, x[7] = 0
*/