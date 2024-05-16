//Q
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    struct node *link;
    int data;
};
struct TreeNode
{
    struct TreeNode *left;
    bool lthread;
    int data;
    struct TreeNode *right;
    bool rthread;
};
struct TreeNode *insert(struct TreeNode *root, int x)
{
    struct TreeNode *tmp, *ptr, *par;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (x == ptr->data)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (x > ptr->data)
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
            {
                break;
            }
        }
        else
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
            {
                break;
            }
        }
    }
    if (found)
    {
        printf("Duplicate element\n");
        return root;
    }
    else
    {
        tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        tmp->data = x;
        tmp->rthread = true;
        tmp->lthread = true;
        if (par == NULL)
        {
            tmp->left = NULL;
            tmp->right = NULL;
            root = tmp;
        }
        else if (x > par->data)
        {
            tmp->right = par->right;
            tmp->left = par;
            par->rthread = false;
            par->right = tmp;
        }
        else
        {
            tmp->left = par->left;
            tmp->right = par;
            par->lthread = false;
            par->left = tmp;
        }
    }
    return root;
}
struct TreeNode *succ(struct TreeNode *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;
    else
    {
        ptr = ptr->right;
        while (ptr->lthread == false)
            ptr = ptr->left;
        return ptr;
    }
}
struct TreeNode *pred(struct TreeNode *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    else
    {
        ptr = ptr->left;
        while (ptr->lthread == false)
            ptr = ptr->right;
        return ptr;
    }
}
struct TreeNode *delete(struct TreeNode *root, int x)
{
    struct TreeNode *par, *ptr;
    bool found = false;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (x == ptr->data)
        {
            found = true;
            break;
        }
        par = ptr;
        if (x > ptr->data)
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
            {
                break;
            }
        }
        else
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
            {
                break;
            }
        }
    }
    if (!found)
    {
        printf("Element not found\n");
        return root;
    }
    if (ptr->lthread == true && ptr->rthread == true)
    {
        if (par == NULL)
        {
            free(ptr);
            return NULL;
        }
        else if (par->left == ptr)
        {
            par->lthread = true;
            par->left = ptr->left;
        }
        else
        {
            par->rthread = true;
            par->right = ptr->right;
        }
        struct TreeNode *s = succ(ptr);
        struct TreeNode *p = pred(ptr);
        if (p != NULL)
            p->right = s;
        if (s != NULL)
            s->left = p;
        free(ptr);
        return root;
    }
    else if (ptr->lthread == true)
    {
        if (par == NULL)
            root = ptr->right;
        else if (par->left == ptr)
            par->left = ptr->right;
        else
            par->right = ptr->right;
        struct TreeNode *s = succ(ptr);
        s->left = ptr->left;
        free(ptr);
        return root;
    }
    else if (ptr->rthread == true)
    {
        if (par == NULL)
            root = ptr->left;
        else if (par->left == ptr)
            par->left = ptr->left;
        else
            par->right = ptr->left;
        struct TreeNode *p = pred(ptr);
        p->right = ptr->right;
        free(ptr);
        return root;
    }
    struct TreeNode *s = succ(ptr);
    ptr->data = s->data;
    ptr->right = delete (ptr->right, s->data);
    ptr->rthread = true;
    return root;
}
bool search(struct TreeNode *root, int x)
{
    struct TreeNode *ptr, *par;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == x)
        {
            return true;
        }
        par = ptr;
        if (x > ptr->data)
        {
            if (ptr->rthread == false)
            {
                ptr = ptr->right;
            }
            else
            {
                return false;
            }
        }
        else if (x < ptr->data)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
            {
                return false;
            }
        }
    }
}
void inorder(struct TreeNode *root)
{
    struct TreeNode *p = root;
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while (p->lthread == false)
    {
        p = p->left;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = succ(p);
    }
}
void postorder(struct TreeNode *root)
{
    struct TreeNode *p = root;
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        if (p->lthread == false)
            p = p->left;
        else if (p->rthread == false)
            p = p->right;
        else
        {
            while (p != NULL && p->rthread == true)
                p = p->right;
            if (p != NULL)
                p = p->right;
        }
    }
}
int main()
{
    struct TreeNode *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted : ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter element to be deleted : ");
            scanf("%d", &data);
            root = delete (root, data);
            break;
        case 3:
            printf("Enter element to be searched : ");
            scanf("%d", &data);
            if (search(root, data))
                printf("Element is present\n");
            else
                printf("Element not present\n");
            break;
        case 4:
            printf("Inorder TRaversal : ");
            inorder(root);
            break;
        case 5:
            printf("Postorder Traversal : ");
            postorder(root);
            break;
        case 6:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
/*
OUTPUT - 
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 1
Enter element to be inserted : 23

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 1
Enter element to be inserted : 34

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 1
Enter element to be inserted : 2

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 1
Enter element to be inserted : 1

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 1
Enter element to be inserted : 56

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 1
Enter element to be inserted : 78

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 1
Enter element to be inserted : 50

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 4
Inorder TRaversal : 1 2 23 34 50 56 78
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 2
Enter element to be deleted : 56

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 4
Inorder TRaversal : 1 2 23 34 50 78
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 2
Enter element to be deleted : 78

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 4
Inorder TRaversal : 1 2 23 34 50
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 2
Enter element to be deleted : 2

1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 4
Inorder TRaversal : 1 23 34 50
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 5
Postorder Traversal : 23 1 34 50
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 5
Postorder Traversal : 23 1 34 50
1. Insert
2. Delete
3. Search
4. Inorder Traversal
5. postorder Traversal
6. Exit
Enter Choice : 6
Exiting program...
*/


//CONCLUSION - IMPLEMENTAION OF THREADED BINARY SEARCH TREES AND THE LISTED OPERATIONS WERE SUCCESSFULLY PERFORMED.....