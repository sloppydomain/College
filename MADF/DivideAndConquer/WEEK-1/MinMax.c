/*
    author - Yash Malviya
    title - MinMax
*/
#include <stdio.h>
#include <stdlib.h>

void min_max(int a[], int low, int up, int *max, int *min)
{
    static int p = 1;
    if (low == up)
    {
        *max = a[up];
        *min = a[low];
    }
    else if (low == up - 1)
    {
        if (a[low] > a[up])
        {
            *max = a[low];
            *min = a[up];
        }
        else
        {
            *max = a[up];
            *min = a[low];
        }
    }
    else
    {
        int mid = low + (up - low) / 2;
        int max1, min1, max2, min2;
        min_max(a, low, mid, &max1, &min1);
        min_max(a, mid + 1, up, &max2, &min2);
        if (max1 > max2)
            *max = max1;
        else
            *max = max2;
        if (min1 < min2)
            *min = min1;
        else
            *min = min2;
    }
    printf("\nPASS %d : \n(low = %d, High = %d)\nMax = %d\tMin = %d\n", p++, low, up, *max, *min);
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    int min, max;
    min_max(a, 0, n - 1, &max, &min);
    printf("\nMaximum element is %d.\nMinimum element is %d.\n", max, min);
    free(a);
    return 0;
}

/*
OUTPUT -
Enter the number of elements : 9
Enter element 1 : 27
Enter element 2 : -15
Enter element 3 : 32
Enter element 4 : -22
Enter element 5 : 82
Enter element 6 : 65
Enter element 7 : 29
Enter element 8 : 73
Enter element 9 : 37

PASS 1 :
(low = 0, High = 1)
Max = 27        Min = -15

PASS 2 :
(low = 2, High = 2)
Max = 32        Min = 32

PASS 3 :
(low = 0, High = 2)
Max = 32        Min = -15

PASS 4 :
(low = 3, High = 4)
Max = 82        Min = -22

PASS 5 :
(low = 0, High = 4)
Max = 82        Min = -22

PASS 6 :
(low = 5, High = 6)
Max = 65        Min = 29

PASS 7 :
(low = 7, High = 8)
Max = 73        Min = 37

PASS 8 :
(low = 5, High = 8)
Max = 73        Min = 29

PASS 9 :
(low = 0, High = 8)
Max = 82        Min = -22

Maximum element is 82.
Minimum element is -22.
*/