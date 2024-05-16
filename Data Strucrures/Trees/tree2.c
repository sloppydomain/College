// //Q
// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     struct node *link;
//     int data;
// };
// struct TreeNode
// {
//     struct TreeNode *left;
//     int data;
//     struct TreeNode *right;
// };
// struct TreeNode *createNode(int n)
// {
//     struct TreeNode *p;
//     p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     p->data = n;
//     p->left = NULL;
//     p->right = NULL;
//     return p;
// }
// struct node *insert(struct node *, int);
// void Display(struct node *start)
// {
//     struct node *p = start;
//     if (start == NULL)
//     {
//         printf("List is empty. \n");
//         exit(0);
//     }
//     while (p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->link;
//     }
// }
// struct node *insertll(struct node *head, int n)
// {
//     struct node *root = (struct node *)malloc(sizeof(struct node));
//     root->data = n;
//     if (head == NULL)
//     {
//         root->link = NULL;
//         head = root;
//         return head;
//     }
//     struct node *p = head;
//     while (p->link != NULL)
//         p = p->link;
//     p->link = root;
//     root->link = NULL;
//     return head;
// }
// struct TreeNode *inserttree(struct TreeNode *p, int d)
// {
//     struct TreeNode *root, *par = NULL;
//     struct TreeNode *ptr = p;
//     while (ptr != NULL)
//     {
//         par = ptr;
//         if (d < ptr->data)
//             ptr = ptr->left;
//         else if (d > ptr->data)
//             ptr = ptr->right;
//         else
//         {
//             printf("Duplicate element\n");
//             return p;
//         }
//     }
//     root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     root->data = d;
//     root->left = NULL;
//     root->right = NULL;
//     if (par == NULL)
//         p = root;
//     else if (par->data < d)
//         par->right = root;
//     else
//         par->left = root;
//     return p;
// }
// struct TreeNode *search(struct TreeNode *root, int n)
// {
//     if (root == NULL)
//     {
//         printf("Element not present\n");
//         return root;
//     }
//     else if (n > root->data)
//         return search(root->right, n);
//     else if (n < root->data)
//         return search(root->left, n);
//     else
//         return root;
// }
// void in(struct TreeNode *root)
// {
//     if (root == NULL)
//         return;
//     in(root->left);
//     printf("%d ", root->data);
//     in(root->right);
// }
// void pre(struct TreeNode *root)
// {
//     if (root == NULL)
//         return;
//     printf("%d ", root->data);
//     pre(root->left);
//     pre(root->right);
// }
// void post(struct TreeNode *root)
// {
//     if (root == NULL)
//         return;
//     post(root->left);
//     post(root->right);
//     printf("%d ", root->data);
// }
// struct TreeNode *min(struct TreeNode *root)
// {
//     if (root->left == NULL)
//         return root;
//     else
//     {
//         return min(root->left);
//     }
// }
// struct TreeNode *max(struct TreeNode *root)
// {
//     if (root->right == NULL)
//         return root;
//     else
//     {
//         return max(root->right);
//     }
// }
// struct TreeNode *del(struct TreeNode *root, int dkey)
// {
//     struct TreeNode *par, *ptr, *child, *succ, *parsucc;
//     ptr = root;
//     par = NULL;
//     while (ptr != NULL)
//     {

//         if (dkey == ptr->data)
//             break;

//         par = ptr;
//         if (dkey < ptr->data)
//             ptr = ptr->left;

//         else

//             ptr = ptr->right;
//     }
//     if (ptr == NULL)
//     {

//         printf("%d not present in the tree", dkey);
//         return root;
//     }

//     if (ptr->left != NULL && ptr->right != NULL)
//     {

//         parsucc = ptr;
//         succ = ptr->right;
//         while (succ->left != NULL)
//         {
//             parsucc = succ;
//             succ = succ->left;
//         }
//         ptr->data = succ->data;
//         ptr = succ;
//         par = parsucc;
//     }
//     if (ptr->left != NULL)
//         child = ptr->left;

//     else

//         child = ptr->right;

//     if (par == NULL)
//         root = child;
//     else if (par->left == ptr)
//         par->left = child;

//     else

//         par->right = child;

//     free(ptr);
//     return root;
// }
// int main()
// {
//     int data;
//     struct node *head;
//     int skey;
//     struct TreeNode *root = NULL;
//     head = NULL;
//     int m, n;
//     printf("Enter the number of terms : ");
//     scanf("%d", &m);
//     for (int i = 0; i < m; i++)
//     {
//         printf("Enter term %d : ", i + 1);
//         scanf("%d", &n);
//         head = insertll(head, n);
//     }
//     printf("\n");
//     printf("Given list is : ");
//     Display(head);
//     printf("\n");
//     struct node *p = head;
//     while (p != NULL)
//     {
//         root = inserttree(root, p->data);
//         p = p->link;
//     }
//     int choice;
//     while (1)
//     {
//         printf("\n1. Insert a new element\n");
//         printf("2. Delete an element\n");
//         printf("3. Search an element\n");
//         printf("4. Inorder Traversal\n");
//         printf("5. Preorder Traversal\n");
//         printf("6. Postorder Traversal\n");
//         printf("7. Maximum Element\n");
//         printf("8. Minimum Element\n");
//         printf("9. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             printf("Enter element to be inserted : ");
//             scanf("%d", &data);
//             root = inserttree(root, data);
//             break;
//         case 2:
//             printf("Enter element to be inserted : ");
//             scanf("%d", &data);
//             root = del(root, data);
//             break;
//         case 3:
//             printf("\nEnter element to search : ");
//             scanf("%d", &skey);
//             if (search(root, skey))
//                 printf("Element is present.\n");
//             break;
//         case 4:
//             printf("\nPostorder Traversal : ");
//             post(root);
//             break;
//         case 5:
//             printf("\nPreorder Traversal : ");
//             pre(root);
//             break;
//         case 6:
//             printf("\nInorder Traversal : ");
//             in(root);
//             break;
//         case 7:
//             printf("\n\nMaximum element is : %d", max(root)->data);
//             break;
//         case 8:
//             printf("\nnMinimum element is : %d", min(root)->data);
//             break;
//         case 9:
//             printf("Exiting the program.\n");
//             exit(0);
//         default:
//             printf("Invalid choice. Please try again.\n");
//         }
//     }
//     return 0;
// }
// /*
// OUTPUT - 
// Enter the number of terms : 6 
// Enter term 1 : 12
// Enter term 2 : 34
// Enter term 3 : 56
// Enter term 4 : 32
// Enter term 5 : 11
// Enter term 6 : 7

// Given list is : 12 34 56 32 11 7 

// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 1
// Enter element to be inserted : 99

// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 4

// Postorder Traversal : 7 11 32 99 56 34 12
// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 5

// Preorder Traversal : 12 11 7 34 32 56 99
// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 6

// Inorder Traversal : 7 11 12 32 34 56 99
// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 2
// Enter element to be inserted : 34

// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 5

// Preorder Traversal : 12 11 7 56 32 99
// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 7


// Maximum element is : 99
// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 8

// nMinimum element is : 7
// 1. Insert a new element
// 2. Delete an element
// 3. Search an element
// 4. Inorder Traversal
// 5. Preorder Traversal
// 6. Postorder Traversal
// 7. Maximum Element
// 8. Minimum Element
// 9. Exit
// Enter your choice: 9
// Exiting the program.
// */


// //CONLUSION - IMPLEMENTATION OF BINARY SEARCH TREES AND THE LISTED OPERATIONS WERE SUCCESSFULLY PERFORMED...