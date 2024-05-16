#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void count(struct node *start);
void search_element(struct node *start, int item);
void Display(struct node *start);
struct node *create_list(struct node *start, int n);
struct node *insert_emptylist(struct node *start, int item);
struct node *insertatbeg(struct node *start, int item);
struct node *insertatend(struct node *start, int item);
struct node *reverse(struct node *start);
struct node *insertafternode(struct node *start, int item, int data)
{
    struct node *p, *tmp;
    p = start;
    while (p != NULL)
    {
        if (p->data == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->data = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Item %d not found in list..\n");
    return start;
}
struct node *insertbeforenode(struct node *start, int item, int data)
{
    struct node *p, *tmp;
    if (start == NULL)
    {
        printf("list is empty...\n");
        return start;
    }
    if (start->data == item)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->link = start;
        start = tmp;
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->data == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("Item %d not found in list\n");
    return start;
}
void insertatposition(struct node *start, int data, int n)
{
    struct node *p, *tmp;
    if (start == NULL)
    {
        printf("List is empty..\n");
        return start;
    }
    else if (n == 1)
    {
        start = insertatbeg(start, data);
        return start;
    }
    p = start;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    int pos = 1;
    while (pos != n - 1)
    {
        p = p->link;
        pos++;
    }
    tmp->link = p->link;
    p->link = tmp;
    free(p);
    free(tmp);
}
struct node *delete(struct node *start, int data)
{
    struct node *p, *tmp;
    if (start == NULL)
    {
        printf("List is empty..\n");
        exit(1);
    }
    if (start->data = data)
    {
        p = start;
        start = p->link;
        free(p);
        return start;
    }
    p = start;
    while(p->link != NULL)
    {
        if(p->link->data == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            free(p);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found \n",data);
    return start;
}
int main()
{
    struct node *start = NULL;
    int item, n, choice;
    printf("Enter thee element of first node : ");
    scanf("%d", &item);
    start = create_list(start, n);
    printf("Enter the position of nodes : ");
    scanf("%d", &n);
    insertatposition(start, item, n);
    Display(start);
    start = reverse(start);
    Display(start);

    // start = (struct node *)malloc(sizeof(struct node));
    // printf("Enter data of the first node : ");
    // scanf("%d", &item);
    // start->data = item;
    // start->link = NULL;
    // printf("Enter the number of elements : ");
    // scanf("%d", &n);
    // create_list(start, n);
    // while (1)
    // {
    //     printf("1.Create List\n");
    //     printf("2.Display\n");
    //     printf("3.Count\n");
    //     printf("4.Search\n");
    //     printf("5.Add to begining\n");
    //     printf("6.Add to empty\n");
    //     printf("7.Add at the end\n");
    //     printf("8.Add after the node\n");
    //     printf("9.Add before the node\n");
    //     printf("10.Add at position\n");
    //     printf("11.Delete\n");
    //     printf("12.Reverse\n");
    //     printf("13.Quit\n\n");
    //     printf("Enter the choice : ");
    //     scanf("%d",&choice);
    //     switch(choice)
    //     {
    //         case 1:
    //         printf("Enter the number of nodes : ");
    //         scanf("%d",&n);
    //         start= create_list(start,n);
    //         break;
    //         case 2:
    //         Display(start);
    //         break;
    //         case 3:
    //         break;
    //     }
    // }

    return 0;
}
// void count(struct node*start)
// {
//     struct node*p;
//     int count = 0;
//     p = start;
//     while(p!=NULL)
//     {
//         p = p->link;
//         count++;
//     }
//     printf("Number of element are %d",count);
// }
// void search_element(struct node *start, int item)
// {
//     struct node *p;
//     if (start == NULL)
//     {
//         printf("List is empty. \n");
//         exit(0);
//     }
//     p = start;
//     int count = 1;
//     while (p != NULL)
//     {
//         if (p->data == item)
//         {
//             printf("Item %d found at node %d", item, count);
//             exit(0);
//         }
//         p = p->link;
//         count++;
//     }
//     printf("Element %d not found in the list \n");
//     exit(0);
// }
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
    p->link = start;
    start = p;
    return start;
}
struct node *insertatbeg(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->link = start;
    start = p;
    return start;
}
struct node *insertatend(struct node *start, int item)
{
    if (start == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    struct node *p, *tmp;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    tmp = start;
    while (tmp->link != NULL)
    {
        tmp = tmp->link;
    }
    tmp->link = p;
    p->link = NULL;
    return start;
}
struct node *reverse(struct node *start)
{
    struct node *p, *prev, *next;
    prev = NULL;
    p = start;
    while (p != NULL)
    {
        next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }
    start = prev;
    return start;
}
