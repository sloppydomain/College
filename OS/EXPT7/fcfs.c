#include <stdio.h>

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
    int frames[numFrames];
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;  
    }
    int pageFaults = 0;
    int index = 0;  
    printf("\nPage Reference\tFrames\t\tPage Fault\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < numPages; i++) {
        int flag = 0;  
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;  
                break;
            }
        }
        if (flag == 0) {
            frames[index] = pages[i];
            index = (index + 1) % numFrames;
            pageFaults++;
            printf("%d\t\t", pages[i]);
            for (int k = 0; k < numFrames; k++) {
                if (frames[k] != -1) {
                    printf("%d ", frames[k]);
                } else {
                    printf("- ");
                }
            }
            printf("\tPage Fault\n");
        } else {
            printf("%d\t\t", pages[i]);
            for (int k = 0; k < numFrames; k++) {
                if (frames[k] != -1) {
                    printf("%d ", frames[k]);
                } else {
                    printf("- ");
                }
            }
            printf("\tNo Page Fault\n");
        }
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}

/*
OUTPUT:
Enter number of frames: 3
Enter number of pages: 7
Enter the page reference sequence: 1 3 0 3 5 6 3

Page Reference  Frames          Page Fault
---------------------------------------------------
1               1 - -   Page Fault
3               1 3 -   Page Fault
0               1 3 0   Page Fault
3               1 3 0   No Page Fault
5               5 3 0   Page Fault
6               5 6 0   Page Fault
3               5 6 3   Page Fault

Total Page Faults = 6
*/