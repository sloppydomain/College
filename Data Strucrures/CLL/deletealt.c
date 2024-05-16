// Q4
#include <stdio.h>
#include <stdlib.h>
#define MEM_ALOC (struct node *)malloc(sizeof(struct node))
struct node
{
    int data;
    struct node *link;
};
void Display(struct node *);
struct node *create_list(struct node *, int);
struct node *insert_emptylist(struct node *, int);
struct node *insertatend(struct node *, int);
struct node *deletealt(struct node *);
int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    struct node *last = NULL;
    last = create_list(last, n);
    printf("\nList before removing alternate elements : ");
    Display(last);
    last = deletealt(last);
    printf("\nList after removing alternate elements : ");
    Display(last);
    return 0;
}
void Display(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty. \n");
        exit(0);
    }
    struct node *p = start->link;
    do
    {
        printf("%d ", p->data);
        p = p->link;
    } while (p != start->link);
}
struct node *create_list(struct node *start, int n)
{
    int item;
    if (start == NULL)
    {
        printf("List is empty.\nEnter data to be inserted at node 1 : ");
        scanf("%d", &item);
        start = insert_emptylist(start, item);
    }
    else if (n == 0)
        return start;
    struct node *p = start;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter element to be inserted at node %d : ", i);
        scanf("%d", &item);
        start = insertatend(start, item);
    }
    return start;
}
struct node *insert_emptylist(struct node *start, int item)
{
    if (start != NULL)
    {
        printf("List is not empty\n");
        exit(0);
    }
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->link = p;
    start = p;
    return start;
}
struct node *insertatend(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("List is empty...\n");
        exit(1);
    }
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->link = start->link;
    start->link = p;
    start = p;
    return start;
}
struct node *deletealt(struct node *head)
{
    if (head == NULL || head->link == head)
    {
        return head;
    }

    struct node *p1 = head->link;
    struct node *p2;

    while (p1 != head)
    {
        p2 = p1->link;
        if(p2 == head)
        {
            head = p1;
            head->link = p2->link;
            free(p2);
            return head;
        }
        p1->link = p2->link;
        free(p2);
        p1 = p1->link;
    }

    return head;
}
/*
OUTPUT - 
Enter the number of elements : 6
List is empty.
Enter data to be inserted at node 1 : 2 
Enter element to be inserted at node 2 : 4
Enter element to be inserted at node 3 : 5
Enter element to be inserted at node 4 : 6
Enter element to be inserted at node 5 : 55
Enter element to be inserted at node 6 : 44

List before removing alternate elements : 2 4 5 6 55 44 
List after removing alternate elements : 2 5 55 
*/



