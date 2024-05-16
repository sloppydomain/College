// Q
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct t
{
    struct t *left;
    int val;
    struct t *right;
    int balance;
};

struct t *leftRotate(struct t *pptr)
{
    struct t *aptr;
    aptr = pptr->right;
    pptr->right = aptr->left;
    aptr->left = pptr;
    return aptr;
}
struct t *rightRotate(struct t *pptr)
{
    struct t *aptr;
    aptr = pptr->left;
    pptr->left = aptr->right;
    aptr->right = pptr;
    return aptr;
}

struct t *del(struct t *, int);
struct t *insert(struct t *pptr, int x);
struct t *insert_right_check(struct t *pptr, int *ptaller);
struct t *insert_RightBalance(struct t *pptr);
struct t *insert_left_check(struct t *pptr, int *ptaller);
struct t *insert_LeftBalance(struct t *pptr);
struct t *del_rightbalance(struct t *pptr, int *pshorter);
struct t *del_left_check(struct t *pptr, int *pshorter);
struct t *del_leftbalance(struct t *pptr, int *pshorter);
struct t *del_right_check(struct t *pptr, int *pshorter);
void search(struct t *ptr, int skey);
void min(struct t *ptr);
void max(struct t *ptr);
void displayTree(struct t *ptr);
void inorder(struct t *);
int main()
{
    struct t *root = NULL;
    int choice, key;

    while (1)
    {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Exit\n");
        printf("7. Inorder Traversal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = del(root, key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(root, key);
            break;
        case 4:
            min(root);
            break;
        case 5:
            max(root);
            break;
        case 6:
            exit(0);
        case 7:
            inorder(root);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
struct t *insert(struct t *pptr, int x) // checked
{
    static int ptaller;
    if (pptr == NULL)
    {
        pptr = (struct t *)malloc(sizeof(struct t));
        pptr->val = x;
        pptr->left = NULL;
        pptr->right = NULL;
        pptr->balance = 0;
        ptaller = true;
    }
    else if (x < pptr->val)
    {
        pptr->left = insert(pptr->left, x);
        if (ptaller)
        {
            pptr = insert_left_check(pptr, &ptaller);
        }
    }
    else if (x > pptr->val)
    {
        pptr->right = insert(pptr->right, x);
        if (ptaller)
        {
            pptr = insert_right_check(pptr, &ptaller);
        }
    }
    else
    {
        printf("Duplicate element\n");
        ptaller = false;
    }
    return pptr;
}

struct t *insert_right_check(struct t *pptr, int *ptaller) // checked
{
    switch (pptr->balance)
    {
    case 1:
        pptr->balance = 0;
        *ptaller = false;
        break;
    case 0:
        pptr->balance = -1;
        break;
    case -1:
        pptr = insert_RightBalance(pptr);
        *ptaller = false;
        break;
    }
    return pptr;
}
struct t *insert_RightBalance(struct t *pptr) // checked
{
    struct t *aptr, *bptr;
    aptr = pptr->right;
    if (aptr->balance == -1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = leftRotate(pptr);
    }
    else
    {
        bptr = aptr->left;
        switch (bptr->balance)
        {
        case -1:
            pptr->balance = 1;
            aptr->balance = 0;
            break;
        case 1:
            pptr->balance = 0;
            aptr->balance = -1;
            break;
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
        }
        bptr->balance = 0;
        pptr->right = rightRotate(aptr);
        pptr = leftRotate(pptr);
    }
    return pptr;
}
struct t *insert_left_check(struct t *pptr, int *ptaller) // checked
{
    switch (pptr->balance)
    {
    case 0:
        pptr->balance = 1;
        *ptaller = false;
        break;
    case -1:
        *ptaller = false;
        pptr->balance = 0;
        break;
    case 1:
        pptr = insert_LeftBalance(pptr);
        *ptaller = false;
        break;
    }
    return pptr;
}
struct t *insert_LeftBalance(struct t *pptr) // checked
{
    struct t *aptr, *bptr;
    aptr = pptr->left;
    if (aptr->balance == 1)
    {
        aptr->balance = 0;
        bptr->balance = 0;
        pptr = rightRotate(pptr);
    }
    else
    {
        bptr = aptr->right;
        switch (bptr->balance)
        {
        case -1:
            pptr->balance = 0;
            aptr->balance = 1;
            break;
        case 1:
            pptr->balance = -1;
            aptr->balance = 0;
            break;
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
        }
        bptr->balance = 0;
        pptr->left = leftRotate(aptr);
        pptr = rightRotate(pptr);
    }
    return pptr;
}
struct t *del_rightBalance(struct t *pptr, int *pshorter) // checked
{
    struct t *bptr, *aptr;
    aptr = pptr->right;
    if (aptr->balance == 0)
    {
        pptr->balance = -1;
        aptr->balance = 1;
        *pshorter = false;
        pptr = leftRotate(pptr);
    }
    else if (aptr->balance == -1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = leftRotate(pptr);
    }
    else
    {
        bptr = aptr->left;
        switch (bptr->balance)
        {
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
            break;
        case 1:
            pptr->balance = 0;
            aptr->balance = -1;
            break;
        case -1:
            pptr->balance = 1;
            aptr->balance = 0;
            break;
        }
        bptr->balance = 0;
        pptr->right = rightRotate(aptr);
        pptr = leftRotate(pptr);
    }
    return pptr;
}

struct t *del_left_check(struct t *pptr, int *pshorter) // checked
{
    switch (pptr->balance)
    {
    case 0:
        pptr->balance = -1;
        *pshorter = false;
        break;
    case 1:
        pptr->balance = 0;
        break;
    case -1:
        pptr = del_rightBalance(pptr, pshorter);
        break;
    }
    return pptr;
}

struct t *del_leftbalance(struct t *pptr, int *pshorter) // checked
{
    struct t *bptr, *aptr;
    aptr = pptr->left;
    if (aptr->balance == 0)
    {
        pptr->balance = 1;
        aptr->balance = -1;
        *pshorter = false;
        pptr = rightRotate(pptr);
    }
    else if (aptr->balance == 1)
    {
        pptr->balance = 0;
        aptr->balance = 0;
        pptr = rightRotate(pptr);
    }
    else
    {
        bptr = aptr->left;
        switch (bptr->balance)
        {
        case 0:
            pptr->balance = 0;
            aptr->balance = 0;
            break;
        case 1:
            pptr->balance = -1;
            aptr->balance = 0;
            break;
        case -1:
            pptr->balance = 0;
            aptr->balance = 1;
            break;
        }
        bptr->balance = 0;
        pptr->left = leftRotate(aptr);
        pptr = rightRotate(pptr);
    }
    return pptr;
}

struct t *del_right_check(struct t *pptr, int *pshorter) // checked
{
    switch (pptr->balance)
    {
    case 0:
        pptr->balance = 1;
        *pshorter = false;
        break;
    case -1:
        pptr->balance = 0;
        break;
    case 1:
        pptr = del_leftbalance(pptr, pshorter);
        break;
    }
    return pptr;
}

struct t *del(struct t *pptr, int dkey) // checked
{
    struct t *tmp, *succ;
    static int shorter;
    if (pptr == NULL)
    {
        printf("Key not present\n");
        shorter = false;
        return pptr;
    }

    if (dkey < pptr->val)
    {
        pptr->left = del(pptr->left, dkey);
        if (shorter == true)
            pptr = del_left_check(pptr, &shorter);
    }
    else if (dkey > pptr->val)
    {
        pptr->right = del(pptr->right, dkey);
        if (shorter == true)
            pptr = del_right_check(pptr, &shorter);
    }
    else
    {
        if (pptr->left != NULL && pptr->right != NULL)
        {
            succ = pptr->right;
            while (succ->left)
                succ = succ->left;
            pptr->val = succ->val;
            pptr->right = del(pptr->right, succ->val);
            if (shorter == true)
                pptr = del_right_check(pptr, &shorter);
        }
        else
        {
            tmp = pptr;
            if (pptr->left != NULL)
                pptr = pptr->left;
            else if (pptr->right != NULL)
                pptr = pptr->right;
            else
                pptr = NULL;
            free(tmp);
            shorter = true;
        }
    }
    return pptr;
}

void search(struct t *ptr, int skey)
{
    static int found = 0;
    if (ptr == NULL && found != 1)
    {
        printf("Key not found\n");
        return;
    }
    else if (skey < ptr->val)
        search(ptr->left, skey);
    else if (skey > ptr->val)
        search(ptr->right, skey);
    else
        found = 1;

    if (found == 1)
    {
        printf("Found element\n");
    }
}

void min(struct t *ptr)
{
    if (ptr == NULL)
    {
        printf("The tree is empty. There is no minimum element.\n");
        return;
    }

    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }

    printf("Minimum element is: %d\n", ptr->val);
}
void max(struct t *ptr)
{
    if (ptr == NULL)
    {
        printf("The tree is empty. There is no maximum element.\n");
        return;
    }

    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }

    printf("Maximum element is: %d\n", ptr->val);
}
void inorder(struct t *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

/*
OUTPUT -
AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 2

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 34

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 56

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 34
Duplicate element

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 78

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 55

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 4

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 3

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 2
Duplicate element

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 3
Enter key to search: 34
Found element

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 1
Enter key to insert: 99

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 7
2 3 4 34 55 56 78 99
AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 4
Minimum element is: 2

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 5
Maximum element is: 99

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 2
Enter key to delete: 55

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 7
2 3 4 34 56 78 99
AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 2
Enter key to delete: 45
Key not present

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 7
2 3 4 34 56 78 99
AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 2
Enter key to delete: 99

AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 7
2 3 4 34 56 78
AVL Tree Operations:
1. Insert
2. Delete
3. Search
4. Find Minimum
5. Find Maximum
6. Exit
7. Inorder Traversal
Enter your choice: 6
*/