#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int top = -1;
int stack_arr[MAX];

void push(int x) {
    if (top == (MAX - 1)) {
        printf("Stack Overflow\n");
        exit(1); 
    } else {
        stack_arr[++top] = x;
    }
}

int pop() {
    int y;
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);  
    } else {
        y = stack_arr[top--];
    }
    return y;
}

int main() {
    int n, flag = 0;
    printf("Enter the number : ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Binary Representation is: 0\n");
        return 0;
    }

    int t = n;
    while (t != 0) {
        int r = t % 2;
        push(r);
        t /= 2;
        flag++;
    }

    int Binary[MAX];
    for (int j = 0; j < flag; j++) {
        Binary[j] = pop();
    }

    printf("Binary Representation is: ");
    for (int i = 0; i < flag; i++) {
        printf("%d", Binary[i]);
    }

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 20

// int top = -1;
// int stack_arr[MAX];

// void push(int x) {
//     if (top == (MAX - 1)) {
//         printf("Stack Overflow");
//         exit(0);
//     } else {
//         stack_arr[++top] = x;
//     }
// }

// int pop() {
//     int y;
//     if (top == -1) {
//         printf("Stack underflow");
//         exit(0);
//     } else {
//         y = stack_arr[top--];
//     }
//     return y;
// }

// int main() {
//     int n, flag = 0;
//     printf("Enter the number: ");
//     scanf("%d", &n);
//     int t = n;
    
//     while (t != 0) {
//         int r = t % 2;  // Get the remainder when divided by 2
//         push(r);
//         t /= 2;
//         flag++;
//     }
    
//     printf("Binary representation: ");
    
//     // Create an array to store the binary digits
//     int binaryDigits[MAX];
//     for (int j = 0; j < flag; j++) {
//         binaryDigits[j] = pop();
//     }
    
//     // Print the binary digits in reverse order
//     for (int j = flag - 1; j >= 0; j--) {
//         printf("%d", binaryDigits[j]);
//     }
    
//     return 0;
// }
