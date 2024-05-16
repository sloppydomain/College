#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;
struct node *pop(struct node *start)
{
    struct node *p, *tmp;
    if (start == NULL)
    {
        printf("List is empty..\n");
        exit(1);
    }
    else
    {
        p = start;
        start = p->link;
        free(p);
        return start;
    }
}
struct node *push_emptylist(struct node *start, int item)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->link = start;
    start = p;
    return start;
}
struct node *push(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->link = start;
    start = p;
    return start;
}
struct node *create_stacklist(struct node *start, int n)
{
    int item;
    if (start == NULL)
    {
        printf("List is empty.\nEnter element to be inserted at node 1 : ");
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
        start = insertatbeg(start, item);
    }
    return start;
}
void Display(struct node *start)
{
    struct node *p = start;
    if (start == NULL)
    {
        printf("Stack Underflow \n");
        exit(0);
    }
    printf("\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
}
int peek()
{
    if(top == NULL)
    {
        printf("Stack Underflow \n");
        exit(0);
    }
    return (top->data);
}
int main()
{
    return 0;
}
