//Q
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
    {
        return b;
    }
}

struct node
{
    struct node *link;
    int data;
};

struct TreeNode
{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
};

struct TreeNode *createNode(int n)
{
    struct TreeNode *p;
    p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = n;
    p->right = NULL;
    p->left = NULL;
    return p;
}

struct node *insertll(struct node *head, int n)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = n;
    if (head == NULL)
    {
        t->link = NULL;
        head = t;
        return head;
    }
    struct node *p = head;
    while (p->link != NULL)
        p = p->link;
    p->link = t;
    t->link = NULL;
    return head;
}

struct TreeNode *create_in_post(struct node *inptr, struct node *postptr, int num)
{
    int i, j;
    struct node *p, *q;
    struct TreeNode *t;
    if (num == 0)
        return NULL;
    p = postptr;
    for (int i = 1; i < num; i++)
        p = p->link;
    t = createNode(p->data);
    if (num == 1)
        return t;
    q = inptr;
    for (i = 0; q->data != p->data; i++)
        q = q->link;
    t->left = create_in_post(inptr, postptr, i);
    for (j = 1; j <= i; j++)
        postptr = postptr->link;
    t->right = create_in_post(q->link, postptr, num - i - 1);
    return t;
}

int height(struct TreeNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = height(node->left);
        int rDepth = height(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void levelorder(struct TreeNode *root, int n)
{
    if (root == NULL)
        return;
    if (n == 1)
        printf("%d ", root->data);
    else if (n > 1)
    {
        levelorder(root->left, n - 1);
        levelorder(root->right, n - 1);
    }
}

int depth(struct TreeNode *root, int x)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    int d = -1;
    if (root->data == x || (d = depth(root->left, x)) != -1 || (d = depth(root->right, x)) != -1)
        return d + 1;
    return d;
}

int main()
{
    struct TreeNode *root = NULL;
    struct node *inptr = NULL;
    struct node *postptr = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        if (scanf("%d", &data) != 1)
        {
            printf("Invalid input. Please enter integers.\n");
            continue;
        }
        inptr = insertll(inptr, data);
    }

    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        if (scanf("%d", &data) != 1)
        {
            printf("Invalid input. Please enter integers.\n");
            continue;
        }
        postptr = insertll(postptr, data);
    }

    root = create_in_post(inptr, postptr, n);

    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Display Height of the Tree (Recursive)\n");
        printf("2. Perform Level-Order Traversal (Recursive)\n");
        printf("3. Find Depth of a Node (Recursive)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Height of the tree (Recursive): %d\n", height(root));
            break;
        }
        case 2:
        {
            int height1 = height(root);
            printf("Level-Order Traversal (Recursive):\n");
            for (int i = 1; i <= height1; i++)
            {
                levelorder(root, i);
                printf("\n");
            }
            break;
        }
        case 3:
        {
            int data;
            printf("Enter the node data to find its depth: ");
            scanf("%d", &data);
            int d = depth(root, data);
            if (d == -1)
                printf("Node not found in the tree.\n");
            else
                printf("Depth of node %d (Recursive): %d\n", data, d);
            break;
        }
        case 4:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    while (inptr != NULL)
    {
        struct node *temp = inptr;
        inptr = inptr->link;
        free(temp);
    }
    while (postptr != NULL)
    {
        struct node *temp = postptr;
        postptr = postptr->link;
        free(temp);
    }

    return 0;
}
/*
OUTPUT - 
Enter the number of nodes: 5
Enter inorder traversal: 6 8 7 9 3
Enter postorder traversal: 6 7 8 3 9

Menu:
1. Display Height of the Tree (Recursive)
2. Perform Level-Order Traversal (Recursive)
3. Find Depth of a Node (Recursive)
4. Exit
Enter your choice: 2
Level-Order Traversal (Recursive):
9 
8 3
6 7

Menu:
1. Display Height of the Tree (Recursive)
2. Perform Level-Order Traversal (Recursive)
3. Find Depth of a Node (Recursive)
4. Exit
Enter your choice: 1
Height of the tree (Recursive): 3

Menu:
1. Display Height of the Tree (Recursive)
2. Perform Level-Order Traversal (Recursive)
3. Find Depth of a Node (Recursive)
4. Exit
Enter your choice: 3
Enter the node data to find its depth: 8
Depth of node 8 (Recursive): 1

Menu:
1. Display Height of the Tree (Recursive)
2. Perform Level-Order Traversal (Recursive)
3. Find Depth of a Node (Recursive)
4. Exit
Enter your choice: 4
Exiting the program.
*/


//CONLUSION - IMPLEMENTATION OF BINARY TREES AND THE LISTED OPERATIONS WERE SUCCESSFULLY PERFORMED...