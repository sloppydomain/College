#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *link;
};
struct node *insertatend(struct node *, int);
struct node *insert_emptylist(struct node *, int);
struct node *Difference_AB(struct node *set1, struct node *set2)
{
    struct node *p1 = set1, *p2 = set2;
    struct node *p3;
    p3 = NULL;
    struct node *q;
    while (p1 != NULL)
    {
        q = p2;
        while (q != NULL)
        {
            if (q->num == p1->num)
                break;
            q = q->link;
        }
        if (q == NULL)
            p3 = insertatend(p3, p1->num);
        p1 = p1->link;
    }
    return p3;
}
struct node *simplify(struct node *set)
{
    struct node *p3 = set;
    struct node *temp;
    while (p3->link != NULL)
    {
        if (p3->num == p3->link->num)
        {
            temp = p3->link;
            p3->link = temp->link;
            free(temp);
            temp = NULL;
        }
        else
            p3 = p3->link;
    }
    return set;
}
struct node *Difference_BA(struct node *set1, struct node *set2)
{
    struct node *p1 = set1, *p2 = set2;
    struct node *p3;
    p3 = NULL;
    struct node *q;
    while (p2 != NULL)
    {
        q = p1;
        while (q != NULL)
        {
            if (q->num == p2->num)
                break;
            q = q->link;
        }
        if (q == NULL)
            p3 = insertatend(p3, p2->num);
        p2 = p2->link;
    }
    return p3;
}
struct node *Union(struct node *set1, struct node *set2)
{
    struct node *p1 = set1, *p2 = set2;
    struct node *p3;
    p3 = NULL;
    struct node *q;
    while (p1 != NULL)
    {
        p3 = insertatend(p3, p1->num);
        p1 = p1->link;
    }
    while (p2 != NULL)
    {
        q = p1;
        while (q != NULL)
        {
            if (q->num == p2->num)
                break;
            q = q->link;
        }
        if (q == NULL)
            p3 = insertatend(p3, p2->num);
        p2 = p2->link;
    }
    return p3;
}
struct node *intersection(struct node *set1, struct node *set2)
{
    struct node *p1 = set1, *p2 = set2;
    struct node *p3;
    p3 = NULL;
    struct node *q;
    while (p2 != NULL)
    {
        q = p1;
        while (q != NULL)
        {
            if (q->num == p2->num)
                break;
            q = q->link;
        }
        if (q != NULL)
            p3 = insertatend(p3, p2->num);
        p2 = p2->link;
    }
    return p3;
}
struct node *sort_list(struct node *start)
{
    struct node *p1, *p2;
    int temp;
    p1 = start;
    while (p1 != NULL)
    {
        p2 = p1->link;
        while (p2 != NULL)
        {
            if (p2->num < p1->num)
            {
                temp = p2->num;
                p2->num = p1->num;
                p1->num = temp;
            }
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    return start;
}
struct node *insertatend(struct node *start, int item)
{
    if (start == NULL)
    {
        start = insert_emptylist(start, item);
    }
    struct node *p, *tmp;
    p = (struct node *)malloc(sizeof(struct node));
    p->num = item;
    tmp = start;
    while (tmp->link != NULL)
    {
        tmp = tmp->link;
    }
    tmp->link = p;
    p->link = NULL;
    return start;
}
void Display(struct node *start)
{
    start = sort_list(start);
    start = simplify(start);
    struct node *p = start;
    if (start == NULL)
    {
        printf("List is empty. \n");
        exit(0);
    }
    printf("\n");
    printf("{ ");
    while (p != NULL)
    {
        printf("%d", p->num);
        if (p->link != NULL)
            printf(", ");
        p = p->link;
    }
    printf(" }");
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
    p->num = item;
    p->link = start;
    start = p;
    return start;
}
struct node *create_list(struct node *start, int n)
{
    int item;
    if (n == 0)
        return start;
    if (start == NULL)
    {
        printf("Enter number to be inserted at node 1 : ");
        scanf("%d", &item);
        start = insert_emptylist(start, item);
    }
    struct node *p = start;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter number to be inserted at node %d : ", i);
        scanf("%d", &item);
        start = insertatend(start, item);
    }
    return start;
}
int main()
{
    struct node *p1 = NULL, *p2 = NULL, *p3 = NULL;
    int n1, n2;
    printf("Enter the number of elements in set1 : ");
    scanf("%d", &n1);
    printf("Enter the elements of set1 : \n");
    p1 = create_list(p1, n1);
    printf("Enter the number of elements in set2 : ");
    scanf("%d", &n2);
    printf("Enter the elements of set2 : \n");
    p2 = create_list(p2, n2);
    printf("Set1 = ");
    Display(p1);
    printf("\nSet2 = ");
    Display(p2);
    int choice;
    while (1)
    {
        printf("\n1.Intersection\n");
        printf("2.Union\n");
        printf("3.Difference A-B\n");
        printf("4.Difference B-A\n");
        printf("5.Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            p3 = intersection(p1, p2);
            printf("Final set after intersection is : ");
            Display(p3);
            break;
        case 2:
            p3 = Union(p1, p2);
            printf("\nFinal set after union is : ");
            Display(p3);
            break;
        case 3:
            p3 = Difference_AB(p1, p2);
            printf("\nDifference of sets A-B considering set1 as A and set2 as B : ");
            Display(p3);
            break;
        case 4:
            p3 = Difference_BA(p1, p2);
            printf("\nDifference of sets B-A considering set1 as A and set2 as B : ");
            Display(p3);
            break;
        case 5:
            printf("\nExiting....\n");
            free(p1);
            free(p2);
            free(p3);
            exit(0);
        default:
            printf("Invalid choice...Please try again.\n");
        }
    }
    return 0;
}