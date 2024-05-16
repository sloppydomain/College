#include<stdio.h>
struct node
{
    struct node*prev;
     int data;
    struct node*next;
};
struct node*Display(struct node*last);
struct node*Insert(struct node*last);
struct node*Delete(struct node*last);
struct node*Reverse(struct node*last);
int main()
{  
    return 0;
}
