#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int c_queue[MAX];
int front = -1;
int rear = -1;
int isEmpty();
int isFull();
void Display();
void Insert(int);
