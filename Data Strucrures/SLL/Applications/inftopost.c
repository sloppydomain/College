#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX 50
#define BLANK ' '
#define TAB '\t'
char infix[MAX];
char postfix[MAX];
long int stack_i[MAX];
double stack_d[MAX];
int top = -1;

void push_int(long int x)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow");
        exit(0);
    }
    stack_i[++top] = x;
}
void print_stack_int()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%ld", stack_i[i]);
        if (i != top)
            printf(",");
    }
    printf("\n");
}
void print_stack_double()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%.4lf", stack_d[i]);
        if (i != top)
            printf(",");
    }
    printf("\n");
}
void push_double(double x)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow");
        exit(0);
    }
    stack_d[++top] = x;
}

long int pop_int()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        exit(0);
    }
    long int x = stack_i[top--];
    return x;
}
double pop_double()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        exit(0);
    }
    double x = stack_d[top--];
    return x;
}
int whitespace(char symbol)
{
    if (symbol == BLANK || symbol == TAB || symbol == ' ')
        return 1;
    else
        return 0;
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

void infix_to_postfix()
{
    int i, p = 0;
    char symbol, next;
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        if (!whitespace(symbol))
        {
            switch (symbol)
            {
            case '(':
                push_int(symbol);
                break;
            case ')':
                while ((next = pop_int()) != '(')
                    postfix[p++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (top != -1 && instack_priority(stack_i[top]) >= incoming_priority(symbol))
                    postfix[p++] = pop_int();
                push_int(symbol);
                break;
            default:
                postfix[p++] = symbol;
                break;
            }
        }
    }
    while (top != -1)
        postfix[p++] = pop_int();
    postfix[p] = '\0';
}

long int eval_int_postfix()
{
    int i;
    long int a, b, temp, result;
    printf("Symbol :\t\tStack :\n");
    for (i = 0; i < strlen(postfix); i++)
    {
        printf("%c\t\t\t", postfix[i]);
        if (isdigit(postfix[i]))
        {
            push_int(postfix[i] - '0');
            print_stack_int();
        }
        else
        {
            a = pop_int();
            b = pop_int();
            switch (postfix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = (long int)pow(b, a);
                break;
            }
            push_int(temp);
            print_stack_int();
        }
    }
    result = pop_int();
    return result;
}
double eval_double_postfix()
{
    int i;
    double a, b, temp, result;
    printf("Symbol :\t\tStack :\n");
    for (i = 0; i < strlen(postfix); i++)
    {
        printf("%c\t\t\t", postfix[i]);
        if (isdigit(postfix[i]))
        {
            push_double(postfix[i] - '0');
            print_stack_double();
        }
        else if (isalpha(postfix[i]))
        {
            printf("Variables not supported for evaluation...\n");
            exit(1);
        }
        else
        {
            a = pop_double();
            b = pop_double();
            switch (postfix[i])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '^':
                temp = (long int)pow(b, a);
                break;
            }
            push_double(temp);
            print_stack_double();
        }
    }
    result = pop_double();
    return result;
}

int main()
{
    double num;
    printf("Enter infix expression: ");
    gets(infix);
    int choice;
    printf("1. Long int\n");
    printf("2. Double\n");
    printf("Enter the type of evaluation : ");
    scanf("%d", &choice);
    if (choice != 1 && choice != 2)
    {
        printf("Invalid Choice\n");
        exit(1);
    }
    infix_to_postfix();
    printf("Character Postfix expression: %s\n", postfix);
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (isalpha(postfix[i]))
        {
            printf("Enter the value of %c: ", postfix[i]);
            scanf("%lf", &num);
            postfix[i] = num + '0';
        }
    }
    printf("Number postfix expression: %s\n", postfix);
    if (choice == 1)
    {
        long int value1 = eval_int_postfix();
        printf("\nThe value of the expression(long int) is: %ld\n", value1);
    }
    else
    {
        double value2 = eval_double_postfix();
        printf("\nThe value of the expression(long double) is: %.4lf\n", value2);
    }
    return 0;
}
/*
Enter infix expression: (a+b)/(c-d)-(e*f)
1. Long int
2. Double
Enter the type of evaluation : 2
Character Postfix expression: ab+cd-/ef*-
Enter the value of a: 2
Enter the value of b: 2
Enter the value of c: 3
Enter the value of d: 2
Enter the value of e: 4
Enter the value of f: 5
Number postfix expression: 22+32-/45*-
Symbol :                Stack :
2                       2.0000
2                       2.0000,2.0000
+                       4.0000
3                       4.0000,3.0000
2                       4.0000,3.0000,2.0000
-                       4.0000,1.0000
/                       4.0000
4                       4.0000,4.0000
5                       4.0000,4.0000,5.0000
*                       4.0000,20.0000
-                       -16.0000

The value of the expression(long double) is: -16.0000

Enter infix expression: a+b*c/(e-f)
1. Long int
2. Double
Enter the type of evaluation : 1
Character Postfix expression: abc*ef-/+
Enter the value of a: 2
Enter the value of b: 3
Enter the value of c: 3
Enter the value of e: 4
Enter the value of f: 2
Number postfix expression: 233*42-/+
Symbol :                Stack :
2                       2
3                       2,3
3                       2,3,3
*                       2,9
4                       2,9,4
2                       2,9,4,2
-                       2,9,2
/                       2,4
+                       6

The value of the expression(long int) is: 6
*/