// Qabc
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printList(struct Node *node)
{
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high, int order)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (order * arr[j] < order * pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int order)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, order);
        printf("QuickSort Iteration: ");
        printArray(arr, high + 1);
        quickSort(arr, low, pi - 1, order);
        quickSort(arr, pi + 1, high, order);
    }
}

void heapify(int arr[], int n, int i, int order)
{
    int compare = order * arr[i];
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && order * arr[left] > compare)
        largest = left;

    if (right < n && order * arr[right] > compare)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, order);
    }
}

void insertionSort(char arr[], int n, int order)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && order * arr[j] > order * key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("InsertionSort Iteration: ");
        for (int k = 0; k < n; k++)
            printf("%c ", arr[k]);
        printf("\n");
    }
}

struct Node *merge(struct Node *left, struct Node *right, int order)
{
    if (!left)
        return right;
    if (!right)
        return left;

    struct Node *result = NULL;
    if ((order == 1 && left->data <= right->data) || (order == -1 && left->data >= right->data))
    {
        result = left;
        result->next = merge(left->next, right, order);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next, order);
    }
    return result;
}

void split(struct Node *source, struct Node **left, struct Node **right)
{
    struct Node *fast;
    struct Node *slow;
    if (!source || !source->next)
    {
        *left = source;
        *right = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;

        while (fast)
        {
            fast = fast->next;
            if (fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *left = source;
        *right = slow->next;
        slow->next = NULL;
    }
}

struct Node *mergeSort(struct Node *head, int order)
{
    if (!head || !head->next)
        return head;

    struct Node *left;
    struct Node *right;

    split(head, &left, &right);

    left = mergeSort(left, order);
    right = mergeSort(right, order);
    struct Node *merged = merge(left, right, order);
    printf("MergeSort Iteration: ");
    printList(merged);

    return merged;
}

void push(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void heapSort(int arr[], int n, int order)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, order);

    printf("HeapSort Iteration: ");
    printArray(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, order);
    }
}

int main()
{
    int choice;
    int order;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insertion Sort (Character Array)\n");
        printf("2. Merge Sort (Linked List)\n");
        printf("3. Quick Sort\n");
        printf("4. Heap Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char arr[100];
            int n;

            printf("Enter the size of the character array: ");
            scanf("%d", &n);

            printf("Enter the character array elements: ");
            for (int i = 0; i < n; i++)
                scanf(" %c", &arr[i]);

            printf("Unsorted array: ");
            for (int i = 0; i < n; i++)
                printf("%c ", arr[i]);

            insertionSort(arr, n, 1);
            printf("\nSorted array (Ascending): ");
            for (int i = 0; i < n; i++)
                printf("%c ", arr[i]);

            printf("\n");

            insertionSort(arr, n, -1);
            printf("\nSorted array (Descending): ");
            for (int i = 0; i < n; i++)
                printf("%c ", arr[i]);

            printf("\n");
            break;
        }
        case 2:
        {
            struct Node *head = NULL;
            int num, data;

            printf("Enter the number of elements in the linked list: ");
            scanf("%d", &num);

            printf("Enter the linked list elements: ");
            for (int i = 0; i < num; i++)
            {
                scanf("%d", &data);
                push(&head, data);
            }

            printf("Linked List before sorting \n");
            printList(head);

            head = mergeSort(head, 1);
            printf("Linked List after sorting (Ascending) \n");
            printList(head);
            head = mergeSort(head, -1);
            printf("\n");
            printf("Linked List after sorting (Descending) \n");
            printList(head);
            break;
        }
        case 3:
        {
            int num;

            printf("Enter the number of elements in the array: ");
            scanf("%d", &num);

            int arr[num];

            printf("Enter the array elements: ");
            for (int i = 0; i < num; i++)
                scanf("%d", &arr[i]);

            printf("Unsorted array: \n");
            printArray(arr, num);

            quickSort(arr, 0, num - 1, 1);
            printf("Sorted array (Ascending): \n");
            printArray(arr, num);
            printf("\n");
            quickSort(arr, 0, num - 1, -1);
            printf("Sorted array (Descending): \n");
            printArray(arr, num);
            break;
        }
        case 4:
        {
            int num;
            printf("Enter the number of elements in the array: ");
            scanf("%d", &num);
            int arr[num];
            printf("Enter the array elements: ");
            for (int i = 0; i < num; i++)
                scanf("%d", &arr[i]);

            printf("Unsorted array: \n");
            printArray(arr, num);

            heapSort(arr, num, 1);
            printf("Sorted array (Ascending): \n");
            printArray(arr, num);
            printf("\n");
            heapSort(arr, num, -1);
            printf("Sorted array (Descending): \n");
            printArray(arr, num);
            break;
        }
        case 0:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
/*
OUTPUT - 
Menu:
1. Insertion Sort (Character Array)
2. Merge Sort (Linked List)
3. Quick Sort
4. Heap Sort
0. Exit
Enter your choice: 1
Enter the size of the character array: 5
Enter the character array elements: A D L B G
Unsorted array: A D L B G InsertionSort Iteration: A D L B G
InsertionSort Iteration: A D L B G
InsertionSort Iteration: A B D L G
InsertionSort Iteration: A B D G L

Sorted array (Ascending): A B D G L
InsertionSort Iteration: B A D G L
InsertionSort Iteration: D B A G L
InsertionSort Iteration: G D B A L
InsertionSort Iteration: L G D B A

Sorted array (Descending): L G D B A

Menu:
1. Insertion Sort (Character Array)
2. Merge Sort (Linked List)
3. Quick Sort
4. Heap Sort
0. Exit
Enter your choice: 2
Enter the number of elements in the linked list: 5
Enter the linked list elements: 2 33 1 54 6
Linked List before sorting
6 54 1 33 2
MergeSort Iteration: 6 54
MergeSort Iteration: 1 6 54
MergeSort Iteration: 2 33
MergeSort Iteration: 1 2 6 33 54
Linked List after sorting (Ascending)
1 2 6 33 54
MergeSort Iteration: 2 1
MergeSort Iteration: 6 2 1
MergeSort Iteration: 54 33
MergeSort Iteration: 54 33 6 2 1

Linked List after sorting (Descending)
54 33 6 2 1

Menu:
1. Insertion Sort (Character Array)
2. Merge Sort (Linked List)
3. Quick Sort
4. Heap Sort
0. Exit
Enter your choice: 3
Enter the number of elements in the array: 5
Enter the array elements: 2 33 1 54 6
Unsorted array:
2 33 1 54 6
QuickSort Iteration: 2 1 6 54 33
QuickSort Iteration: 1 2
QuickSort Iteration: 1 2 6 33 54
Sorted array (Ascending):
1 2 6 33 54

QuickSort Iteration: 54 2 6 33 1
QuickSort Iteration: 54 2 6 33 1
QuickSort Iteration: 54 33 6 2
QuickSort Iteration: 54 33 6 2
Sorted array (Descending):
54 33 6 2 1

Menu:
1. Insertion Sort (Character Array)
2. Merge Sort (Linked List)
3. Quick Sort
4. Heap Sort
0. Exit
Enter your choice: 4
Enter the number of elements in the array: 5
Enter the array elements: 2 33 1 54 6
Unsorted array:
2 33 1 54 6
HeapSort Iteration: 54 6 1 33 2
Sorted array (Ascending):
1 2 33 6 54

HeapSort Iteration: 1 2 33 6 54
Sorted array (Descending):
54 6 2 33 1

Menu:
1. Insertion Sort (Character Array)
2. Merge Sort (Linked List)
3. Quick Sort
4. Heap Sort
0. Exit
Enter your choice: 0
Exiting the program. Goodbye!*/