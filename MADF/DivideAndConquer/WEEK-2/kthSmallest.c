/*
    author - Yash Malviya
    title  - kthSmallest2
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Display1(int *a, int x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            printf("\033[1m[ %d ]\033[0m", a[i]);
        else
            printf(" %d ", a[i]);
    }
    printf("\n");
}

void Display2(char *a, int x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            printf("\033[1m[ %c ]\033[0m", a[i]);
        else
            printf(" %c ", a[i]);
    }
    printf("\n");
}

int partition1(int *arr, int i, int j, int n)
{
    int pivot = arr[i], low = i, high = j;
    while (i <= j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot && i < j);
        do
        {
            j--;
        } while (arr[j] > pivot && j >= low);
        if (j > i)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        else
        {
            if (low == j)
            {
                return j;
            }
            break;
        }
    }
    int tmp = arr[low];
    arr[low] = arr[j];
    arr[j] = tmp;
    return j;
}

int partition2(char arr[], int i, int j, int n)
{
    char pivot = arr[i], low = i, high = j;
    while (i <= j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot && i < j);
        do
        {
            j--;
        } while (arr[j] > pivot && j >= low);
        if (j > i)
        {
            char tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        else
        {
            if (low == j)
            {
                return j;
            }
            break;
        }
    }
    char tmp = arr[low];
    arr[low] = arr[j];
    arr[j] = tmp;
    return j;
}

int kthsmallest1(int *arr, int n, int k)
{
    int low = 1;
    int up = n + 1;
    while (1)
    {
        int j = partition1(arr, low, up, n);
        printf("j = %d\t", j);
        Display1(arr, j, n);
        if (j == k)
            return arr[j];
        else if (k < j)
            up = j;
        else
            low = j + 1;
    }
    return -1;
}

char kthsmallest2(char *arr, int n, int k)
{
    int low = 1;
    int up = n + 1;
    while (1)
    {
        int j = partition2(arr, low, up, n);
        printf("j = %d\t", j);
        Display2(arr, j, n);
        if (j == k)
            return arr[j];
        else if (k < j)
            up = j;
        else
            low = j + 1;
    }
    return '!';
}

void select(int c)
{
    if (c == 1)
    {
        int n;
        printf("Enter number of elements : ");
        scanf("%d", &n);
        int *a = (int *)malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++)
        {
            printf("Enter element %d : ", i);
            scanf("%d", &a[i]);
        }
        printf("\n");
        int choice;
        while (1)
        {
            int k;
            printf("\n1. Select.");
            printf("\n2. Exit.\n");
            printf("\nEnter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nSelect the kth Element : ");
                scanf("%d", &k);
                if (k > n)
                {
                    printf("Total elements are %d...\n", n);
                    return;
                }
                int ans = kthsmallest1(a, n, k);
                if (ans == -1)
                    printf("%dth smallest element not found...\n", k);
                else
                    printf("%dth smallest element is %d\n", k, ans);
                printf("\n");
                break;
            case 2:
                printf("Exiting...\n");
                return;
            default:
                printf("\nInvalid choice...\n");
                break;
            }
        }
        free(a);
    }
    else
    {
        int n;
        printf("Enter number of elements : ");
        scanf("%d", &n);
        char *b = (char *)malloc((n + 1) * sizeof(char));
        for (int i = 1; i <= n; i++)
        {
            printf("Enter element %d : ", i);
            scanf(" %c", &b[i]);
        }
        printf("\n");
        int choice;
        while (1)
        {
            int k;
            printf("\n1. Select.");
            printf("\n2. Exit.\n");
            printf("\nEnter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nSelect the kth Element : ");
                scanf("%d", &k);
                if (k > n)
                {
                    printf("Total elements are %d...\n", n);
                    return;
                }
                int ans = kthsmallest2(b, n, k);
                if (ans == '!')
                {
                    printf("%dth smallest element not found...\n", k);
                    return;
                }
                else
                    printf("%dth smallest element is %c\n", k, ans);
                printf("\n");
                break;
            case 2:
                printf("Exiting...\n");
                return;
            default:
                printf("\nInvalid choice...\n");
                break;
            }
        }
        free(b);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Select Integer.\n");
        printf("2. Select Character.\n");
        printf("3. Exit.\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            select(1);
            break;
        case 2:
            select(2);
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("\nInvalid choice...\n");
            break;
        }
    }
    return 0;
}
/*
OUTPUT -
1. Select Integer.
2. Select Character.
3. Exit.
Enter choice : 1
Enter number of elements : 11
Enter element 1 : 65
Enter element 2 : 20
Enter element 3 : 56
Enter element 4 : 19
Enter element 5 : 79
Enter element 6 : 28
Enter element 7 : 53
Enter element 8 : 66
Enter element 9 : 75
Enter element 10 : 61
Enter element 11 : 31


1. Select.
2. Exit.

Enter choice : 1

Select the kth Element : 6
j = 8    61  20  56  19  31  28  53 [ 65 ] 75  66  79
j = 7    53  20  56  19  31  28 [ 61 ] 65  75  66  79
j = 5    31  20  28  19 [ 53 ] 56  61  65  75  66  79
j = 6    31  20  28  19  53 [ 56 ] 61  65  75  66  79
6th smallest element is 56


1. Select.
2. Exit.

Enter choice : 1

Select the kth Element : 10
j = 4    19  20  28 [ 31 ] 53  56  61  65  75  66  79
j = 5    19  20  28  31 [ 53 ] 56  61  65  75  66  79
j = 6    19  20  28  31  53 [ 56 ] 61  65  75  66  79
j = 7    19  20  28  31  53  56 [ 61 ] 65  75  66  79
j = 8    19  20  28  31  53  56  61 [ 65 ] 75  66  79
j = 10   19  20  28  31  53  56  61  65  66 [ 75 ] 79
10th smallest element is 75


1. Select.
2. Exit.

Enter choice : 2
Exiting...

1. Select Integer.
2. Select Character.
3. Exit.
Enter choice : 2
Enter number of elements : 12
Enter element 1 : S
Enter element 2 : N
Enter element 3 : E
Enter element 4 : V
Enter element 5 : B
Enter element 6 : O
Enter element 7 : T
Enter element 8 : H
Enter element 9 : K
Enter element 10 : Z
Enter element 11 : M
Enter element 12 : I


1. Select.
2. Exit.

Enter choice : 1

Select the kth Element : 5
j = 9    K  N  E  I  B  O  M  H [ S ] Z  T  V
j = 5    B  H  E  I [ K ] O  M  N  S  Z  T  V
5th smallest element is K


1. Select.
2. Exit.

Enter choice : 1

Select the kth Element : 9
j = 1   [ B ] H  E  I  K  O  M  N  S  Z  T  V
j = 3    B  E [ H ] I  K  O  M  N  S  Z  T  V
j = 4    B  E  H [ I ] K  O  M  N  S  Z  T  V
j = 5    B  E  H  I [ K ] O  M  N  S  Z  T  V
j = 8    B  E  H  I  K  N  M [ O ] S  Z  T  V
j = 9    B  E  H  I  K  N  M  O [ S ] Z  T  V
9th smallest element is S


1. Select.
2. Exit.

Enter choice : 2
Exiting...

1. Select Integer.
2. Select Character.
3. Exit.
Enter choice : 2
Exiting...
*/