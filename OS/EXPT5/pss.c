#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int* buffer;
    int rear;
    int front;
    int size;
};

void produce(struct Queue* q, int id) {
    if(isFull(q)) {
        printf("Buffer is Full!\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
        q->rear = 0;
        q->buffer[q->rear] = id;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->buffer[q->rear] = id;
    }
}

int consumer(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Buffer is Empty!\n");
        return -1;
    }
    int id = q->buffer[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return id;
}

bool isEmpty(struct Queue* q) {
    return (q->front == -1);
}

bool isFull(struct Queue* q) {
    return ((q->rear + 1) % q->size == q->front);
}

int main() {
    int sz;
    printf("Enter buffer size: ");
    scanf("%d", &sz);
    struct Queue q1;
    q1.size = sz;
    q1.front = -1;
    q1.rear = -1;
    q1.buffer = (int*)malloc(sz * sizeof(int));
    while(1) {
        int op;
        printf("Choose an option.\n");
        printf("1. Produce an item.\n");
        printf("2. Consume an item.\n");
        printf("3. Exit.\n");
        printf("Enter choice: ");
        if (scanf("%d", &op) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {};
            continue;
        }
        switch(op) {
            case 1: {
                int id;
                printf("Enter process id: ");
                scanf("%d", &id);
                produce(&q1, id);
                break;
            }
            case 2: {
                int consumedItem = consumer(&q1);
                if (consumedItem != -1) {
                    printf("Consumed item with process id: %d\n", consumedItem);
                }
                break;
            }
            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}