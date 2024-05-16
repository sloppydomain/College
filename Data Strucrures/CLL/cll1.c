#include <stdio.h>
#include <stdlib.h>
#define MEM_ALOC (struct node *)malloc(sizeof(struct node))
struct node
{
    int data;
    struct node *link;
};
void Display(struct node *start)
{
    struct node *p = start;
    if (start == NULL)
    {
        printf("List is empty. \n");
        exit(0);
    }
    printf("\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
}
struct node *create_list(struct node *start, int n)
{
    int item;
    if (start == NULL)
    {
        printf("List is empty.\nEnter data to be inserted in first node : ");
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
        return;
    }
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->link = p;
    start = p;
    return start;
}
struct node *insertatbeg(struct node *start, int item)
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
    return start;
}
struct node *insertatend(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->link = start->link;
    start->link = p;
    return start;
}
struct node *insertafter(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("List is empty...\n");
        exit(1);
    }
    struct node *p = start->link;
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    while (p != start->link)
    {
        if (p->data = item)
        {
            tmp->data = item;
            tmp->link = p->link;
            p->link = tmp;
            if (p == start)
                start = tmp;
        }
        p = p->link;
    }
    printf("%d Not found\n", item);
    exit(1);
}
struct node *addbefore(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("List is empty...\n");
        exit(1);
    }
    struct node *tmp, *p;
    if (start->link->data == item)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = item;
        tmp->link = start->link;
        start->link = tmp;
        free(tmp);
        return start;
    }
    while (p->link != tmp->link)
    {
        if (p->link->data == item)
        {
            tmp = MEM_ALOC;
            tmp->data = item;
            tmp->link = p->link;
            p->link = tmp;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("%d Not found\n", item);
    exit(1);
}
struct node *Delete(struct node *last, int data)
{
    struct node *tmp, *p;
    if (last == NULL)
    {
        printf("List is empty...\n");
        return last;
    }
    if (last->link == last && last->data == data)
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }
    if (last->link->data == data)
    {
        tmp = last->link;
        last->link = tmp->link;
        free(tmp);
        return last;
    }
    p = last->link->link;
    while (p != last)
    {
        if (p->link->data == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }
    if (last->data == data)
    {
        tmp = last->link->link;
        while (tmp->link != last)
        {
            tmp = tmp->link;
        }
        tmp->link = last->link;
        free(last);
        last = tmp;
        return last;
    }
    printf("Element %d not found",data);
    return last;
}
int main()
{
    struct node *last = NULL;
    return 0;
}