/*
    author - Yash Malviya
    title  - Sum Of Subsets
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    struct node* left;
    int s;
    int k;
    int r;
    int nodeCount;
    struct node* right;
};

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

void printBinaryTree(struct node* root, int depth, char edge) {
    if (root == NULL) {
        printSpaces(5 * depth);
        printf("\n\n");
        return;
    }
    printBinaryTree(root->right, depth + 1, '/');
    printSpaces(4 * depth);
    printf("%c--Node %d: [%d, %d, %d]\n", edge, root->nodeCount, root->s, root->k, root->r);
    printBinaryTree(root->left, depth + 1, '\\');
}

struct node* newNode(int s_, int k_, int r_, int c_) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed...\n");
        return NULL;
    }
    new->left = NULL;
    new->right = NULL;
    new->s = s_;
    new->k = k_;
    new->r = r_;
    new->nodeCount = c_;
    return new;
}

const int m;
const int n;
int p = 0;
int c = 0;

void SumOfSubsets(int s, int k, int r, int* x, int* w, struct node* Tree) {
    x[k] = 1;
    if (s + w[k] == m) {
        printf("Solution %d: [", ++p);
        for (int i = 1; i <= n; i++) {
            printf("%d", x[i]);
            if (i != n) {
                printf(", ");
            }
        }
        printf("]\n");
        Tree->left = newNode(s + w[k], k + 1, r - w[k], ++c);
        x[k] = 0;
    } else if (k + 1 <= n) {
        if(s + w[k] + w[k + 1] <= m){
            Tree->left = newNode(s + w[k], k + 1, r - w[k], ++c);
            SumOfSubsets(s + w[k], k + 1, r - w[k], x, w, Tree->left);
            x[k] = 0;
        }
    }
    else if(k + 1 > n){
        Tree->left = NULL;
    }
    if(k + 1 <= n){
        if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
            x[k] = 0;
            Tree->right = newNode(s, k + 1, r - w[k], ++c);
            SumOfSubsets(s, k + 1, r - w[k], x, w, Tree->right);
        }
    }
    else if(k + 1 > n){
        Tree->right = NULL;
    }
}

void freeTree(struct node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* a = (int*)malloc((n + 1) * sizeof(int));

    int sum = 0;
    printf("\nCase 1:\nEnter the elements in sorted (Ascending Order): ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("Enter the target sum: ");
    scanf("%d", &m);
    int* x = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    struct node* Tree1 = newNode(0, 1, sum, ++c);
    SumOfSubsets(0, 1, sum, x, a, Tree1);
    printf("\nTotal Solutions: %d\n\nState Space Tree\n", p);
    printBinaryTree(Tree1, 0, '|');

    sum = 0;
    p = 0;
    c = 0;
    printf("\nCase 2:\nEnter the elements in sorted (Descending Order): ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("Enter the target sum: ");
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    struct node* Tree2 = newNode(0, 1, sum, ++c);
    SumOfSubsets(0, 1, sum, x, a, Tree2);
    printf("\nTotal Solutions: %d\n\nState Space Tree\n", p);
    printBinaryTree(Tree2, 0, '|');

    sum = 0;
    p = 0;
    c = 0;
    printf("\nCase 3:\nEnter the elements in random Order: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("Enter the target sum: ");
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
    struct node* Tree3 = newNode(0, 1, sum, ++c);
    SumOfSubsets(0, 1, sum, x, a, Tree3);
    printf("\nTotal Solutions: %d\n\nState Space Tree\n", p);
    printBinaryTree(Tree3, 0, '|');

    freeTree(Tree1);
    freeTree(Tree2);
    freeTree(Tree3);
    free(x);
    free(a);
    return 0;
}

/*
OUTPUT:
Enter the number of elements: 7

Case 1:
Enter the elements in sorted (Ascending Order): 2 3 5 10 20 25 30
Enter the target sum: 30
Solution 1: [1, 1, 1, 0, 1, 0, 0]
Solution 2: [1, 1, 0, 0, 0, 1, 0]
Solution 3: [0, 0, 1, 0, 0, 1, 0]
Solution 4: [0, 0, 0, 1, 1, 0, 0]
Solution 5: [0, 0, 0, 0, 0, 0, 1]

Total Solutions: 5

State Space Tree


                        /--Node 34: [0, 7, 30]


                            \--Node 35: [30, 8, 0]


                    /--Node 33: [0, 6, 55]


                /--Node 32: [0, 5, 75]


            /--Node 29: [0, 4, 85]


                \--Node 30: [10, 5, 75]


                    \--Node 31: [30, 6, 55]


        /--Node 24: [0, 3, 90]


                    /--Node 27: [5, 6, 55]


                        \--Node 28: [30, 7, 30]


                /--Node 26: [5, 5, 75]


            \--Node 25: [5, 4, 85]


    /--Node 17: [0, 2, 93]


                    /--Node 23: [3, 6, 55]


                /--Node 22: [3, 5, 75]


            /--Node 21: [3, 4, 85]


        \--Node 18: [3, 3, 90]


                /--Node 20: [8, 5, 75]


            \--Node 19: [8, 4, 85]


|--Node 1: [0, 1, 95]


                    /--Node 16: [2, 6, 55]


                /--Node 15: [2, 5, 75]
                         

            /--Node 14: [2, 4, 85]


        /--Node 11: [2, 3, 90]


                /--Node 13: [7, 5, 75]


            \--Node 12: [7, 4, 85]


    \--Node 2: [2, 2, 93]


                    /--Node 9: [5, 6, 55]


                        \--Node 10: [30, 7, 30]


                /--Node 8: [5, 5, 75]


            /--Node 7: [5, 4, 85]


        \--Node 3: [5, 3, 90]


                /--Node 5: [10, 5, 75]


                    \--Node 6: [30, 6, 55]


            \--Node 4: [10, 4, 85]



Case 2:
Enter the elements in sorted (Descending Order): 30 25 20 10 5 3 2
Enter the target sum: 30
Solution 1: [1, 0, 0, 0, 0, 0, 0]
Solution 2: [0, 0, 1, 1, 0, 0, 0]
Solution 3: [0, 0, 1, 0, 1, 1, 1]

Total Solutions: 3

State Space Tree


        /--Node 4: [0, 3, 40]


                /--Node 7: [20, 5, 10]


                    \--Node 8: [25, 6, 5]


                        \--Node 9: [28, 7, 2]


                            \--Node 10: [30, 8, 0]


            \--Node 5: [20, 4, 20]


                \--Node 6: [30, 5, 10]


    /--Node 3: [0, 2, 65]


|--Node 1: [0, 1, 95]


    \--Node 2: [30, 2, 65]



Case 3:
Enter the elements in random Order: 3 30 25 20 5 2 10
Enter the target sum: 30
Solution 1: [0, 1, 0, 0, 0, 0, 0]
Solution 2: [0, 0, 0, 1, 0, 0, 1]

Total Solutions: 2

State Space Tree


            /--Node 5: [0, 4, 37]


                        /--Node 9: [20, 7, 10]


                            \--Node 10: [30, 8, 0]


                    /--Node 8: [20, 6, 12]


                \--Node 6: [20, 5, 17]


                    \--Node 7: [25, 6, 12]


        /--Node 4: [0, 3, 62]


    /--Node 2: [0, 2, 92]
               

        \--Node 3: [30, 3, 62]


|--Node 1: [0, 1, 95]

*/