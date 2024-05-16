#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main()
{
    int *arr = NULL;
    int n;
    printf("Enter array elements (-1 to stop): \n");
    int i = 0;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        arr = (int *)realloc(arr, (i + 1) * sizeof(int));
        if (arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        arr[i] = n;
        i++;
    }
    if (i == 0)
    {
        printf("Array is empty.\n");
        return 1;
    }
    printf("Enter element to be searched: ");
    scanf("%d", &n);

    int index = BinarySearch(arr, i, n);

    if (index == -1)
        printf("%d not found in the array\n", n);
    else
        printf("%d found at position %d\n", n, index + 1);
    free(arr);
    return 0;
}
