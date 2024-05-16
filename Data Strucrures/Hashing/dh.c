#include <stdio.h>
#include <stdlib.h>
#define MAX 50
enum type_of_record
{
    EMPTY,
    DELETED,
    OCCUPIED
};
struct employee
{
    int empid;
    char name[20];
    int age;
};
struct Record
{
    struct employee info;
    enum type_of_record status;
};
void insert(struct employee emprec, struct Record table[]);
int search(int key, struct Record table[]);
void del(int key, struct Record table[]);
void display(struct Record table[]);
int doubleHash(int key);
int hash(int key);
int main()
{
    struct Record table[MAX];
    struct employee emprec;
    int i, key, choice;
    for (i = 0; i <= MAX - 1; i++)
        table[i].status = EMPTY;
    while (1)
    {
        printf("1. Insert a record\n");
        printf("2. Search a record\n");
        printf("3. Delete a record\n");
        printf("4. Display table\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter empid, name, age : ");
            scanf("%d%s%d", &emprec.empid, emprec.name, &emprec.age);
            insert(emprec, table);
            break;
        case 2:
            printf("Enter a key to be searched : ");
            scanf("%d", &key);
            i = search(key, table);
            if (i == -1)
                printf("Key not found\n");
            else
                printf("Key found at index %d\n", i);
            break;
        case 3:
            printf("Enter a key to be deleted\n");
            scanf("%d", &key);
            del(key, table);
            break;
        case 4:
            display(table);
            break;
        case 5:
            exit(1);
        }
    }
}

int doubleHash(int key)
{
    return (7 + (key % 7));
}

int hash(int key)
{
    return (key % MAX);
}

void insert(struct employee emprec, struct Record table[])
{
    int i, location, h, h2;
    int key = emprec.empid;
    h = hash(key);
    h2 = doubleHash(key);
    location = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[location].status == EMPTY ||
            table[location].status == DELETED)
        {
            table[location].info = emprec;
            table[location].status = OCCUPIED;
            printf("Record inserted\n\n");
            return;
        }
        if (table[location].info.empid == key)
        {
            printf("Duplicate key\n\n");
            return;
        }
        location = (h + i * h2) % MAX;
    }
    printf("Record can't be inserted : Table overFlow\n\n");
}

int search(int key, struct Record table[])
{
    int i, h, h2, location;
    h = hash(key);
    h2 = doubleHash(key);
    location = h;
    for (i = 1; i != MAX - 1; i++)
    {
        if (table[location].status == EMPTY)
            return -1;
        if (table[location].info.empid == key)
            return location;
        location = (h + i * h2) % MAX;
    }
    return -1;
}

void del(int key, struct Record table[])
{
    int location = search(key, table);
    if (location == -1)
        printf("Key not found\n");
    else
        table[location].status = DELETED;
}

void display(struct Record table[])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("[%d] : ", i);
        if (table[i].status == OCCUPIED)
        {
            printf("Occupied : %d %s", table[i].info.empid, table[i].info.name);
            printf(" %d\n", table[i].info.age);
        }
        else if (table[i].status == DELETED)
            printf("Deleted\n");
        else
            printf("Empty\n");
    }
}

/*
OUTPUT - 
1. Insert a record
2. Search a record
3. Delete a record
4. Display table
5. Exit
Enter your choice
1
Enter empid, name, age : 121
yash 19
Record inserted

1. Insert a record
2. Search a record
3. Delete a record
4. Display table
5. Exit
Enter your choice
1
Enter empid, name, age : 123
piyush 19
Record inserted

1. Insert a record
2. Search a record
3. Delete a record
4. Display table
5. Exit
Enter your choice
4
[0] : Empty
[1] : Empty
[2] : Empty
[3] : Empty
[4] : Empty
[5] : Empty
[6] : Empty
[7] : Empty
[8] : Empty
[9] : Empty
[10] : Empty
[11] : Empty
[12] : Empty
[13] : Empty
[14] : Empty
[15] : Empty
[16] : Empty
[17] : Empty
[18] : Empty
[19] : Empty
[20] : Empty
[21] : Occupied : 121 yash 19
[22] : Empty
[23] : Occupied : 123 piyush 19
[24] : Empty
[25] : Empty
[26] : Empty
[27] : Empty
[28] : Empty
[29] : Empty
[30] : Empty
[31] : Empty
[32] : Empty
[33] : Empty
[34] : Empty
[35] : Empty
[36] : Empty
[37] : Empty
[38] : Empty
[39] : Empty
[40] : Empty
[41] : Empty
[42] : Empty
[43] : Empty
[44] : Empty
[45] : Empty
[46] : Empty
[47] : Empty
[48] : Empty
[49] : Empty
1. Insert a record
2. Search a record
3. Delete a record
4. Display table
5. Exit
Enter your choice
2
Enter a key to be searched : 123
Key found at index 23
1. Insert a record
2. Search a record
3. Delete a record
4. Display table
5. Exit
Enter your choice
1
Enter empid, name, age : 223
avin 20
Record inserted

1. Insert a record
2. Search a record
3. Delete a record
4. Display table
5. Exit
Enter your choice
4
[0] : Empty
[1] : Empty
[2] : Empty
[3] : Empty
[4] : Empty
[5] : Empty
[6] : Empty
[7] : Empty
[8] : Empty
[9] : Empty
[10] : Empty
[11] : Empty
[12] : Empty
[13] : Empty
[14] : Empty
[15] : Empty
[16] : Empty
[17] : Empty
[18] : Empty
[19] : Empty
[20] : Empty
[21] : Occupied : 121 yash 19
[22] : Empty
[23] : Occupied : 123 piyush 19
[24] : Empty
[25] : Empty
[26] : Empty
[27] : Empty
[28] : Empty
[29] : Empty
[30] : Empty
[31] : Empty
[32] : Empty
[33] : Empty
[34] : Empty
[35] : Empty
[36] : Occupied : 223 avin 20
[37] : Empty
[38] : Empty
[39] : Empty
[40] : Empty
[41] : Empty
[42] : Empty
[43] : Empty
[44] : Empty
[45] : Empty
[46] : Empty
[47] : Empty
[48] : Empty
[49] : Empty
1. Insert a record
2. Search a record
3. Delete a record
4. Display table
5. Exit
Enter your choice
5
*/