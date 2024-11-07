#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[100], q_size, head, seek = 0, diff;
    float avg;
    printf("***** FCFS Disk Scheduling Algorithm *****\n");
    printf("Enter the size of the queue: ");
    scanf("%d", &q_size);
    printf("Enter the queue elements:\n");
    for (int i = 1; i <= q_size; i++) {
        printf("Request %d: ", i);
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    queue[0] = head;
    printf("\nDisk Movement Sequence:\n");
    printf("-------------------------------------\n");
    printf("| From Position | To Position | Seek |\n");
    printf("-------------------------------------\n");
    for (int j = 0; j < q_size; j++) {
        diff = abs(queue[j] - queue[j + 1]);
        seek += diff;
        printf("|      %3d      |     %3d     | %3d  |\n", queue[j], queue[j + 1], diff);
    }
    printf("-------------------------------------\n");
    printf("\nTotal seek time: %d\n", seek);
    avg = seek / (float) q_size;
    printf("Average seek time: %.2f\n", avg);
    return 0;
}

/*
OUTPUT:
***** FCFS Disk Scheduling Algorithm *****
Enter the size of the queue: 8
Enter the queue elements:
Request 1: 176
Request 2: 79
Request 3: 34
Request 4: 60
Request 5: 92
Request 6: 11
Request 7: 41
Request 8: 114
Enter the initial head position: 50

Disk Movement Sequence:
-------------------------------------
| From Position | To Position | Seek |
-------------------------------------
|       50      |     176     | 126  |
|      176      |      79     |  97  |
|       79      |      34     |  45  |
|       34      |      60     |  26  |
|       60      |      92     |  32  |
|       92      |      11     |  81  |
|       11      |      41     |  30  |
|       41      |     114     |  73  |
-------------------------------------

Total seek time: 510
Average seek time: 63.75
*/