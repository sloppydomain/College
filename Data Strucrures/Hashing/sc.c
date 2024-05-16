// Qc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
struct Employee
{
    int employeeID;
    char name[50];
    int age;
};
struct Node
{
    struct Employee data;
    struct Node *link;
};
struct Node *hashTable[TABLE_SIZE];
void initializeHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}
int calculateHash(int employeeID)
{
    return employeeID % TABLE_SIZE;
}

void insert(struct Employee employee)
{
    
    int hashValue = calculateHash(employee.employeeID);

    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = employee;
    newNode->link = NULL;

    
    if (hashTable[hashValue] == NULL)
    {
        hashTable[hashValue] = newNode;
    }
    else
    {
        newNode->link = hashTable[hashValue];
        hashTable[hashValue] = newNode;
    }
}


void search(int employeeID)
{
    
    int hashValue = calculateHash(employeeID);

    
    struct Node *current = hashTable[hashValue];
    while (current != NULL)
    {
        if (current->data.employeeID == employeeID)
        {
            printf("Employee found:\n");
            printf("Employee ID: %d\n", current->data.employeeID);
            printf("Name: %s\n", current->data.name);
            printf("Age: %d\n", current->data.age);
            return;
        }
        current = current->link;
    }

    printf("Employee with ID %d not found in the hash table.\n", employeeID);
}


void deleteRecord(int employeeID)
{
    
    int hashValue = calculateHash(employeeID);

    struct Node *current = hashTable[hashValue];
    struct Node *prev = NULL;

    while (current != NULL && current->data.employeeID != employeeID)
    {
        prev = current;
        current = current->link;
    }
    if (current != NULL)
    {
        if (prev == NULL)
        {
            hashTable[hashValue] = current->link;
        }
        else
        {
            prev->link = current->link;
        }

        free(current);
        printf("Employee with ID %d deleted from the hash table.\n", employeeID);
    }
    else
    {
        printf("Employee with ID %d not found in the hash table. Deletion failed.\n", employeeID);
    }
}
void displayHashTable()
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d]: ", i);
        struct Node *current = hashTable[i];
        while (current != NULL)
        {
            printf("ID: %d, Name: %s, Age: %d -> ", current->data.employeeID, current->data.name, current->data.age);
            current = current->link;
        }
        printf("NULL\n");
    }
}

void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Insert an employee\n");
    printf("2. Search for an employee\n");
    printf("3. Delete an employee\n");
    printf("4. Display the hash table\n");
    printf("5. Exit\n");
}

int main()
{
    int choice, employeeID, age;
    char name[50];

    initializeHashTable();

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter employee ID: ");
            scanf("%d", &employeeID);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &age);
            struct Employee newEmployee;
            newEmployee.employeeID = employeeID;
            strcpy(newEmployee.name, name);
            newEmployee.age = age;

            insert(newEmployee);
            break;

        case 2:
            printf("Enter employee ID to search: ");
            scanf("%d", &employeeID);
            search(employeeID);
            break;

        case 3:
            printf("Enter employee ID to delete: ");
            scanf("%d", &employeeID);
            deleteRecord(employeeID);
            break;

        case 4:
            displayHashTable();
            break;

        case 5:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
/*
OUTPUT - 
Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 1
Enter employee ID: 12
Enter name: yash
Enter age: 19

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 1
Enter employee ID: 23
Enter name: piyush
Enter age: 91

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 1
Enter employee ID: 76
Enter name: avin
Enter age: 19

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 1
Enter employee ID: 42
Enter name: kmam
Enter age: 88

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 2
Enter employee ID to search: 42
Employee found:
Employee ID: 42
Name: kmam
Age: 88

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 4
Hash Table:
[0]: NULL
[1]: NULL
[2]: ID: 42, Name: kmam, Age: 88 -> ID: 12, Name: yash, Age: 19 -> NULL
[3]: ID: 23, Name: piyush, Age: 91 -> NULL
[4]: NULL
[5]: NULL
[6]: ID: 76, Name: avin, Age: 19 -> NULL
[7]: NULL
[8]: NULL
[9]: NULL

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 3
Enter employee ID to delete: 12
Employee with ID 12 deleted from the hash table.

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 4
Hash Table:
[0]: NULL
[1]: NULL
[2]: ID: 42, Name: kmam, Age: 88 -> NULL
[3]: ID: 23, Name: piyush, Age: 91 -> NULL
[4]: NULL
[5]: NULL
[6]: ID: 76, Name: avin, Age: 19 -> NULL
[7]: NULL
[8]: NULL
[9]: NULL

Menu:
1. Insert an employee
2. Search for an employee
3. Delete an employee
4. Display the hash table
5. Exit
Enter your choice: 5
Exiting the program.

*/