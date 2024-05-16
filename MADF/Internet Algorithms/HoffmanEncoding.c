/*
    author - Yash Malviya
    title  - Hoffman Encoding
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define M 1000
#define nline printf("\n")

struct TreeNode {
    int freq;
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
};

int it = 0;
void restoreDown(struct TreeNode **Trees, int i, int n) {
    int l = 2 * i;
    int r = l + 1;
    struct TreeNode *ok = Trees[i];
    while (l <= n) {
        int minChild;
        if (r <= n && (Trees[r]->freq < Trees[l]->freq || (Trees[r]->freq == Trees[l]->freq && (int)Trees[r]->ch < (int)Trees[l]->ch))) {
            minChild = r;
        }
        else {
            minChild = l;
        }
        if (ok->freq < Trees[minChild]->freq)             // ok is at correct position
            break;
        if(ok->freq == Trees[minChild]->freq) {            // ok has frequency equal to minchild ans ascii is small so at correct position
            if((int)ok->ch < (int)Trees[minChild]->ch) {
                break;
            }
        }
        Trees[i] = Trees[minChild];
        i = minChild;
        l = 2 * i;
        r = l + 1;
    }
    Trees[i] = ok;
}

struct TreeNode *del_min(struct TreeNode **a, int *n) {
    struct TreeNode *min = a[1];
    a[1] = a[*n];
    (*n)--;
    restoreDown(a, 1, *n);
    return min;
}

void heapify(struct TreeNode **a, int n) {
    for (int i = n / 2; i >= 1; i--)
        restoreDown(a, i, n);
}

void printHeap(struct TreeNode **Trees, int size1) {
    struct TreeNode **copy = (struct TreeNode **)malloc((size1 + 1) * sizeof(struct TreeNode *));
    memcpy(copy, Trees, (size1 + 1) * sizeof(struct TreeNode *));
    printf("\n");
    printf("Iteration %d: ", ++it);
    while (size1 >= 1) {
        struct TreeNode *temp = del_min(copy, &size1);
        if (temp->ch == ' ') {
            printf("(' ', %d)", temp->freq);
        } else {
            printf("(%c, %d)", temp->ch, temp->freq);
        }
        if (size1 != 0) {
            printf(", ");
        }
    }
    free(copy);
}

void dfsCodes(struct TreeNode *root, int path[], int len) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < len; i++)
            printf("%d", path[i]);
        if(root->ch == ' ') {
            printf("\t -> ' '\n");
        } else {
            printf("\t -> %c\n", root->ch);
        }
    }
    path[len] = 0;
    dfsCodes(root->left, path, len + 1);
    path[len] = 1;
    dfsCodes(root->right, path, len + 1);
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

void dfsPrint(struct TreeNode* root, int depth, char edge) {
    if (root == NULL) {
        printSpaces(4 * depth);
        printf("\n");
        return;
    }
    dfsPrint(root->right, depth + 1, '/');
    printSpaces(4 * depth);
    if(root->ch == '#') {
        printf("%c--*", edge);
    } else {
        printf("%c--%c", edge, root->ch);
    }
    printf("(%d)", root->freq);
    dfsPrint(root->left, depth + 1, '\\');
}

void Hoffman(struct TreeNode **Trees, int size) {
    int p = size;
    while (size >= 1) {
        heapify(Trees, size);
        printHeap(Trees, size);
        struct TreeNode *a = del_min(Trees, &size);
        heapify(Trees, size);   
        if(size == 0) {
            printf("\n\nHuffman Tree:\n");
            dfsPrint(a, 0, '|');
            nline;
            printf("\nHuffman Codes:\n");
            int path[p];
            dfsCodes(a, path, 0);
            break;
        }
        struct TreeNode *b = del_min(Trees, &size);
        heapify(Trees, size);
        struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        temp->freq = a->freq + b->freq;
        temp->ch = '~';
        temp->left = a;
        temp->right = b;
        size++;
        Trees[size] = temp;
    }
}

int main() {
    char text[M];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    for(int i = 0; i < M; i++) {
        if(text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }
    char freq[128] = {0};
    for(int i = 0; i < strlen(text); i++) {
        freq[(int)(text[i])]++;
    }
    int size = 0;
    for(int i = 0; i < 128; i++) {              // Only 128 (ASCII Codes from 0 to 127) characters are printable
        if(freq[i]) {
            size++;
        }
    }
    int idx = 1;
    struct TreeNode **Trees = (struct TreeNode **)malloc((size + 1) * sizeof(struct TreeNode *));
    for(int i = 0; i < 128; i++) {
        if(freq[i]) {
            Trees[idx] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            Trees[idx]->freq = freq[i];
            Trees[idx]->ch = (char)i;
            Trees[idx]->left = NULL;
            Trees[idx]->right = NULL; 
            idx++;
        }
    }
    printf("Frequencies of characters:\n");
    for(int i = 0; i < 128; i++) {
        if(freq[i]) {
            if((char)i == ' ') {
                printf("[' ' -> %d]\n", freq[i]);
            } else {
                printf("[%c -> %d]\n", i, freq[i]);
            }
        }
    }
    Hoffman(Trees, size);
    free(Trees);
    return 0;
}

/*
OUTPUT:
Enter text: the cub wanted to rub on the tree branch
Frequencies of characters:
[' ' -> 8]
[a -> 2]
[b -> 3]
[c -> 2]
[d -> 1]
[e -> 5]
[h -> 3]
[n -> 3]
[o -> 2]
[r -> 3]
[t -> 5]
[u -> 2]
[w -> 1]

Iteration 1: (d, 1), (w, 1), (a, 2), (c, 2), (o, 2), (u, 2), (b, 3), (h, 3), (n, 3), (r, 3), (e, 5), (t, 5), (' ', 8)
Iteration 2: (a, 2), (c, 2), (o, 2), (u, 2), (~, 2), (b, 3), (h, 3), (n, 3), (r, 3), (e, 5), (t, 5), (' ', 8)
Iteration 3: (o, 2), (u, 2), (~, 2), (b, 3), (h, 3), (n, 3), (r, 3), (~, 4), (e, 5), (t, 5), (' ', 8)
Iteration 4: (~, 2), (b, 3), (h, 3), (n, 3), (r, 3), (~, 4), (~, 4), (e, 5), (t, 5), (' ', 8)
Iteration 5: (h, 3), (n, 3), (r, 3), (~, 4), (~, 4), (e, 5), (t, 5), (~, 5), (' ', 8)
Iteration 6: (r, 3), (~, 4), (~, 4), (e, 5), (t, 5), (~, 5), (~, 6), (' ', 8)
Iteration 7: (~, 4), (e, 5), (t, 5), (~, 5), (~, 6), (~, 7), (' ', 8)
Iteration 8: (t, 5), (~, 5), (~, 6), (~, 7), (' ', 8), (~, 9)
Iteration 9: (~, 6), (~, 7), (' ', 8), (~, 9), (~, 10)
Iteration 10: (' ', 8), (~, 9), (~, 10), (~, 13)
Iteration 11: (~, 10), (~, 13), (~, 17)
Iteration 12: (~, 17), (~, 23)
Iteration 13: (~, 40)

Huffman Tree:

                    /--c(2)
                /--~(4)
                    \--a(2)
            /--~(7)
                \--r(3)
        /--~(13)
                /--n(3)
            \--~(6)
                \--h(3)                    
    /--~(23)
                /--b(3)
            /--~(5)
                    /--w(1)
                \--~(2)                        
                    \--d(1)
        \--~(10)
            \--t(5)
|--~(40)
            /--e(5)
        /--~(9)
                /--u(2)
            \--~(4)
                \--o(2)
    \--~(17)
        \-- (8)


Huffman Codes:
00       -> ' '
0100     -> o
0101     -> u
011      -> e
100      -> t
10100    -> d
10101    -> w
1011     -> b
1100     -> h
1101     -> n
1110     -> r
11110    -> a
11111    -> c
*/