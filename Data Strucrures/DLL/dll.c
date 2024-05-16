//Q1
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *create_list(struct node *);
void Display(struct node *);
struct node *insertempty(struct node *, int);
struct node *addatend(struct node *, int);
struct node *Delete(struct node *);
struct node *Delete1(struct node *, int);
struct node *Delete2(struct node *, int);
struct node *reverse(struct node *);
struct node *swap(struct node *);

int main()
{
    int choice, n;
    struct node *head;
    head = create_list(head);
    while (1)
    {
        printf("\n1. Add Node\n");
        printf("2. Delete\n");
        printf("3. Reverse\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value of data to be inserted : ");
            scanf("%d", &n);
            head = addatend(head, n);
            break;
        case 2:
            head = Delete(head);
            break;
        case 3:
            head = reverse(head);
            break;
        case 4:
            Display(head);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        }
    }
    return 0;
}

struct node *create_list(struct node *head)
{
    int n, data;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    head = NULL;
    if (n == 0)
        return head;
    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    head = insertempty(head, data);
    for (int i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        head = addatend(head, data);
    }
    return head;
}

struct node *insertempty(struct node *head, int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    head = p;
    return head;
}

struct node *addatend(struct node *head, int data)
{
    struct node *p, *t;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    t = head;
    if (t == NULL)
    {
        p->prev = NULL;
        p->next = NULL;
        head = p;
    }
    else
    {
        while (t->next != NULL)
            t = t->next;
        t->next = p;
        p->prev = t;
        p->next = NULL;
    }
    return head;
}

struct node *reverse(struct node *head)
{
    printf("List before reversing : ");
    Display(head);
    struct node *p1, *p2;
    p1 = head;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    printf("\nList after reversing : ");
    Display(head);
    return head;
}

void Display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *p = head;
    printf("\nElements of the list are : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct node *Delete(struct node *head)
{
    int choice, n;
    Display(head);
    while (1)
    {
        printf("\n1. Delete by value\n");
        printf("2. Delete by position\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value of element : ");
            scanf("%d", &n);
            head = Delete1(head, n);
            break;
        case 2:
            printf("Enter positiion of element to be deleted : ");
            scanf("%d", &n);
            head = Delete2(head, n);
            break;
        case 3:
            Display(head);
            break;
        case 4:
            printf("Exiting...\n");
            goto jump;
        }
    }
jump:
    return head;
}
struct node *Delete1(struct node *head, int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    struct node *p;
    if (head->next == NULL)
    {
        if (head->data == data)
        {
            p = head;
            head = NULL;
            free(p);
            printf("Element %d deleted successfully\n", data);
            return head;
        }
        else
        {
            printf("Element %d not found\n", data);
            return head;
        }
    }
    if (head->data == data)
    {
        p = head;
        head = head->next;
        head->prev = NULL;
        free(p);
        printf("Element %d deleted successfully\n", data);
        return head;
    }
    p = head->next;
    while (p->next != NULL)
    {
        if (p->data == data)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            printf("Element %d deleted successfully\n", data);
            return head;
        }
        p = p->next;
    }
    if (p->data == data)
    {
        p->prev->next = NULL;
        free(p);
        printf("Element %d deleted successfully\n", data);
        return head;
    }
    printf("Element %d not found\n", data);
    return head;
}
struct node *Delete2(struct node *head, int i_)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    struct node *p = head;
    if (i_ == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(p);
        printf("Element at position %d deleted successfully\n", i_);
        Display(head);
        return head;
    }
    for (int i = 1; i < (i_ - 1); i++)
    {
        p = p->next;
    }
    if (p == NULL || p->next == NULL)
    {
        printf("No element at %d position\n", i_);
        return head;
    }
    int y;
    struct node *t = p->next;
    p->next = t->next;
    if (t->next != NULL)
        t->next->prev = p;
    y = t->data;
    free(t);
    printf("Element %d at position %d deleted successfully\n", y, i_);
    Display(head);
    return head;
}
/*
OUTPUT - 

Enter the number of elements : 5
Enter the element to be inserted : 2
Enter the element to be inserted : 3
Enter the element to be inserted : 4
Enter the element to be inserted : 5
Enter the element to be inserted : 6

1. Add Node
2. Delete
3. Reverse
4. Display
5. Exit
Enter choice : 1
Enter value of data to be inserted : 77

1. Add Node
2. Delete
3. Reverse
4. Display
5. Exit
Enter choice : 4

Elements of the list are : 2 3 4 5 6 77 

1. Add Node
2. Delete
3. Reverse
4. Display
5. Exit
Enter choice : 2

Elements of the list are : 2 3 4 5 6 77 

1. Delete by value
2. Delete by position
3. Display
4. Exit
Enter choice : 1
Enter value of element : 4
Element 4 deleted successfully

1. Delete by value
2. Delete by position
3. Display
4. Exit
Enter choice : 3

Elements of the list are : 2 3 5 6 77

1. Delete by value
2. Delete by position
3. Display
4. Exit
Enter choice : 2
Enter positiion of element to be deleted : 4
Element 6 at position 4 deleted successfully

Elements of the list are : 2 3 5 77

1. Delete by value
2. Delete by position
3. Display
4. Exit
Enter choice : 3

Elements of the list are : 2 3 5 77

1. Delete by value
2. Delete by position
3. Display
4. Exit
Enter choice : 4
Exiting...

1. Add Node
2. Delete
3. Reverse
4. Display
5. Exit
Enter choice : 3
List before reversing :
Elements of the list are : 2 3 5 77

List after reversing :
Elements of the list are : 77 5 3 2

1. Add Node
2. Delete
3. Reverse
4. Display
5. Exit
Enter choice : 4

Elements of the list are : 77 5 3 2

1. Add Node
2. Delete
3. Reverse
4. Display
5. Exit
Enter choice : 5
Exiting...
*/