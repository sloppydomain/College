// Q2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

struct node
{
    char info[50];
    struct node *link;
};

struct node *top = NULL;

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void push(char item[])
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Stack overflow");
        exit(1);
    }
    strcpy(tmp->info, item);
    tmp->link = top;
    top = tmp;
}

char *pop()
{
    if (top == NULL)
    {
        printf("Stack underflow");
        exit(1);
    }
    static char item[50];
    struct node *tmp = top;
    top = top->link;
    strcpy(item, tmp->info);
    free(tmp);
    return item;
}

char *postfix_to_infix(char *postfix)
{
    int len = strlen(postfix);

    for (int i = 0; i < len; i++)
    {
        if (postfix[i] == ' ')
        {
            continue;
        }

        if (isOperator(postfix[i]))
        {
            char op2[MAX_SIZE];
            char op1[MAX_SIZE];
            strcpy(op2, pop());
            strcpy(op1, pop());

            char expression[MAX_SIZE];
            sprintf(expression, "(%s%c%s)", op1, postfix[i], op2);
            push(expression);
        }
        else
        {
            char variable[2];
            variable[0] = postfix[i];
            variable[1] = '\0';
            push(variable);
        }
    }
    return top->info;
}

int main()
{
    int n;
    while (1)
    {
        char postfixExpression[MAX_SIZE];
        printf("Enter a postfix expression: ");
        scanf("%s", postfixExpression);
        char *infixExpression = postfix_to_infix(postfixExpression);
        printf("Infix expression: %s\n", infixExpression);
        printf("\nEnter 1 to continue or 0 to discontinue : ");
        scanf("%d", &n);
        if (n == 0)
            break;
    }
    return 0;
}
/*
OUTPUT - 
Enter a postfix expression: ab+
Infix expression: (a+b)

Enter 1 to continue or 0 to discontinue : 1
Enter a postfix expression: abc*de-/+
Infix expression: (a+((b*c)/(d-e)))

Enter 1 to continue or 0 to discontinue : 0
*/