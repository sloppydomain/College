#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SIZE;
int DISK_SIZE = 200;

void scan(int arr[], int head, char direction[]) {
    int h = head;
    int seek_count = 0;
    int distance, cur_track;
    int left[SIZE + 1], right[SIZE + 1];
    int left_size = 0, right_size = 0;
    int seek_sequence[SIZE + 2], seek_sequence_index = 0;
    if (strcmp(direction, "left") == 0) {
        left[left_size++] = 0;
    } else if (strcmp(direction, "right") == 0) {
        right[right_size++] = DISK_SIZE - 1;
    }
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        else if (arr[i] > head)
            right[right_size++] = arr[i];
    }
    for (int i = 0; i < left_size - 1; i++) {
        for (int j = i + 1; j < left_size; j++) {
            if (left[i] > left[j]) {
                int temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }
    for (int i = 0; i < right_size - 1; i++) {
        for (int j = i + 1; j < right_size; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
            }
        }
    }
    int run = 2;
    while (run--) {
        if (strcmp(direction, "left") == 0) {
            for (int i = left_size - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence[seek_sequence_index++] = cur_track;

                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "right");
        } else if (strcmp(direction, "right") == 0) {
            for (int i = 0; i < right_size; i++) {
                cur_track = right[i];
                seek_sequence[seek_sequence_index++] = cur_track;

                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "left");
        }
    }
    for (int i = seek_sequence_index - 1; i >= 0; i--) {
        seek_sequence[i + 1] = seek_sequence[i];
    }
    seek_sequence[0] = h;
    printf("\nDisk Movement Sequence:\n");
    printf("-------------------------------------\n");
    printf("| From Position | To Position | Seek |\n");
    printf("-------------------------------------\n");
    for (int i = 1; i <= seek_sequence_index; i++) {
        int seekDistance = abs(seek_sequence[i] - seek_sequence[i - 1]);
        printf("|      %3d       |     %3d      |  %3d |\n", seek_sequence[i - 1], seek_sequence[i], seekDistance);
    }
	printf("-------------------------------------\n");
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is: ");
    for (int i = 0; i <= seek_sequence_index; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}

int main() {
    int head;
    printf("***** SCAN Disk Scheduling Algorithm *****\n");
    printf("Enter the number of requests: ");
    scanf("%d", &SIZE);
    int request[SIZE];
    printf("Enter the request sequence: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &request[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    char direction[6];
    printf("Enter the initial direction (left/right): ");
    scanf("%s", direction);
    scan(request, head, direction);
    return 0;
}

/*
OUTPUT:
***** SCAN Disk Scheduling Algorithm *****
Enter the number of requests: 8
Enter the request sequence: 176 79 34 60 92 11 41 114
Enter the initial head position: 50
Enter the initial direction (left/right): left

Disk Movement Sequence:
-------------------------------------
| From Position | To Position | Seek |
-------------------------------------
|       50       |      41      |    9 |
|       41       |      34      |    7 |
|       34       |      11      |   23 |
|       11       |       0      |   11 |
|        0       |      60      |   60 |
|       60       |      79      |   19 |
|       79       |      92      |   13 |
|       92       |     114      |   22 |
|      114       |     176      |   62 |
-------------------------------------
Total number of seek operations = 226
Seek Sequence is: 50 41 34 11 0 60 79 92 114 176 
*/