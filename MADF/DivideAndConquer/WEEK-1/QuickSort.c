/*
    author - Yash Malviya
    title - QuickSort
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n;
void Display1(int arr[], int pivot, int i, int j, int ok, bool a)
{
    int m = 0;
    int ans = -1;
    while (m < n)
    {
        if (m == i)
        {
            printf("[");
            for (m = i; m < j; m++)
            {
                if (arr[m] == pivot)
                {
                    if (ok == 0)
                        printf("\033[1m[ %d ]\033[0m", arr[m]);
                    else if (ok == 1)
                        printf("\033[1m] %d [\033[0m", arr[m]);
                    if (a)
                        ans = m + 1;
                }
                else
                    printf(" %d ", arr[m]);
            }
            printf("]");
        }
        if (m == n)
            break;
        printf(" %d ", arr[m]);
        m++;
    }
    if (a)
        printf("\tj = %d", ans);
    printf("\n");
}

int partition(int arr[], int i, int j)
{
    int pivot = arr[i], low = i, high = j;
    Display1(arr, pivot, low, high, 0, false);
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
    Display1(arr, pivot, low, high, 0, false);
    int tmp = arr[low];
    arr[low] = arr[j];
    arr[j] = tmp;
    Display1(arr, pivot, low, high, 0, true);
    Display1(arr, pivot, low, high, 1, false);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if (high > low)
    {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot);
        quick_sort(arr, pivot + 1, high);
    }
}

int main()
{
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter size : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\nArray before sorting : ");
    for (int i = 0; i < n; i++)
        printf(" %d ", a[i]);
    printf("\n\n");
    quick_sort(a, 0, n);
    printf("\nArray after sorting : ");
    for (int i = 0; i < n; i++)
        printf(" %d ", a[i]);
    free(a);
    printf("\n");
}

/*
OUTPUT -
Enter size : 9
Enter element 1 : 17
Enter element 2 : -5
Enter element 3 : 22
Enter element 4 : -11
Enter element 5 : 72
Enter element 6 : 55
Enter element 7 : -19
Enter element 8 : 89
Enter element 9 : 23

Array before sorting :  17  -5  22  -11  72  55  -19  89  23

[[ 17 ] -5  22  -11  72  55  -19  89  23 ]
[[ 17 ] -5  -19  -11  72  55  22  89  23 ]
[ -11  -5  -19 [ 17 ] 72  55  22  89  23 ]      j = 4
[ -11  -5  -19 ] 17 [ 72  55  22  89  23 ]
[[ -11 ] -5  -19 ] 17  72  55  22  89  23
[[ -11 ] -19  -5 ] 17  72  55  22  89  23
[ -19 [ -11 ] -5 ] 17  72  55  22  89  23       j = 2
[ -19 ] -11 [ -5 ] 17  72  55  22  89  23
[[ -19 ]] -11  -5  17  72  55  22  89  23
 -19  -11 [[ -5 ]] 17  72  55  22  89  23
 -19  -11  -5  17 [[ 72 ] 55  22  89  23 ]
 -19  -11  -5  17 [[ 72 ] 55  22  23  89 ]
 -19  -11  -5  17 [ 23  55  22 [ 72 ] 89 ]      j = 8
 -19  -11  -5  17 [ 23  55  22 ] 72 [ 89 ]
 -19  -11  -5  17 [[ 23 ] 55  22 ] 72  89
 -19  -11  -5  17 [[ 23 ] 22  55 ] 72  89
 -19  -11  -5  17 [ 22 [ 23 ] 55 ] 72  89       j = 6
 -19  -11  -5  17 [ 22 ] 23 [ 55 ] 72  89
 -19  -11  -5  17 [[ 22 ]] 23  55  72  89
 -19  -11  -5  17  22  23 [[ 55 ]] 72  89
 -19  -11  -5  17  22  23  55  72 [[ 89 ]]

Array after sorting :  -19  -11  -5  17  22  23  55  72  89
*/