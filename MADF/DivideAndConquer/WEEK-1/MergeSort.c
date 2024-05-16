/*
    author - Yash Malviya
    title - Merge Sort
*/
#include <stdio.h>
#include <stdlib.h>

int n;
char *bar;

void printArray_char(char a[], int size)
{
    printf("( ");
    for (int i = 0; i < size; i++)
    {
        printf("%c", a[i]);
        if (i != n - 1)
        {
            if (bar[i] == '|')
                printf(" %c ", bar[i]);
            else
                printf(", ");
        }
    }
    printf(" )\n");
}

void printArray_int(int a[], int size)
{
    printf("( ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
        {
            if (bar[i] == '|')
                printf(" %c ", bar[i]);
            else
                printf(", ");
        }
    }
    printf(" )\n");
}

void merge_char(char a[], char t[], int low1, int high1, int low2, int high2)
{
    int i = low1, j = low2, k = 0;
    while (i <= high1 && j <= high2)
    {
        if (a[i] <= a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }
    while (i <= high1)
        t[k++] = a[i++];
    while (j <= high2)
        t[k++] = a[j++];
    bar[high1] = '/';
}

void merge_int(int a[], int t[], int low1, int high1, int low2, int high2)
{
    int i = low1, j = low2, k = 0;
    while (i <= high1 && j <= high2)
    {
        if (a[i] >= a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }
    while (i <= high1)
        t[k++] = a[i++];
    while (j <= high2)
        t[k++] = a[j++];
    bar[high1] = '/';
}

void mergeSort_char(char a[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        char *temp = (char *)malloc((high - low + 1) * sizeof(char));
        bar[mid] = '|';
        printArray_char(a, n);
        mergeSort_char(a, low, mid);
        mergeSort_char(a, mid + 1, high);
        merge_char(a, temp, low, mid, mid + 1, high);
        for (int i = low, k = 0; i <= high; i++)
            a[i] = temp[k++];
        printArray_char(a, n);
        free(temp);
    }
}

void mergeSort_int(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        int *temp = (int *)malloc((high - low + 1) * sizeof(int));
        bar[mid] = '|';
        printArray_int(a, n);
        mergeSort_int(a, low, mid);
        mergeSort_int(a, mid + 1, high);
        merge_int(a, temp, low, mid, mid + 1, high);
        for (int i = low, k = 0; i <= high; i++)
            a[i] = temp[k++];
        printArray_int(a, n);
        free(temp);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Char Merge Sort (Ascending).\n");
        printf("2. Int Merge Sort (Descending).\n");
        printf("3. Exit.\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of terms: ");
            scanf("%d", &n);
            char *a_char = (char *)malloc(n * sizeof(char));
            bar = (char *)malloc((n - 1) * sizeof(char));
            for (int i = 0; i < n; i++)
            {
                printf("Enter element %d: ", i + 1);
                scanf(" %c", &a_char[i]);
            }
            printf("Array before sorting: ");
            printArray_char(a_char, n);
            printf("\n\n");
            mergeSort_char(a_char, 0, n - 1);
            printf("\n\n");
            printf("Array after sorting: ");
            printArray_char(a_char, n);
            free(a_char);
            free(bar);
            break;

        case 2:
            printf("Enter number of terms: ");
            scanf("%d", &n);
            int *a_int = (int *)malloc(n * sizeof(int));
            bar = (char *)malloc((n - 1) * sizeof(char));
            for (int i = 0; i < n; i++)
            {
                printf("Enter element %d: ", i + 1);
                scanf("%d", &a_int[i]);
            }
            printf("Array before sorting: ");
            printArray_int(a_int, n);
            printf("\n\n");
            mergeSort_int(a_int, 0, n - 1);
            printf("\n\n");
            printf("Array after sorting: ");
            printArray_int(a_int, n);
            free(a_int);
            free(bar);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
/*
OUTPUT -
1. Char Merge Sort (Ascending).
2. Int Merge Sort (Descending).
3. Exit.
Enter choice : 1
Enter number of terms: 11
Enter element 1: K
Enter element 2: H
Enter element 3: B
Enter element 4: Q
Enter element 5: X
Enter element 6: S
Enter element 7: W
Enter element 8: F
Enter element 9: I
Enter element 10: V
Enter element 11: S
Array before sorting: ( K, H, B, Q, X, S, W, F, I, V, S )


( K, H, B, Q, X, S | W, F, I, V, S )
( K, H, B | Q, X, S | W, F, I, V, S )
( K, H | B | Q, X, S | W, F, I, V, S )
( K | H | B | Q, X, S | W, F, I, V, S )
( H, K | B | Q, X, S | W, F, I, V, S )
( B, H, K | Q, X, S | W, F, I, V, S )
( B, H, K | Q, X | S | W, F, I, V, S )
( B, H, K | Q | X | S | W, F, I, V, S )
( B, H, K | Q, X | S | W, F, I, V, S )
( B, H, K | Q, S, X | W, F, I, V, S )
( B, H, K, Q, S, X | W, F, I, V, S )
( B, H, K, Q, S, X | W, F, I | V, S )
( B, H, K, Q, S, X | W, F | I | V, S )
( B, H, K, Q, S, X | W | F | I | V, S )
( B, H, K, Q, S, X | F, W | I | V, S )
( B, H, K, Q, S, X | F, I, W | V, S )
( B, H, K, Q, S, X | F, I, W | V | S )
( B, H, K, Q, S, X | F, I, W | S, V )
( B, H, K, Q, S, X | F, I, S, V, W )
( B, F, H, I, K, Q, S, S, V, W, X )


Array after sorting: ( B, F, H, I, K, Q, S, S, V, W, X )
1. Char Merge Sort (Ascending).
2. Int Merge Sort (Descending).
3. Exit.
Enter choice : 2
Enter number of terms: 11
Enter element 1: 33
Enter element 2: 53
Enter element 3: 87
Enter element 4: -11
Enter element 5: 55
Enter element 6: 98
Enter element 7: 65
Enter element 8: -11
Enter element 9: 73
Enter element 10: 33
Enter element 11: 43
Array before sorting: ( 33, 53, 87, -11, 55, 98, 65, -11, 73, 33, 43 )


( 33, 53, 87, -11, 55, 98 | 65, -11, 73, 33, 43 )
( 33, 53, 87 | -11, 55, 98 | 65, -11, 73, 33, 43 )
( 33, 53 | 87 | -11, 55, 98 | 65, -11, 73, 33, 43 )
( 33 | 53 | 87 | -11, 55, 98 | 65, -11, 73, 33, 43 )
( 53, 33 | 87 | -11, 55, 98 | 65, -11, 73, 33, 43 )
( 87, 53, 33 | -11, 55, 98 | 65, -11, 73, 33, 43 )
( 87, 53, 33 | -11, 55 | 98 | 65, -11, 73, 33, 43 )
( 87, 53, 33 | -11 | 55 | 98 | 65, -11, 73, 33, 43 )
( 87, 53, 33 | 55, -11 | 98 | 65, -11, 73, 33, 43 )
( 87, 53, 33 | 98, 55, -11 | 65, -11, 73, 33, 43 )
( 98, 87, 55, 53, 33, -11 | 65, -11, 73, 33, 43 )
( 98, 87, 55, 53, 33, -11 | 65, -11, 73 | 33, 43 )
( 98, 87, 55, 53, 33, -11 | 65, -11 | 73 | 33, 43 )
( 98, 87, 55, 53, 33, -11 | 65 | -11 | 73 | 33, 43 )
( 98, 87, 55, 53, 33, -11 | 65, -11 | 73 | 33, 43 )
( 98, 87, 55, 53, 33, -11 | 73, 65, -11 | 33, 43 )
( 98, 87, 55, 53, 33, -11 | 73, 65, -11 | 33 | 43 )
( 98, 87, 55, 53, 33, -11 | 73, 65, -11 | 43, 33 )
( 98, 87, 55, 53, 33, -11 | 73, 65, 43, 33, -11 )
( 98, 87, 73, 65, 55, 53, 43, 33, 33, -11, -11 )


Array after sorting: ( 98, 87, 73, 65, 55, 53, 43, 33, 33, -11, -11 )
1. Char Merge Sort (Ascending).
2. Int Merge Sort (Descending).
3. Exit.
Enter choice : 3
*/