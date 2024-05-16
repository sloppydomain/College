#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct Employee
{
    int id;
    char name[MAX];
    char address[MAX];
};
int LinearSearch(struct Employee *arr, int x, int n)
{
    int i = 0;
    while (i < n && arr[i].id != x)
        i++;
    if (i < n)
        return i;
    else
        return -1;
}
int main()
{
    int n;
    char name[MAX];
    char a[MAX];
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    struct Employee *arr = (struct Employee *)malloc(n * sizeof(struct Employee));
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter ID of Employee %d: ", i + 1);
        scanf("%d", &(arr[i]).id);
        printf("Enter Name of Employee %d: ", i + 1);
        scanf("%s", (arr[i].name));
        printf("Enter Address of Employee %d: ", i + 1);
        scanf("%s", (arr[i].address));
    }
    int m;
    printf("\nEnter ID of employee to be searched : ");
    scanf("%d", &m);
    int t = LinearSearch(arr, m, n);
    if (t == -1)
        printf("Element not found...\n");
    else
        printf("Element found at position %d...", t + 1);
    return 0;
}
/*
OUTPUT - 
Enter the number of terms : 5

Enter ID of Employee 1: 10
Enter Name of Employee 1: YASH        
Enter Address of Employee 1: NABSJJ
Enter ID of Employee 2: 11
Enter Name of Employee 2: PIYUSH
Enter Address of Employee 2: KANS
Enter ID of Employee 3: 12
Enter Name of Employee 3: KAMSKAMS
Enter Address of Employee 3: KMASS
Enter ID of Employee 4: 34
Enter Name of Employee 4: KSNJNDJ
Enter Address of Employee 4: JSKA
Enter ID of Employee 5: 56
Enter Name of Employee 5: AVIN
Enter Address of Employee 5: JSDND

Enter ID of employee to be searched : 56
Element found at position 5...
*/