#include <stdio.h>
#include <stdlib.h>
struct vertex;
struct edge
{
    struct vertex *destV;
    struct edge *nextE;
};
struct vertex
{
    int val;
    struct vertex *nextV;
    struct edge *firstE;
} *start = NULL;
struct vertex *find(int u);
void insertV(int u);
void deleteV(int u);
void insertE(int u, int v);
void deleteE(int u, int v);
void incomingE(int u);
void Display();
int main()
{
    return 0;
}
void insertV(int u)
{
    struct vertex *tmp, *p;
    tmp = (struct vertex *)malloc(sizeof(struct vertex));
    tmp->val = u;
    tmp->nextV = NULL;
    tmp->firstE = NULL;
    if (start == NULL)
    {
        start = tmp;
        return;
    }
    p = start;
    while (p->nextV != NULL)
        p = p->nextV;
    p->nextV = tmp;
}
void deleteV(int u)
{
    struct vertex *tmp, *q;
    struct edge *t, *p;
    if (start == NULL)
    {
        printf("No vertices to be deleted\n");
        return;
    }
    if (start->val == u)
    {
        tmp = start;
        start = start->nextV;
    }
    else
    {
        q = start;
        while (q->nextV != NULL)
        {
            if (q->nextV->val == u)
                break;
            q = q->nextV;
        }
        if (q->nextV == NULL)
        {
            printf("Vertex not found\n");
            return;
        }
        else
        {
            tmp = q->nextV;
            q->nextV = tmp->nextV;
        }
    }
    t = tmp->firstE;
    while (t != NULL)
    {
        p = t;
        t = t->nextE;
        free(p);
    }
    free(tmp);
}