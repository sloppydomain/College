#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

float float_stack[MAX];
long int int_stack[MAX];
char infix[MAX];
char prefix[MAX];
int top = -1;
void print_stack_int()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%ld", int_stack[i]);
        if (i != top)
            printf(",");
    }
    printf("\n");
}
void print_stack_float()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%.4lf", float_stack[i]);
        if (i != top)
            printf(",");
    }
    printf("\n");
}
void push_float(float item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    float_stack[++top] = item;
}

float pop_float()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return float_stack[top--];
}

void push_int(long int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    int_stack[++top] = item;
}

long int pop_int()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return int_stack[top--];
}

int instack_priority(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int incoming_priority(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 4;
    }
    return -1;
}

int is_whitespace(char symbol)
{
    return (symbol == BLANK) || (symbol == TAB);
}

void display_step(char symbol)
{
    int i;
    printf("%c\t\t\t", symbol);
    // printf("Stack: ");
    if (top == -1)
    {
        printf("empty");
    }
    else
    {
        for (i = 0; i <= top; i++)
            printf("%c ", int_stack[i]);
    }
    printf("\t\t\t%s\n", prefix);
}

void push_int_display(long int item)
{
    push_int(item);
    display_step(item);
}

void push_float_display(float item)
{
    push_float(item);
    display_step(item);
}

void pop_int_display()
{
    long int item = pop_int();
    display_step(item);
}

void pop_float_display()
{
    float item = pop_float();
    display_step(item);
}

void infix_to_prefix_display()
{
    int i, p = 0;
    char symbol, next;
    printf("\nSymbol :\t\tStack :\t\t\tPrefix :\n");
    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        symbol = infix[i];
        if (!is_whitespace(symbol))
        {
            switch (symbol)
            {
            case ')':
                push_int_display(symbol);
                break;
            case '(':
                while ((next = pop_int()) != ')')
                    prefix[p++] = next;
                display_step('(');
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while ((top != -1) && (instack_priority(int_stack[top]) > incoming_priority(symbol)))
                {
                    prefix[p++] = pop_int();
                }
                push_int_display(symbol);
                break;
            default:
                prefix[p++] = symbol;
                display_step(symbol);
                break;
            }
        }
    }
    while (top != -1)
    {
        prefix[p++] = pop_int();
        display_step(prefix[p - 1]);
    }
    prefix[p] = '\0';

    // Reverse the prefix expression to get the correct order
    int len = strlen(prefix);
    for (i = 0; i < len / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
    printf("\n");
}

long int eval_int_prefix()
{
    int i;
    long int a, b, temp, result;
    printf("Symbol :\t\tStack :\n");
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        printf("%c\t\t\t", prefix[i]);
        if (isdigit(prefix[i]))
        {
            push_int(prefix[i] - '0');
            print_stack_int();
        }
        else
        {
            a = pop_int();
            b = pop_int();
            switch (prefix[i])
            {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '*':
                temp = a * b;
                break;
            case '/':
                temp = a / b;
                break;
            case '%':
                temp = a % b;
                break;
            case '^':
                temp = (long int)pow(a, b);
                break;
            }
            push_int(temp);
            print_stack_int();
        }
    }
    result = pop_int();
    return result;
}

float eval_float_prefix()
{
    int i;
    float a, b, temp, result;
    printf("Symbol :\t\t\tStack :\n");
    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        printf("%c\t\t\t\t", prefix[i]);
        if (isdigit(prefix[i]))
        {
            push_float(prefix[i] - '0');
            print_stack_float();
        }
        else if (isalpha(prefix[i]))
        {
            printf("Variables not supported for evaluation...\n");
            exit(1);
        }
        else
        {
            a = pop_float();
            b = pop_float();

            switch (prefix[i])
            {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '*':
                temp = a * b;
                break;
            case '/':
                temp = a / b;
                break;
            case '^':
                temp = powf(a, b);
                break;
            }
            push_float(temp);
            print_stack_float();
        }
    }
    result = pop_float();
    return result;
}

int main()
{
    int choice;
    printf("Choose the type of evaluation:\n");
    printf("1. Long Int\n");
    printf("2. Float\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter infix expression: ");
    if (fgets(infix, MAX, stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }

    infix[strcspn(infix, "\n")] = '\0';

    int i;
    for (i = 0; i < strlen(infix); i++)
    {
        if (isalpha(infix[i]))
        {
            long int num;
            printf("Enter value for %c: ", infix[i]);
            scanf("%ld", &num);
            infix[i] = num + '0'; // Convert the number to char
        }
    }

    infix_to_prefix_display();
    printf("Character Prefix Expression : %s\n", prefix);
    if (choice == 1)
    {
        long int int_result = eval_int_prefix();
        printf("\nResult (Long Int): %ld\n", int_result);
    }
    else if (choice == 2)
    {
        float float_result = eval_float_prefix();
        printf("Result (Float): %f\n", float_result);
    }

    return 0;
}
/*
Choose the type of evaluation:
1. Long Int
2. Float
Enter your choice: 1
Enter infix expression: (a+b)*(c-d)
Enter value for a: 2
Enter value for b: 2
Enter value for c: 4
Enter value for d: 2

Symbol :                Stack :                 Prefix :
)                       ) 
2                       )                       2
-                       ) -                     2
4                       ) -                     24
)                       empty                   24-
*                       *                       24-
)                       * )                     24-
2                       * )                     24-2
+                       * ) +                   24-2
2                       * ) +                   24-22
)                       *                       24-22+
*                       empty                   24-22+*

Character Prefix Expression : *+22-42
Symbol :                Stack :
2                       2
4                       2,4
-                       2
2                       2,2
2                       2,2,2
+                       2,4
*                       8

Result (Long Int): 8

Choose the type of evaluation:
1. Long Int
2. Float
Enter your choice: 2
Enter infix expression: a-b/(c*d^e)
Enter value for a: 2
Enter value for b: 3
Enter value for c: 2
Enter value for d: 2
Enter value for e: 2

Symbol :                Stack :                 Prefix :
)                       ) 
2                       )                       2
^                       ) ^                     2
2                       ) ^                     22
*                       ) *                     22^
2                       ) *                     22^2
)                       empty                   22^2*
/                       /                       22^2*
3                       /                       22^2*3
-                       -                       22^2*3/
2                       -                       22^2*3/2
-                       empty                   22^2*3/2-

Character Prefix Expression : -2/3*2^22
Symbol :                        Stack :
2                               2.0000
2                               2.0000,2.0000
^                               4.0000
2                               4.0000,2.0000
*                               8.0000
3                               8.0000,3.0000
/                               0.3750
2                               0.3750,2.0000
-                               1.6250
Result (Float): 1.625000
*/