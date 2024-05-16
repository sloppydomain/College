#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int coeff;
    int exp;
    struct node *link;
};
void Display(struct node *);
struct node *sort_list(struct node *start)
{
    struct node *p1, *p2;
    int temp_coeff, temp_exp;
    p1 = start;
    while (p1 != NULL)
    {
        p2 = p1->link;
        while (p2 != NULL)
        {
            if (p2->exp > p1->exp)
            {
                temp_coeff = p2->coeff;
                temp_exp = p2->exp;
                p2->coeff = p1->coeff;
                p2->exp = p1->exp;
                p1->coeff = temp_coeff;
                p1->exp = temp_exp;
            }
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    return start;
}
struct node *insert_emptylist(struct node *start, int c, int e)
{
    if (start != NULL)
    {
        printf("List is not empty\n");
        exit(0);
    }
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->exp = e;
    p->coeff = c;
    p->link = start;
    start = p;
    return start;
}
struct node *insertatend(struct node *start, int c, int e)
{
    struct node *p, *tmp;
    p = (struct node *)malloc(sizeof(struct node));
    p->exp = e;
    p->coeff = c;
    p->link = NULL;

    if (start == NULL)
    {
        start = p;
    }
    else
    {
        tmp = start;
        while (tmp->link != NULL)
        {
            tmp = tmp->link;
        }
        tmp->link = p;
    }
    return start;
}

struct node *create_list(struct node *start)
{
    int i, c, e, n;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    if (n == 0)
        return start;
    printf("Enter coefficient of 1 term : ");
    scanf("%d", &c);
    printf("Enter exponent of 1 term : ");
    scanf("%d", &e);
    start = insert_emptylist(start, c, e);
    struct node *p = start;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter coefficient of %d term : ", i);
        scanf("%d", &c);
        printf("Enter exponent of %d term : ", i);
        scanf("%d", &e);
        start = insertatend(start, c, e);
    }
    start = sort_list(start);
    return start;
}
void polyadd(struct node *poly1, struct node *poly2)
{
    struct node *ptr1 = poly1;
    struct node *ptr2 = poly2;
    struct node *ptr3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            ptr3 = insertatend(ptr3, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            ptr3 = insertatend(ptr3, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->link;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            ptr3 = insertatend(ptr3, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->link;
        }
    }
    while (ptr1 != NULL)
    {
        ptr3 = insertatend(ptr3, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        ptr3 = insertatend(ptr3, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->link;
    }
    printf("Added polynomial is : ");
    Display(ptr3);
}
struct node *simplify(struct node *poly3)
{
    struct node *p3 = poly3;
    struct node *temp;
    while (p3->link != NULL)
    {
        if (p3->exp == p3->link->exp)
        {
            p3->coeff = p3->coeff + p3->link->coeff;
            temp = p3->link;
            p3->link = temp->link;
            free(temp);
            temp = NULL;
        }
        else
            p3 = p3->link;
    }
    return poly3;
}
struct node *multiply(struct node *poly1, struct node *poly2)
{
    struct node *p3 = NULL;
    struct node *p1 = poly1, *p2 = poly2;
    while (p1 != NULL)
    {
        p2 = poly2;
        while (p2 != NULL)
        {
            p3 = insertatend(p3, (p1->coeff) * (p2->coeff), p1->exp + p2->exp);
            p2 = p2->link;
        }
        p2 = poly2;
        p1 = p1->link;
    }
    p3 = sort_list(p3);
    p3 = simplify(p3);
    printf("Multiplied polynomial is : ");
    Display(p3);
    return p3;
}
struct node *delete(struct node *start, int e)
{
    struct node *p, *tmp;
    if (start == NULL)
    {
        printf("List is empty..\n");
        exit(1);
    }
    if (start->exp == e)
    {
        p = start;
        start = p->link;
        free(p);
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->exp == e)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found \n", e);
    return start;
}
struct node *modifyPoly(struct node *start)
{
    int choice, c, e;
    while (1)
    {
        printf("1.Insert term\n");
        printf("2.Delete term\n");
        printf("3.Exit...\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the coefficient : ");
            scanf("%d", &c);
            printf("Enter the exponent : ");
            scanf("%d", &e);
            start = insertatend(start, c, e);
            printf("Polynomial after inserting : ");
            simplify(start);
            sort_list(start);
            Display(start);
            break;
        case 2:
            printf("Enter the exponent for deletion : ");
            scanf("%d", &e);
            start = delete (start, e);
            printf("Polynomial after deleting : ");
            simplify(start);
            sort_list(start);
            Display(start);
            break;
        case 3:
            printf("Exiting...");
            goto jump;
        case 4:
            printf("Invalid choice....\n");
            break;
        }
    }
jump:
    return start;
}
void readPolynomialFromFile(const char *filename, struct node **poly1, struct node **poly2)
{
    FILE *p = fopen(filename, "r");
    if (p == NULL)
    {
        printf("Cannot open the file.\n");
        exit(0);
    }
    int n1, n2, c, e;
    fscanf(p, "%d", &n1);
    *poly1 = NULL;
    for (int i = 0; i < n1; i++)
    {
        fscanf(p, "%d %d", &c, &e);
        *poly1 = insertatend(*poly1, c, e);
    }
    fscanf(p, "%d", &n2);
    *poly2 = NULL;
    for (int i = 0; i < n2; i++)
    {
        fscanf(p, "%d %d", &c, &e);
        *poly2 = insertatend(*poly2, c, e);
    }
    fclose(p);
}
void createPolynomialToFile(const char *filename)
{
    FILE *p = fopen(filename, "w");
    if (p == NULL)
    {
        printf("Cannot open the file.\n");
        exit(0);
    }

    int numTerms;
    printf("Enter the number of terms in polynomial 1 : ");
    scanf("%d", &numTerms);
    fprintf(p, "%d\n", numTerms);

    for (int i = 0; i < numTerms; i++)
    {
        int coeff, exp;
        printf("Enter the coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        fprintf(p, "%d %d\n", coeff, exp);
    }
    printf("Enter the number of terms in polynomial 2 : ");
    scanf("%d", &numTerms);
    fprintf(p, "%d\n", numTerms);

    for (int i = 0; i < numTerms; i++)
    {
        int coeff, exp;
        printf("Enter the coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        fprintf(p, "%d %d\n", coeff, exp);
    }
    fclose(p);
}

int main()
{
    struct node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    printf("Enter the first polynomial : \n");
    poly1 = create_list(poly1);
    printf("Enter the second polynomial : \n");
    poly2 = create_list(poly2);
    printf("Polynomial 1 : ");
    Display(poly1);
    printf("Polynomial 2 : ");
    Display(poly2);
    int choice;
    char filename[20];
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Display polynomials\n");
        printf("2. Add polynomials\n");
        printf("3. Multiply polynomials\n");
        printf("4. Write to a file\n");
        printf("5. Read polynomial from a file\n");
        printf("6. Modify Polynomial 1\n");
        printf("7. Modify Polynomial 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Polynomial 1: ");
            Display(poly1);
            printf("Polynomial 2: ");
            Display(poly2);
            break;
        case 2:
            polyadd(poly1, poly2);
            break;
        case 3:
            poly3 = multiply(poly1, poly2);
            break;
        case 4:
            printf("Enter a filename : ");
            // fgets(filename, sizeof(filename), stdin);
            // filename[strcspn(filename, "\n")] = '\0';
            scanf("%s", filename);
            strcat(filename, ".txt");
            createPolynomialToFile(filename);
            break;
        case 5:
            printf("Enter the filename : ");
            // fgets(filename, sizeof(filename), stdin);
            // filename[strcspn(filename, "\n")] = '\0';
            scanf("%s", filename);
            readPolynomialFromFile(filename, &poly1, &poly2);
            break;
        case 6:
            poly1 = modifyPoly(poly1);
            break;
        case 7:
            poly2 = modifyPoly(poly2);
            break;
        case 8:
            printf("Exiting the program.\n");
            goto jump;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
jump:
    free(poly1);
    free(poly2);
    free(poly3);
    return 0;
}
void Display(struct node *start)
{
    simplify(start);
    sort_list(start);
    struct node *p = start;
    if (start == NULL)
    {
        printf("Polynomial is empty..\n");
        exit(1);
    }
    else
    {
        while (p != NULL)
        {
            printf("%dx^%d", p->coeff, p->exp);
            p = p->link;
            if (p != NULL)
            {
                printf(" + ");
            }
            else
                printf("\n");
        }
    }
}