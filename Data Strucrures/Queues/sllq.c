//Q1
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *MEM_ALLOC()
{
    return (struct node *)malloc(sizeof(struct node));
}

void nq(int item)
{
    struct node *tmp;
    tmp = MEM_ALLOC();
    if (tmp == NULL)
    {
        printf("Queue overflow\n");
        return;
    }
    tmp->data = item;
    tmp->link = NULL;
    if (front == NULL)
    {
        front = tmp;
        rear = tmp;
    }
    else
    {
        rear->link = tmp;
        rear = tmp;
    }
}

int dq()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
        exit(0);
    }
    int item;
    struct node *p = front;
    front = front->link;
    item = p->data;
    free(p);
    return item;
}

void Display()
{
    struct node *p = front;
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Contents of the Queue are : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    int item = front->data;
    printf("The element at the front is : %d\n", item);
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to be inserted : ");
            scanf("%d", &item);
            nq(item);
            break;
        case 2:
            item = dq();
            printf("The Dequeued element is : %d\n", item);
            break;
        case 3:
            Display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice..\n");
            break;
        }
    }
    return 0;
}
/*1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 1
Enter data to be inserted : 2

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 1 
Enter data to be inserted : 3

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 1
Enter data to be inserted : 4

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 1
Enter data to be inserted : 5

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 3
Contents of the Queue are : 2 3 4 5 

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 2
The Dequeued element is : 2

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 3
Contents of the Queue are : 3 4 5

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 4
The element at the front is : 3

1. Enqueue
2. Dequeue
3. Display
4. Peek
5. Exit
Enter your choice : 5
Exiting...*/