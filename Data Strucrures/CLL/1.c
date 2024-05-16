#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *deletealt(struct node *head)
{
    if (head == NULL || head->link == head)
    {
        return head;
    }

    struct node *p1 = head;
    struct node *p2 = head->link; // Initialize p2 to the second node

    while (p1->link != head)
    {
        p1->link = p2->link;
        free(p2);

        p1 = p1->link;
        if (p1 != head)
        {
            p2 = p1->link;
        }
    }

    return head;
}


int main()
{
    // Create a sample circular linked list for testing
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->link = head;

    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 2;
    node2->link = head;

    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 3;
    node3->link = head;

    head->link = node2;
    node2->link = node3;

    // Print the original list
    printf("Original List: ");
    struct node *current = head;
    do {
        printf("%d ", current->data);
        current = current->link;
    } while (current != head);
    printf("\n");

    // Delete alternate nodes
    head = deletealt(head);

    // Print the modified list
    printf("Modified List: ");
    current = head;
    do {
        printf("%d ", current->data);
        current = current->link;
    } while (current != head);
    printf("\n");

    return 0;
}
