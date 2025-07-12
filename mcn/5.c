#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void transmitter1() {
    int n;
    scanf("%d", &n);
    int fz;
    scanf("%d", &fz);
    char *data;
    data = malloc((n * sizeof(char)));
    scanf("%s", data);
    int l = (n + fz - 2) / (fz - 1) + n;
    char *e;
    bool *is;
    e = malloc((l + 1) * sizeof(char));
    is = malloc((l + 1) * sizeof(bool));
    memset(e, ' ', sizeof(e));
    memset(is, false, sizeof(is));
    int j = 0;
    for (int i = 0; i < n; i += fz - 1) {
        if (n - i >= fz - 1) {
            e[j] = (char)(fz + '0');
            is[j] = true;
            j += fz;
        }
        else {
            e[j] = (char)((n - i + 1) + '0');
            is[j] = true;
        }
    }
    j = 0;
    for (int i = 0; i < l; i++) {
        if (!is[i]) {
            e[i] = data[j++];
        }
    }
    e[l] = '\0';
    printf("Encoded word using character count: %s\n", e);
    free(data);
    free(e);
    free(is);
}

void reciever1() {
    int n;
    scanf("%d", &n);
    char *frame = malloc(((n + 1) * sizeof(char)));
    scanf("%s", frame);
    char *d = malloc((n + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (frame[i] >= '1' && frame[i] <= '9') {
            continue;
        } else {
            d[j++] = frame[i];
        }
    }
    d[n] = '\0';
    printf("Decoded word: %s\n", d);
    free(frame);
    free(d);
}

void transmitter2() {
    int n;
    scanf("%d", &n);
    char *data = malloc((n + 1) * sizeof(char));
    scanf("%s", data);
    int bit = 0;
    int m = n;
    for (int i = 0; i < n; i++) {
        bit += (data[i] == '1');
        if (bit == 5 || data[i] == '0') {
            if (bit == 5) {
                m += 1;
            }
            bit = 0;
        }
    }
    char *ans = malloc((m + 1) * sizeof(char));
    bit = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        ans[j++] = data[i];
        if (data[i] == '1') {
            bit += 1;
            if (bit == 5) {
                ans[j++] = '0';
                bit = 0;
            }
        } else {
            bit = 0;
        }
    }
    ans[m] = '\0';
    printf("Data after bit stuffing: %s", ans);
    free(ans);
    free(data);
}

void reciever2() {
    int n;
    scanf("%d", &n);
    char *data = malloc((n + 1) * sizeof(char));
    scanf("%s", data);
    int bit = 0;
    char *ans = malloc((n + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == '1') {
            ans[j++] = data[i];
            bit += 1;
        } else {
            if (i + 1 < n && data[i + 1] == '1' && bit == 5) {
                bit = 0;
                continue;
            }
            bit = 0;
            ans[j++] = data[i];
        }
    }
    printf("Data after bit destuffing: %s", ans);
}

void transmitter3() {
    int n;
    scanf("%d", &n);
    char **data = malloc((n + 2) * sizeof(char *)); 
    for (int i = 0; i < n + 2; i++) {  
        data[i] = malloc(20 * sizeof(char));  
    }
    strcpy(data[0], "flag"); 
    for (int i = 1; i <= n; i++) {
        char *s = malloc(20 * sizeof(char));
        scanf("%s", s); 
        data[i][0] = '\0'; // initialize an empty string
        if (strcmp(s, "flag") == 0) {
            strcat(data[i], "esc ");
            strcat(data[i], "flag");
        } else if (strcmp(s, "esc") == 0) {
            strcat(data[i], "esc ");
            strcat(data[i], "esc");
        } else {
            strcpy(data[i], s);
        }
        free(s);
    }
    strcpy(data[n + 1], "flag");
    printf("\nData after byte stuffing: "); 
    for (int i = 0; i < n + 2; i++) {
        printf("%s ", data[i]);
        free(data[i]);
    }
    free(data);  
}

void reciever3() {
    int n;
    scanf("%d", &n);
    char **data = malloc(n * sizeof(char *));  
    for (int i = 0; i < n; i++) {  
        data[i] = malloc(20 * sizeof(char));  
        scanf("%s", data[i]);
    }
    if (strcmp(data[0], "flag") != 0 || strcmp(data[n - 1], "flag") != 0) {
        printf("Wrong frame values! They should end with flags delimiter\n");
        for (int i = 0; i < n; i++) free(data[i]);
        free(data);
        return;
    }
    char **ans = malloc((n - 2) * sizeof(char *));
    for (int i = 0; i < n - 2; i++) {
        ans[i] = malloc(20 * sizeof(char));
    }
    int in = 0;
    for (int i = 1; i < n - 1; i++) {
        if (strcmp(data[i], "esc") == 0) {
            if (i + 1 < n - 1 && (strcmp(data[i + 1], "flag") == 0 || strcmp(data[i + 1], "esc") == 0)) {
                strcpy(ans[in++], data[i + 1]);
                i++; 
                continue;
            }
        } else {
            strcpy(ans[in++], data[i]);
        }
    }
    printf("\nOriginal data: ");
    for (int i = 0; i < in; i++) {
        printf("%s ", ans[i]);
        free(ans[i]);
    }
    printf("\n");
    free(ans);
    for (int i = 0; i < n; i++) free(data[i]);
    free(data);
}

int main() {
    while (1) {
        printf("\n1. Character Count\n2. Bit stuffing\n3. Byte stuffing\n4. Exit\nEnter choice: ");
        int c1;
        if (scanf("%d", &c1) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (c1) {
            case 1:
                printf("\n-------- CHARACTER COUNT --------\n");
                break;
            case 2:
                printf("\n-------- BIT STUFFING --------\n");
                break;
            case 3:
                printf("\n-------- BYTE STUFFING --------\n");
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }
        while (1) {
            printf("\n1. Transmitter\n2. Receiver\n3. Back to Main Menu\nEnter option: ");
            int c2;
            if (scanf("%d", &c2) != 1) {  
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n'); 
                continue;
            }
            switch (c2) {
                case 1:
                    if (c1 == 1) {
                        transmitter1();
                    } else if (c1 == 2) {
                        transmitter2();
                    } else if (c1 == 3) {
                        transmitter3();
                    }
                    continue;
                case 2:
                    if (c1 == 1) {
                        reciever1();
                    } else if (c1 == 2) {
                        reciever2();
                    } else if (c1 == 3) {
                        reciever3();
                    }
                    continue;
                case 3:
                    printf("Returning to Main Menu...\n");
                    break; 
                default:
                    printf("Wrong option...Try again\n");
                    continue;
            }
            break; 
        }
    }
    return 0;
}

/*
OUTPUT:
1. Character Count
2. Bit stuffing
3. Byte stuffing
4. Exit
Enter choice: 1

-------- CHARACTER COUNT --------

1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 1
11
3
abcdefghijk
Encoded word using character count: 3ab3cd3ef3gh3ij2k

1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 2
17
3ab3cd3ef3gh3ij2k
Decoded word: abcdefghijk

1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 3
Returning to Main Menu...

1. Character Count
2. Bit stuffing
3. Byte stuffing
4. Exit
Enter choice: 2

-------- BIT STUFFING --------

1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 1
11
10111111000
Data after bit stuffing: 101111101000
1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 2
12
101111101000
Data after bit destuffing: 10111111000
1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 3
Returning to Main Menu...

1. Character Count
2. Bit stuffing
3. Byte stuffing
4. Exit
Enter choice: 3

-------- BYTE STUFFING --------

1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 1
4
abc
flag
esc 
def

Data after byte stuffing: flag abc esc flag esc esc def flag 
1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 2
8
flag abc esc flag esc esc def flag

Original data: abc flag esc def 

1. Transmitter
2. Receiver
3. Back to Main Menu
Enter option: 3
Returning to Main Menu...

1. Character Count
2. Bit stuffing
3. Byte stuffing
4. Exit
Enter choice: 4
Exiting program...
*/