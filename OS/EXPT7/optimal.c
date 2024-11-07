#include <stdio.h>

void optimal(int string[], int n, int size) {
    int frames[n];
    for (int i = 0; i < n; i++)
        frames[i] = -1;
    int page_miss = 0, page_hits = 0, full = 0;
    printf("\nPage Reference\tFrames\t\tPage Fault\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        int symbol = string[i], flag = 0;
        for (int j = 0; j < n; j++) {
            if (symbol == frames[j]) {
                flag = 1;
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
            if (full == 0) {
                int index = page_miss % n;
                frames[index] = symbol;
                page_miss++;
                printf("%d\t\t", symbol);
                for (int j = 0; j < n; j++) {
                    if (frames[j] != -1)
                        printf("%d ", frames[j]);
                    else
                        printf("- ");
                }
                printf("\tPage Fault\n");
                if (page_miss == n)
                    full = 1;
            } else {
                int pos = -1, index = -1;
                for (int j = 0; j < n; j++) {
                    int found = 0;
                    for (int k = i + 1; k < size; k++) {
                        if (frames[j] == string[k]) {
                            found = 1;
                            if (pos < k) {
                                pos = k;
                                index = j;
                            }
                            break;
                        }
                    }
                    if (!found) {
                        pos = size;
                        index = j;
                        break;
                    }
                }
                frames[index] = symbol;
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
    optimal(pages, numFrames, numPages);
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