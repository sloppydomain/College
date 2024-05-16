/*
    author - Yash Malviya
    title - Binary Search
*/
#include <stdio.h>
int bs(int low, int high, char a[], char c)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    printf("\t%d\t%d\t%d\n", low + 1, high + 1, mid + 1);
    if (c > a[mid])
        return bs(mid + 1, high, a, c);
    else if (c < a[mid])
        return bs(low, mid - 1, a, c);
    else
        return mid;
}

int main()
{
    int n;
    printf("Enter number of terms : ");
    scanf("%d", &n);
    char a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf(" %c", &a[i]);
    }
    char temp;
    printf("\nThe character array is : ");
    for (int i = 0; i < n; i++)
        printf("%c ", a[i]);
    printf("\n");
    int choice;
    while (1)
    {
        printf("\n1. Search.");
        printf("\n2. Exit.\n");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter character to be searched : ");
            scanf(" %c", &temp);
            printf("Character = %c\n", temp);
            printf("\tLOW\tHIGH\tMID\n");
            int result = bs(0, n - 1, a, temp);
            if (result == -1)
                printf("Character %c not found", temp);
            else
                printf("Character %c found at position %d", temp, result + 1);
            printf("\n");
            break;
        case 2:
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
Enter number of terms : 11
Enter element 1 : B
Enter element 2 : F
Enter element 3 : H
Enter element 4 : I
Enter element 5 : K
Enter element 6 : M
Enter element 7 : Q
Enter element 8 : S
Enter element 9 : V
Enter element 10 : W
Enter element 11 : X

The character array is : B F H I K M Q S V W X

1. Search.
2. Exit.

Enter choice : 1
Enter character to be searched : Q
Character = Q
        LOW     HIGH    MID
        1       11      6
        7       11      9
        7       8       7
Character Q found at position 7

1. Search.
2. Exit.

Enter choice : 1
Enter character to be searched : A
Character = A
        LOW     HIGH    MID
        1       11      6
        1       5       3
        1       2       1
Character A not found

1. Search.
2. Exit.

Enter choice : 2
Exiting...
*/