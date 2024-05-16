//Q2
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

void Display(struct node *);
struct node *insertempty(struct node *, int);
struct node *addatend(struct node *, int);
struct node *swap(struct node *);

int main()
{
    struct node *head = NULL;
    head = insertempty(head, 2);
    head = addatend(head, 4);
    head = addatend(head, 6);
    head = addatend(head, 8);
    head = addatend(head, 0);
    head = addatend(head, 2);
    printf("List Before swapping adjacent nodes : ");
    Display(head);
    head = swap(head);
    printf("List after swapping adjacent nodes : ");
    Display(head);
    return 0;
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

void Display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct node *swap(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("List is empty or contains only one element, no swap needed.\n");
        return head;
    }
    struct node *p1, *p2;
    p1 = head;
    p2 = p1->next;
    while (p1 != NULL && p2 != NULL)
    {
        p1->next = p2->next;
        p2->prev = p1->prev;
        p1->prev = p2;
        p2->next = p1;

        if (p1->next != NULL)
            p1->next->prev = p1;
        if (p2->prev == NULL)
            head = p2;
        else
            p2->prev->next = p2;

        p1 = p1->next;
        if (p1 != NULL)
            p2 = p1->next;
    }
    return head;
}
/*
OUTPUT - 
List Before swapping adjacent nodes : 2 4 6 8 0 2 
List after swapping adjacent nodes : 4 2 8 6 2 0 
*/