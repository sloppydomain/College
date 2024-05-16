#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue_arr[MAX];
int front = -1;
int rear = -1;

int isEmpty();
int isFull();
void Insert(int);
int Delete();
void Display();
int peek();

int main()
{
    int choice, data;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display all the elements of Queue\n");
        printf("4. Display first Element\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element : ");
            scanf("%d", &data);
            Insert(data);
            break;
        case 2:
            data = Delete();
            printf("Deleted element is %d\n", data);
            break;
        case 3:
            Display();
            break;
        case 4:
            printf("Element at the front is : %d\n", peek());
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice. Enter valid choice.....\n");
        }
    }
    return 0;
}

int isEmpty()
{
    return (front == -1 || front == rear + 1);
}

int isFull()
{
    return (rear == MAX - 1 || front == rear + 1);
}

void Display()
{
    int i;
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue contents are : ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue_arr[i]);
    }
    printf("\n\n");
}

void Insert(int data)
{
    if (isFull())
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue_arr[++rear] = data;
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    int data = queue_arr[front];
    return data;
}

int Delete()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    int data = queue_arr[front++];
    return data;
}

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 5

// typedef struct {
//     int data[MAX_SIZE];
//     int front;
//     int rear;
// } Queue;

// int isEmpty(Queue *queue) {
//     return queue->front == -1;
// }

// int isFull(Queue *queue) {
//     return queue->rear == MAX_SIZE - 1;
// }

// void display(Queue *queue) {
//     if (isEmpty(queue)) {
//         printf("Queue is empty.\n");
//         return;
//     }

//     printf("Queue contents are: ");
//     for (int i = queue->front; i <= queue->rear; i++) {
//         printf("%d ", queue->data[i]);
//     }
//     printf("\n");
// }

// void insert(Queue *queue, int data) {
//     if (isFull(queue)) {
//         printf("Queue is full. Cannot insert.\n");
//         return;
//     }

//     if (queue->front == -1) {
//         queue->front = 0;
//     }

//     queue->data[++queue->rear] = data;
// }

// int delete(Queue *queue) {
//     if (isEmpty(queue)) {
//         printf("Queue is empty. Cannot delete.\n");
//         exit(1);
//     }

//     int data = queue->data[queue->front++];

//     if (queue->front > queue->rear) { // Reset front and rear when queue becomes empty
//         queue->front = -1;
//         queue->rear = -1;
//     }

//     return data;
// }

// int peek(Queue *queue) {
//     if (isEmpty(queue)) {
//         printf("Queue is empty.\n");
//         exit(1);
//     }
//     return queue->data[queue->front];
// }

// int main() {
//     Queue queue = {.front = -1, .rear = -1};

//     while (1) {
//         printf("1. Insert\n");
//         printf("2. Delete\n");
//         printf("3. Display all elements of the queue\n");
//         printf("4. Display first element\n");
//         printf("5. Quit\n");
//         printf("Enter your choice: ");

//         int choice, data;
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter the element: ");
//                 scanf("%d", &data);
//                 insert(&queue, data);
//                 break;
//             case 2:
//                 data = delete(&queue);
//                 printf("Deleted element is %d\n", data);
//                 break;
//             case 3:
//                 display(&queue);
//                 break;
//             case 4:
//                 printf("Element at the front is: %d\n", peek(&queue));
//                 break;
//             case 5:
//                 exit(0);
//             default:
//                 printf("Wrong choice. Enter a valid choice.\n");
//         }
//     }

//     return 0;
// }
