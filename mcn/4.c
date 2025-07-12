#include <stdio.h>
#include <stdlib.h>

void printH() {
    printf("----");
}

void printV() {
    printf("|");
}

void printS(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// manchester encoding
void mes(int n, char *s) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printS(4);
            printf("%c", s[i]);
        } else if (s[i] != s[i - 1]) {
            printS(8);
            printf("%c", s[i]);
        } else {
            printS(9);
            printf("%c", s[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            printH();
            if (i + 1 < n && s[i + 1] != s[i]) {
                printS(5);
            } else {
                printS(6);
            }
        } else {
            if (i == 0 || i - 1 >= 0 && s[i - 1] != s[i]) {
                printS(5);
            } else {
                printS(6);
            }
            printH();
        }
    }
    printf("\n");
    for (int r = 0; r < 2; r++) {
        for (int i = 0; i < n; i++) {
            printS(4);
            printV();
            printS(4);
            if (i + 1 < n && s[i + 1] == s[i]) {
                printV();
            }
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i == 0 || i - 1 >= 0 && s[i - 1] != s[i]) {
                printS(5);
            } else {
                printS(6);
            }
            printH();
        } else {
            printH();
            if (i + 1 < n && s[i + 1] != s[i]) {
                printS(5);
            } else {
                printS(6);
            }
        }
    }
    printf("\n");
}

void me(int n, char *s, char *e) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            e[j++] = '1';
            e[j++] = '0';
        } else {
            e[j++] = '0';
            e[j++] = '1';
        }
    }
    e[j] = '\0';
};

void md(int n, char *s, char *d, char *e) {
    int j = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (e[i] == '0' && e[i + 1] == '1') {
            d[j++] = '1';
        } else if (e[i] == '1' && e[i + 1] == '0') {
            d[j++] = '0';
        }
    }
    d[j] = '\0';
};

// differential machester encoding
void dmes(int n, char *s) {
    char d;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '0') {
                printS(5);
                printf("%c", s[i]);
            } else {
                printS(4);
                printf("%c", s[i]);
            }
        } else if (s[i] == '1') {
            printS(8);
            printf("%c", s[i]);
        } else {
            printS(9);
            printf("%c", s[i]);
        }
    }
    printf("\n");
    int r;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '0') {
                printS(6);
                printH();
                r = 1;
            } else {
                printH();
                printS(5);
                if (i + 1 < n && s[i] != s[i + 1]) {
                    printS(1);
                }
                r = 0;
            }
        } else if (s[i] == '1') {
            if (!r) {
                printS(5);
                printH();
            } else {
                printH();
                printS(5);
                if (i + 1 < n && s[i] != s[i + 1]) {
                    printS(1);
                }
            }
            r ^= 1;
        } else {
            if (!r) {
                printH();
                printS(5);
                if (i + 1 < n && s[i] == s[i + 1]) {
                    printS(1);
                }
            } else {
                printS(6);
                printH();
            }
        }
    }
    printf("\n");
    for (int r = 0; r < 2; r++) {
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == '0') {
                    printV();
                    printS(4);
                    printV();
                    printS(4);
                } else {
                    printS(4);
                    printV();
                    printS(4);
                }
            } else if (s[i] == '0') {
                printV();
                printS(4);
                printV();
                printS(4);
            } else {
                printS(4);
                printV();
                printS(4);
                r ^= 1;
            }
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '0') {
                printS(1);
                printH();
                printS(5);
                if (i + 1 < n && s[i] == s[i + 1]) {
                    printS(1);
                }
                r = 0;
            } else {
                printS(5);
                printH();
                r = 1;
            } 
        } else if (s[i] == '1') {
            if (!r) {
                printS(5);
                printH();
            } else {
                printH();
                printS(5);
                if (i + 1 < n && s[i] != s[i + 1]) {
                    printS(1);
                }
            }
            r ^= 1;
        } else {
            if (!r) {
                printH();
                printS(5);
                if (i + 1 < n && s[i] == s[i + 1]) {
                    printS(1);
                }
            } else {
                printS(6);
                printH();
            }
        }
    }
    printf("\n");
}

void dme(int n, char *s, char *e) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '0') {
                e[j++] = '0';
                e[j++] = '1';   
            } else {
                e[j++] = '1';
                e[j++] = '0';
            }
        } else if (s[i] == '0') {
            if (e[j - 1] == '1') {
                e[j++] = '0';
                e[j++] = '1';
            } else {
                e[j++] = '1';
                e[j++] = '0';
            }
        } else {
            if (e[j - 1] == '0') {
                e[j++] = '0';
                e[j++] = '1';
            } else {
                e[j++] = '1';
                e[j++] = '0';
            }
        }
    }
    e[j] = '\0';
};

void dmd(int n, char *s, char *d, char *e) {
    int j = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (i == 0) {
            if (e[i] == '0' && e[i + 1] == '1') {
                d[j++] = '0';
            } else if (e[i] == '1' && e[i + 1] == '0') {
                d[j++] = '1';
            }
        } else if (e[i] != e[i - 1]) {
            d[j++] = '0';
        } else {
            d[j++] = '1';
        }
    }
    d[j] = '\0';
};

int main () {
    while (1) {
        printf("\n1. Machester Encoding\n2. Differential Manchester Encoding\n3. Exit\n");
        int c;
        if (scanf("%d", &c) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (c == 3) {
            printf("Exiting program...\n");
            exit(0);
        }
        int n;
        scanf("%d", &n);
        char *m = malloc(n * sizeof(char));
        scanf("%s", m);
        printf("Original message: %s\n", m);
        char *e = malloc(2 * n * sizeof(char));
        char *d = malloc(2 * n * sizeof(char));
        switch (c) {
            case 1:
                me(n, m, e);
                printf("Encoded message: %s\n", e);
                md(n, m, d, e);
                mes(n, m);
                printf("Decoded message: %s\n", d);
                break;
            case 2:
                dme(n, m, e);
                printf("Encoded message: %s\n", e);
                dmd(n, m, d, e);
                printf("\n");
                dmes(n, m);
                printf("\n");
                printf("Decoded message: %s\n", d);
                break;
            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }
    }
    return 0;
}

/*
OUTPUT:
1. Machester Encoding
2. Differential Manchester Encoding
3. Exit
1
11
01001100011
Original message: 01001100011
Encoded message: 1001101001011010100101
    0        1        0         0        1         1        0         0         0        1         1
----          --------      ----          ----      --------      ----      ----          ----      ----
    |        |        |    |    |        |    |    |        |    |    |    |    |        |    |    |    
    |        |        |    |    |        |    |    |        |    |    |    |    |        |    |    |    
     --------          ----      --------      ----          ----      ----      --------      ----      
Decoded message: 01001100011

1. Machester Encoding
2. Differential Manchester Encoding
3. Exit
2
11
01001100011
Original message: 01001100011
Encoded message: 0110101001101010100110

     0        1         0         0        1        1         0         0         0        1        1
      --------      ----      ----          --------      ----      ----      ----          --------     
|    |        |    |    |    |    |        |        |    |    |    |    |    |    |        |        |    
|    |        |    |    |    |    |        |        |    |    |    |    |    |    |        |        |    
 ----          ----      ----      --------          ----      ----      ----      --------          ----

Decoded message: 01001100011

1. Machester Encoding
2. Differential Manchester Encoding
3. Exit
3
Exiting program...




Conclusion: Study of machester encoding and differential manchester encoding was successfully done and their c-codees were implemented successfully.
*/