//Q2
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_QUEUE 5
#define MAX_TASKS 10

int front = -1;
int rear = -1;
int itemcount = 0;

typedef struct
{
    int TaskId;
    char TaskTitle[10];
    int TaskDuration;
    char status[10];
} task;

task tasks[MAX_TASKS];
task cqueue_arr[MAX_QUEUE];

int isEmpty()
{
    return front == -1 && rear == -1;
}

int isFull()
{
    return (rear + 1) % MAX_QUEUE == front;
}

void displayTasks()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("\nTasks in the queue are : \n");
    int i = front;
    do
    {
        printf("\nTask ID : %d\n", cqueue_arr[i].TaskId);
        printf("Task Title : %s\n", cqueue_arr[i].TaskTitle);
        printf("Task Duration : %d\n", cqueue_arr[i].TaskDuration);
        printf("Task Status : %s\n", cqueue_arr[i].status);
        i = (i + 1) % MAX_QUEUE;
    } while (i != (rear + 1) % MAX_QUEUE);
}

void nq(task t)
{
    if (isFull())
    {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_QUEUE;
    }
    cqueue_arr[rear] = t;
    itemcount++;
    displayTasks();
}
task dq()
{
    task emptyTask = {0, "", 0, ""};
    if (isEmpty())
    {
        printf("Queue underflow\n");
        return emptyTask;
    }
    task dequeuedTask = cqueue_arr[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_QUEUE;
    }
    itemcount--;
    return dequeuedTask;
}
void handleFullQueue()
{
    int minwaitingtime = tasks[front].TaskDuration;
    int maxwaitingtime = 0;
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    do
    {
        maxwaitingtime += tasks[i].TaskDuration;
        i = (i + 1) % MAX_QUEUE;
    } while (i != (rear + 1) % MAX_QUEUE);
    printf("Minimum waiting time: %ds\n", minwaitingtime);
    printf("Maximum waiting time: %ds\n", maxwaitingtime);
}
void scheduleTask(int x)
{
    int id;
    printf("Enter the task Id of the task to be scheduled: ");
    scanf("%d", &id);
    int taskindex = -1;
    for (int i = 0; i < x; i++)
    {
        if (tasks[i].TaskId == id)
        {
            taskindex = i;
            break;
        }
    }
    if (taskindex == -1)
    {
        printf("Task not found in Queue\n");
        return;
    }
    if (strcmp(tasks[taskindex].status, "Queued") == 0 || strcmp(tasks[taskindex].status, "Completed") == 0)
    {
        printf("\nDetails of the Task : \n");
        printf("\nTask ID : %d\n", tasks[taskindex].TaskId);
        printf("Task Title : %s\n", tasks[taskindex].TaskTitle);
        printf("Task Duration : %d\n", tasks[taskindex].TaskDuration);
        printf("Task Status : %s\n", tasks[taskindex].status);
        printf("\nThe task has already been %s.\n", tasks[taskindex].status);
        return;
    }
    if (isFull())
    {
        printf("Queue is full. Cannot schedule more tasks.\n");
        handleFullQueue();
        return;
    }
    strcpy(tasks[taskindex].status, "Queued");
    nq(tasks[taskindex]);
    printf("\nTask with Id %d has been scheduled.\n", id);
}
void Display(int x)
{
    if (x == 0)
    {
        printf("Structure is Empty\n");
        return;
    }
    printf("\nDetails of All tasks are : \n");
    for (int i = 0; i < x; i++)
    {
        printf("\nTask ID : %d\n", tasks[i].TaskId);
        printf("Task Title : %s\n", tasks[i].TaskTitle);
        printf("Task Duration : %d\n", tasks[i].TaskDuration);
        printf("Task Status : %s\n", tasks[i].status);
    }
}
int main()
{
    int choice, n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    if (n > MAX_TASKS)
    {
        printf("Number of tasks is too much.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter Task ID: ");
        scanf("%d", &tasks[i].TaskId);
        printf("Enter Task name: ");
        scanf("%s", tasks[i].TaskTitle);
        printf("Enter task duration: ");
        scanf("%d", &tasks[i].TaskDuration);
        strcpy(tasks[i].status, "Idle");
    }

    while (1)
    {
        printf("\n1. Schedule a Task\n");
        printf("2. Run Tasks\n");
        printf("3. Display Queued or Sheduled Tasks\n");
        printf("4. Display All Tasks\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (!isFull())
            {
                scheduleTask(n);
            }
            else
            {
                printf("Queue is full. Cannot schedule more tasks.\n");
                handleFullQueue();
            }
            break;

        case 2:
            if (isEmpty())
            {
                printf("No tasks in the queue. Nothing to run.\n");
            }
            else
            {
                task runningTask = dq();
                printf("\nRunning Task: \nTask ID: %d \nTask Name: %s\n", runningTask.TaskId, runningTask.TaskTitle);
                printf("Task is running...\n");
                sleep(runningTask.TaskDuration);
                for (int i = 0; i < n; i++)
                {
                    if (tasks[i].TaskId == runningTask.TaskId)
                    {
                        strcpy(tasks[i].status, "Completed");
                        break;
                    }
                }
                printf("\nTask Completed.\n");
            }
            break;

        case 3:
            displayTasks();
            break;

        case 4:
            Display(n);
            break;

        case 5:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
/*Enter the number of tasks: 10
Enter Task ID: 1
Enter Task name: task1
Enter task duration: 2
Enter Task ID: 2
Enter Task name: task2
Enter task duration: 3
Enter Task ID: 3
Enter Task name: task3
Enter task duration: 4
Enter Task ID: 4
Enter Task name: task
Enter task duration: 4
Enter Task ID: 5
Enter Task name: task5
Enter task duration: 1
Enter Task ID: 6
Enter Task name: task6 
Enter task duration: 6
Enter Task ID: 7 
Enter Task name: task7
Enter task duration: 2
Enter Task ID: 8
Enter Task name: task8
Enter task duration: 2
Enter Task ID: 9
Enter Task name: task9
Enter task duration: 2
Enter Task ID: 10
Enter Task name: task10
Enter task duration: 3

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 1
Enter the task Id of the task to be scheduled: 4

Tasks in the queue are :

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Queued

Task with Id 4 has been scheduled.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 1
Enter the task Id of the task to be scheduled: 4

Details of the Task :

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Queued

The task has already been Queued.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 1
Enter the task Id of the task to be scheduled: 2

Tasks in the queue are :

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Queued

Task ID : 2
Task Title : task2
Task Duration : 3
Task Status : Queued

Task with Id 2 has been scheduled.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 1
Enter the task Id of the task to be scheduled: 3

Tasks in the queue are :

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Queued

Task ID : 2
Task Title : task2
Task Duration : 3
Task Status : Queued

Task ID : 3
Task Title : task3
Task Duration : 4
Task Status : Queued

Task with Id 3 has been scheduled.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 1
Enter the task Id of the task to be scheduled: 1

Tasks in the queue are :

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Queued

Task ID : 2
Task Title : task2
Task Duration : 3
Task Status : Queued

Task ID : 3
Task Title : task3
Task Duration : 4
Task Status : Queued

Task ID : 1
Task Title : task1
Task Duration : 2
Task Status : Queued

Task with Id 1 has been scheduled.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 1
Enter the task Id of the task to be scheduled: 7

Tasks in the queue are :

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Queued

Task ID : 2
Task Title : task2
Task Duration : 3
Task Status : Queued

Task ID : 3
Task Title : task3
Task Duration : 4
Task Status : Queued

Task ID : 1
Task Title : task1
Task Duration : 2
Task Status : Queued

Task ID : 7
Task Title : task7
Task Duration : 2
Task Status : Queued

Task with Id 7 has been scheduled.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 1
Queue is full. Cannot schedule more tasks.
Minimum waiting time: 2
Maximum waiting time: 14

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 2

Running Task:
Task ID: 4
Task Name: task
Task is running...

Task Completed.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 2

Running Task:
Task ID: 2
Task Name: task2
Task is running...

Task Completed.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 2

Running Task:
Task ID: 3
Task Name: task3
Task is running...

Task Completed.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 3

Tasks in the queue are :

Task ID : 1
Task Title : task1
Task Duration : 2
Task Status : Queued

Task ID : 7
Task Title : task7
Task Duration : 2
Task Status : Queued

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 4

Details of All tasks are :

Task ID : 1
Task Title : task1
Task Duration : 2
Task Status : Queued

Task ID : 2
Task Title : task2
Task Duration : 3
Task Status : Completed

Task ID : 3
Task Title : task3
Task Duration : 4
Task Status : Completed

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Completed

Task ID : 5
Task Title : task5
Task Duration : 1
Task Status : Idle

Task ID : 6
Task Title : task6
Task Duration : 6
Task Status : Idle

Task ID : 7
Task Title : task7
Task Duration : 2
Task Status : Queued

Task ID : 8
Task Title : task8
Task Duration : 2
Task Status : Idle

Task ID : 9
Task Title : task9
Task Duration : 2
Task Status : Idle

Task ID : 10
Task Title : task10
Task Duration : 3
Task Status : Idle

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 2

Running Task: 
Task ID: 1 
Task Name: task1
Task is running...

Task Completed.

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 4

Details of All tasks are :

Task ID : 1
Task Title : task1
Task Duration : 2
Task Status : Completed

Task ID : 2
Task Title : task2
Task Duration : 3
Task Status : Completed

Task ID : 3
Task Title : task3
Task Duration : 4
Task Status : Completed

Task ID : 4
Task Title : task
Task Duration : 4
Task Status : Completed

Task ID : 5
Task Title : task5
Task Duration : 1
Task Status : Idle

Task ID : 6
Task Title : task6
Task Duration : 6
Task Status : Idle

Task ID : 7
Task Title : task7
Task Duration : 2
Task Status : Queued

Task ID : 8
Task Title : task8
Task Duration : 2
Task Status : Idle

Task ID : 9
Task Title : task9
Task Duration : 2
Task Status : Idle

Task ID : 10
Task Title : task10
Task Duration : 3
Task Status : Idle

1. Schedule a Task
2. Run Tasks
3. Display Queued or Sheduled Tasks
4. Display All Tasks
5. Quit
Enter choice: 5
Exiting the program.*/