#include <stdio.h>
#define MAX 5
int q1[MAX];
int q2[MAX];
int front1 = -1, front2 = -1;
int rear1 = -1, rear2 = -1;
int isEmpty()
{
    if (front1 == -1 || front1 == rear1 + 1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((rear1 + 1) % MAX == front1)
    {
        return 1;
    }
    else
        return 0;
}
void push1(int x)
{
    if (front1 == -1 && rear1 == -1)
    {
        front1 = rear1 = 0;
        q1[rear1] = x;
        return;
    }
    else
    {
        while (!isEmpty)
        {
        }
    }
}
int Delete()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        exit(1);
    }
    int data = q1[front1++];
    return data;
}
int main()
{
    return 0;
}