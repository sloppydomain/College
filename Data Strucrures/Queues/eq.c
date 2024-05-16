//Q1
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1;
int rear = -1;
int c_queue[MAX];
void Display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    if (front <= rear)
    {
        printf("The elements in the Queue are : ");
        printf("( ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", c_queue[i]);
            if (i != rear)
                printf(", ");
        }
        printf(" )");
    }
    else
    {
        printf("The elements in the Queue are : ");
        printf("( ");
        for (i = front; i < MAX; i++)
        {
            printf("%d ", c_queue[i]);
            printf(", ");
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d ", c_queue[i]);
            if (i != rear)
                printf(", ");
        }
        printf(" )");
    }
    printf("\n");
}

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if ((rear + 1) % MAX == front)
    {
        return 1;
    }
    else
        return 0;
}
void nq(int item)
{
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else if (isFull())
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
    }
    c_queue[rear] = item;
    Display();
}
void dq()
{
    int item;
    if (isEmpty())
    {
        printf("Queue underfow\n");
        return;
    }
    else if (front == rear)
    {
        printf("The Dequeued element is %d\n", c_queue[front]);
        front = -1;
        rear = -1;
        Display();
    }
    else
    {
        printf("The Dequeued element is %d\n", c_queue[front]);
        front = (front + 1) % MAX;
        Display();
    }
}
int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element which is to be inserted : ");
            scanf("%d", &item);
            nq(item);
            break;
        case 2:
            dq();
            break;
        case 3:
            Display();
            break;
        case 4:
            printf("Exiting....\n");
            exit(0);
        default:
            printf("Invalid choice...\n");
        }
    }
    return 0;
}
/*1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 1
Enter element which is to be inserted : 1
The elements in the Queue are : ( 1  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 1
Enter element which is to be inserted : 2
The elements in the Queue are : ( 1 , 2  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 1
Enter element which is to be inserted : 3
The elements in the Queue are : ( 1 , 2 , 3  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 1
Enter element which is to be inserted : 4
The elements in the Queue are : ( 1 , 2 , 3 , 4  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 1
Enter element which is to be inserted : 5
The elements in the Queue are : ( 1 , 2 , 3 , 4 , 5  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 2
The Dequeued element is 1
The elements in the Queue are : ( 2 , 3 , 4 , 5  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 2
The Dequeued element is 2
The elements in the Queue are : ( 3 , 4 , 5  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 2
The Dequeued element is 3
The elements in the Queue are : ( 4 , 5  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 2
The Dequeued element is 4
The elements in the Queue are : ( 5  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 2
The Dequeued element is 5
Queue is Empty

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 1
Enter element which is to be inserted : 2
The elements in the Queue are : ( 2  )

1. Insert
2. Delete
3. Display
4. Exit
Enter your choice : 4
Exiting....*/