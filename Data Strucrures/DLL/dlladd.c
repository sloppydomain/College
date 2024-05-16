#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createList(struct node *, int);
struct node *InsertEnd(struct node *, int);
struct node *InsertEmpty(struct node *, int);
struct node *Add(struct node *, struct node *);
int convertToNum(struct node *);
void Display1(struct node *);
struct node *reverse(struct node *);
void Display(struct node *);

struct node *start3 = NULL;
int carry = 0;

void Display(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *p = start;
    while (p != NULL)
    {
        printf("%d", p->data);
        if(p->next != NULL)
        {
            printf("->");
        }
        p = p->next;
    }
}
void Display1(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *p = start;
    while (p->next != NULL)
        p = p->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
}

int main()
{
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    int n, x1, x2;
    printf("Enter the number 1: ");
    scanf("%d", &x1);
    printf("Enter number 2: ");
    scanf("%d", &x2);
    int t1 = x1;
    while (t1 != 0)
    {
        start1 = InsertEnd(start1, t1 % 10);
        t1 /= 10;
    }
    int t2 = x2;
    while (t2 != 0)
    {
        start2 = InsertEnd(start2, t2 % 10);
        t2 /= 10;
    }
    printf("List 1 contains : ");
    Display(start1);
    printf("\n");
    printf("List 2 contains : ");
    Display(start2);
    start3 = Add(start1, start2);
    printf("\n");
    printf("Adding the two number gives : %d\n", convertToNum(start3));
    printf("List after adding contains : ");
    Display(start3);
    return 0;
}

struct node *InsertEnd(struct node *start, int n)
{
    struct node *p = start;
    if (start == NULL)
    {
        start = InsertEmpty(start, n);
    }
    else
    {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = n;
        tmp->next = NULL;
        while (p->next != NULL)
            p = p->next;
        tmp->prev = p;
        p->next = tmp;
    }
    return start;
}

struct node *InsertEmpty(struct node *start, int n)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = n;
    tmp->prev = NULL;
    tmp->next = start;
    if (start != NULL)
    {
        start->prev = tmp;
    }
    start = tmp;
    return start;
}

struct node *Add(struct node *start1, struct node *start2)
{
    struct node *p1 = start1;
    struct node *p2 = start2;
    int sum, num;
    while (p1 != NULL && p2 != NULL)
    {
        sum = p1->data + p2->data + carry;
        start3 = InsertEnd(start3, sum % 10);
        carry = sum / 10;
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1 != NULL)
    {
        sum = p1->data + carry;
        start3 = InsertEnd(start3, sum % 10);
        carry = sum / 10;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        sum = p2->data + carry;
        start3 = InsertEnd(start3, sum % 10);
        carry = sum / 10;
        p2 = p2->next;
    }
    if (carry > 0)
    {
        start3 = InsertEnd(start3, carry);
    }
    return start3;
}

struct node *reverse(struct node *start)
{
    struct node *p1, *p2;
    p1 = start;
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
    start = p1;
    return start;
}
int convertToNum(struct node *start)
{
    int ans = 0;
    struct node *p = start;
    while (p->next != NULL)
        p = p->next;
    while (p != NULL)
    {
        ans = ans * 10 + (p->data);
        p = p->prev;
    }
    return ans;
}

// OUTPUT -
// Enter the number 1: 2345
// Enter number 2: 9657
// List 1 contains : 5->4->3->2
// List 2 contains : 7->5->6->9
// Adding the two number gives : 12002
// List after adding contains : 2->0->0->2->1
