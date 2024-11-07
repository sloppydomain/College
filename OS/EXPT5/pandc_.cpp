#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int* buffer;
    int rear;
    int front;
    int size;
    int full;  
    int empty; 
};

void displayBuffer(struct Queue *queue) {
    if (queue->front == -1) {
        printf("Buffer is empty!\n");
        return;
    }
    printf("------------- Buffer State -------------\n");
    printf("| Index | Process ID                    |\n");
    printf("|-------|-------------------------------|\n");
    int c = 0;
    if(queue->front <= queue->rear) {
        for(int i = queue->front; i <= queue->rear; i++) {
            printf("| %5d | %-30d |\n", i, queue->buffer[i]);
            c += 1;
        }
    } else {
        for(int i = queue->front; i < queue->size; i++) {
            printf("| %5d | %-30d |\n", i, queue->buffer[i]);
            c += 1;
        }
        for(int i = 0; i <= queue->rear; i++) {
            printf("| %5d | %-30d |\n", i, queue->buffer[i]);
            c += 1;
        }
    }
    printf("|-------|-------------------------------|\n");
    printf("Total Items: %d\n", c);
    printf("-----------------------------------------\n");
}

int mutex = 0;
bool isEmpty(struct Queue* q) {
    return (q->front == -1);
}

bool isFull(struct Queue* q) {
    return ((q->rear + 1) % q->size == q->front);
}

void wait(int *flag) {
    *flag = 1; 
}

void signal(int *flag) {
    *flag = 0; 
}

void push(struct Queue* w, int id) {
    if (isFull(w)) {
        printf("Waiting queue is full, cannot push item %d.\n", id);
        return; 
    }
    if (w->front == -1) {
        w->front = 0; 
    }
    w->rear = (w->rear + 1) % w->size; 
    w->buffer[w->rear] = id; 
    printf("Item %d added to waiting queue.\n", id);
}

int pop(struct Queue* w) {
    if (isEmpty(w)) {
        printf("Waiting queue is empty, cannot pop item.\n");
        return -1; 
    }
    int id = w->buffer[w->front]; 
    if (w->front == w->rear) {
        w->front = -1; 
        w->rear = -1;
    } else {
        w->front = (w->front + 1) % w->size; 
    }
    printf("Item %d removed from waiting queue.\n", id);
    return id; 
}

void produce(struct Queue* q, struct Queue* w, int id) {
    wait(&mutex); 
    if (isFull(q)) {
        push(w, id); 
        printf("Main buffer full! Item %d added to waiting queue.\n", id);
    } else {
        if (q->front == -1) { 
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->size; 
        q->buffer[q->rear] = id; 
        printf("Produced item with id: %d\n", id);
        q->empty = 0; 
    }
    signal(&mutex); 
}

int consume(struct Queue* q, struct Queue* w) {
    wait(&mutex); 
    if (isEmpty(q)) {
        printf("Main buffer empty! Cannot consume.\n");
        signal(&mutex); 
        return -1; 
    }
    int id = q->buffer[q->front]; 
    if (q->front == q->rear) { 
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size; 
    }
    printf("Consumed item with id: %d\n", id);
    q->full = 0; 
    if (!isEmpty(w)) {
        int waitingItem = pop(w); 
        if (waitingItem != -1) {
            if (q->front == -1) {
                q->front = 0; 
            }
            q->rear = (q->rear + 1) % q->size; 
            q->buffer[q->rear] = waitingItem;
            printf("Moved item %d from waiting queue to main queue.\n", waitingItem);
        }
    }
    signal(&mutex); 
    return id; 
}

void initialize(struct Queue* q, int size) {
    q->size = size;
    q->rear = -1; 
    q->front = -1; 
    q->full = 0; 
    q->empty = 1; 
    q->buffer = (int*)malloc(size * sizeof(int)); 
}

int main() {
    int sz;
    printf("Enter buffer size: ");
    scanf("%d", &sz);
    struct Queue mainQueue;
    struct Queue waitingQueue;
    initialize(&mainQueue, sz); 
    initialize(&waitingQueue, 1e6); 
    while (1) {
        int op;
        printf("Choose an option.\n");
        printf("1. Produce an item.\n");
        printf("2. Consume an item.\n");
        printf("3. Display buffer.\n");
        printf("4. Exit.\n");
        printf("Enter choice: ");
        if (scanf("%d", &op) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {};
            continue;
        }
        switch (op) {
            case 1: {
                int id;
                printf("Enter process id: ");
                scanf("%d", &id);
                produce(&mainQueue, &waitingQueue, id); 
                break;
            }
            case 2: {
                int consumedItem = consume(&mainQueue, &waitingQueue); 
                if (consumedItem != -1) {
                    printf("Consumed item: %d\n", consumedItem);
                }
                break;
            }
            case 3:
                displayBuffer(&mainQueue);
                break;
            case 4:
                printf("Exiting...\n");
                free(mainQueue.buffer); 
                free(waitingQueue.buffer); 
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}

/*
OUTPUT:
Enter buffer size: 3
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 1
Enter process id: 1
Produced item with id: 1
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 1
Enter process id: 2
Produced item with id: 2
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 1
Enter process id: 3
Produced item with id: 3
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 1
Enter process id: 4
Item 4 added to waiting queue.
Main buffer full! Item 4 added to waiting queue.
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 1
Enter process id: 5
Item 5 added to waiting queue.
Main buffer full! Item 5 added to waiting queue.
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 2
Consumed item with id: 1
Item 4 removed from waiting queue.
Moved item 4 from waiting queue to main queue.
Consumed item: 1
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 2
Consumed item with id: 2
Item 5 removed from waiting queue.
Moved item 5 from waiting queue to main queue.
Consumed item: 2
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 2
Consumed item with id: 3
Consumed item: 3
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 3
------------- Buffer State -------------
| Index | Process ID                    |
|-------|-------------------------------|
|     0 | 4                              |
|     1 | 5                              |
|-------|-------------------------------|
Total Items: 2
-----------------------------------------
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 2
Consumed item with id: 4
Consumed item: 4
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 3
------------- Buffer State -------------
| Index | Process ID                    |
|-------|-------------------------------|
|     1 | 5                              |
|-------|-------------------------------|
Total Items: 1
-----------------------------------------
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 2
Consumed item with id: 5
Consumed item: 5
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 3
Buffer is empty!
Choose an option.
1. Produce an item.
2. Consume an item.
3. Display buffer.
4. Exit.
Enter choice: 4
Exiting...


Conclusion: Process synchronization using semaphores was successfully studied and implemented
*/