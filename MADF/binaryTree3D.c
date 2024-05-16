#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

void printBinaryTree(TreeNode* root, int depth, char edge) {
    if (root == NULL) {
        printSpaces(4 * depth);
        printf("~\n");
        return;
    }
    printBinaryTree(root->right, depth + 1, '/');
    printSpaces(4 * depth);
    printf("%c--%d\n", edge, root->data);
    printBinaryTree(root->left, depth + 1, '\\');
}

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("Binary Tree with Edges:\n");
    printBinaryTree(root, 0, '|');
    return 0;
}
