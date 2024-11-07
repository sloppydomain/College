#include <stdio.h>

void lru(int string[], int n, int size) {
    int frames[n];
    int last_used[n];
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }
    int page_miss = 0, page_hits = 0;
    printf("\nPage Reference\tFrames\t\tPage Fault\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        int symbol = string[i];
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == symbol) {
                flag = 1;
                last_used[j] = i;
                break;
            }
        }
        if (flag == 1) {
            page_hits++;
            printf("%d\t\t", symbol);
            for (int j = 0; j < n; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tNo Page Fault\n");
        } else {
            int replace_index = -1;
            for (int j = 0; j < n; j++) {
                if (frames[j] == -1) {
                    replace_index = j;
                    break;
                }
            }
            if (replace_index == -1) {
                int min_last_used = i;
                for (int j = 0; j < n; j++) {
                    if (last_used[j] < min_last_used) {
                        min_last_used = last_used[j];
                        replace_index = j;
                    }
                }
            }
            frames[replace_index] = symbol;
            last_used[replace_index] = i;
            page_miss++;
            printf("%d\t\t", symbol);
            for (int j = 0; j < n; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tPage Fault\n");
        }
    }
    printf("\nTotal Page Faults = %d\n", page_miss);
}

int main() {
    int numFrames, numPages;
    printf("Enter number of frames: ");
    scanf("%d", &numFrames);
    printf("Enter number of pages: ");
    scanf("%d", &numPages);
    int pages[numPages];
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }
    lru(pages, numFrames, numPages);
    return 0;
}

/*
OUTPUT:
Enter number of frames: 4
Enter number of pages: 14
Enter the page reference sequence: 7 0 1 2 0 3 0 4 2 3 0 3 2 3

Page Reference  Frames          Page Fault
---------------------------------------------------
7               7 - - -         Page Fault
0               7 0 - -         Page Fault
1               7 0 1 -         Page Fault
2               7 0 1 2         Page Fault
0               7 0 1 2         No Page Fault
3               3 0 1 2         Page Fault
0               3 0 1 2         No Page Fault
4               3 0 4 2         Page Fault
2               3 0 4 2         No Page Fault
3               3 0 4 2         No Page Fault
0               3 0 4 2         No Page Fault
3               3 0 4 2         No Page Fault
2               3 0 4 2         No Page Fault
3               3 0 4 2         No Page Fault

Total Page Faults = 6
*/