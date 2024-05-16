/*
    author - Yash Malviya
    title  - StrassenMatrix
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int cnt = 0;
void add(int **a, int **b, int size, int **c)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void sub(int **a, int **b, int size, int **c)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void displaymat(int **matrix, int size, char name)
{
    if (size == 1)
    {
        printf("\n%c : \t%4d", name, matrix[0][0]);
    }
    else
    {

        printf("\n%c :  ", name);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("\t%4d ", matrix[i][j]);
            }
            printf("\n   ");
        }
    }
}
void multiply(int **c, int **d, int size, int size2, int **new, const char *n1, int n2)
{
    if (size == 2)
    {
        int P = (c[0][0] + c[1][1]) * (d[0][0] + d[1][1]);
        int Q = (c[1][0] + c[1][1]) * (d[0][0]);
        int R = (c[0][0] * (d[0][1] - d[1][1]));
        int S = c[1][1] * (d[1][0] - d[0][0]);
        int T = (c[0][0] + c[0][1]) * d[1][1];
        int U = (c[1][0] - c[0][0]) * (d[0][0] + d[0][1]);
        int V = (c[0][1] - c[1][1]) * (d[1][1] + d[1][0]);
        new[0][0] = P + S - T + V;
        new[0][1] = R + T;
        new[1][0] = Q + S;
        new[1][1] = P + R - Q + U;
        if (size2 == 2)
            printf("\nValues Of P, Q, R, S, T : \nP = %d\nQ = %d\nR = %d\nS = %d\nT = %d\nU = %d\nV = %d\n", P, Q, R, S, T, U, V);
    }
    else
    {
        if (n1 == "P")
            n2 = ++cnt;
        int i, j;
        int nsize = size / 2;
        int **c11 = malloc(nsize * sizeof(int *));
        int **c12 = malloc(nsize * sizeof(int *));
        int **c21 = malloc(nsize * sizeof(int *));
        int **c22 = malloc(nsize * sizeof(int *));
        int **d11 = malloc(nsize * sizeof(int *));
        int **d12 = malloc(nsize * sizeof(int *));
        int **d21 = malloc(nsize * sizeof(int *));
        int **d22 = malloc(nsize * sizeof(int *));
        int **p = malloc(nsize * sizeof(int *));
        int **q = malloc(nsize * sizeof(int *));
        int **r = malloc(nsize * sizeof(int *));
        int **s = malloc(nsize * sizeof(int *));
        int **t = malloc(nsize * sizeof(int *));
        int **u = malloc(nsize * sizeof(int *));
        int **v = malloc(nsize * sizeof(int *));
        for (i = 0; i < nsize; i++)
        {
            c11[i] = malloc(nsize * sizeof(int));
            c12[i] = malloc(nsize * sizeof(int));
            c21[i] = malloc(nsize * sizeof(int));
            c22[i] = malloc(nsize * sizeof(int));
            d11[i] = malloc(nsize * sizeof(int));
            d12[i] = malloc(nsize * sizeof(int));
            d21[i] = malloc(nsize * sizeof(int));
            d22[i] = malloc(nsize * sizeof(int));
            p[i] = malloc(nsize * sizeof(int));
            q[i] = malloc(nsize * sizeof(int));
            r[i] = malloc(nsize * sizeof(int));
            s[i] = malloc(nsize * sizeof(int));
            t[i] = malloc(nsize * sizeof(int));
            u[i] = malloc(nsize * sizeof(int));
            v[i] = malloc(nsize * sizeof(int));
        }
        for (i = 0; i < nsize; i++)
        {
            for (j = 0; j < nsize; j++)
            {
                c11[i][j] = c[i][j];
                c12[i][j] = c[i][j + nsize];
                c21[i][j] = c[i + nsize][j];
                c22[i][j] = c[i + nsize][j + nsize];
                d11[i][j] = d[i][j];
                d12[i][j] = d[i][j + nsize];
                d21[i][j] = d[i + nsize][j];
                d22[i][j] = d[i + nsize][j + nsize];
            }
        }
        int **temp1 = malloc(nsize * sizeof(int *));
        int **temp2 = malloc(nsize * sizeof(int *));
        for (i = 0; i < nsize; i++)
        {
            temp1[i] = malloc(nsize * sizeof(int));
            temp2[i] = malloc(nsize * sizeof(int));
        }
        add(c11, c22, nsize, temp1);
        add(d11, d22, nsize, temp2);
        multiply(temp1, temp2, nsize, size, p, "P", cnt);
        add(c21, c22, nsize, temp1);
        multiply(temp1, d11, nsize, size, q, "Q", cnt);
        sub(d12, d22, nsize, temp1);
        multiply(c11, temp1, nsize, size, r, "R", cnt);
        sub(d21, d11, nsize, temp1);
        multiply(c22, temp1, nsize, size, s, "S", cnt);
        add(c11, c12, nsize, temp1);
        multiply(temp1, d22, nsize, size, t, "T", cnt);
        sub(c21, c11, nsize, temp1);
        add(d11, d12, nsize, temp2);
        multiply(temp1, temp2, nsize, size, u, "U", cnt);
        sub(c12, c22, nsize, temp1);
        add(d21, d22, nsize, temp2);
        multiply(temp1, temp2, nsize, size, v, "V", cnt);
        printf("\nValues Of P, Q, R, S, T : \n");
        displaymat(p, nsize, 'P');
        displaymat(q, nsize, 'Q');
        displaymat(r, nsize, 'R');
        displaymat(s, nsize, 'S');
        displaymat(t, nsize, 'T');
        displaymat(u, nsize, 'U');
        displaymat(v, nsize, 'V');
        printf("\n");
        int **te1 = malloc(nsize * sizeof(int *));
        int **te2 = malloc(nsize * sizeof(int *));
        int **te3 = malloc(nsize * sizeof(int *));
        int **te4 = malloc(nsize * sizeof(int *));
        for (i = 0; i < nsize; i++)
        {
            te1[i] = malloc(nsize * sizeof(int));
            te2[i] = malloc(nsize * sizeof(int));
            te3[i] = malloc(nsize * sizeof(int));
            te4[i] = malloc(nsize * sizeof(int));
        }
        add(p, s, nsize, temp1);
        sub(temp1, t, nsize, temp2);
        add(temp2, v, nsize, te1);
        add(r, t, nsize, te2);
        add(s, q, nsize, te3);
        add(p, r, nsize, temp1);
        sub(temp1, q, nsize, temp2);
        add(temp2, u, nsize, te4);
        int a = 0;
        int b = 0;
        for (int i = 0; i < nsize; i++)
            for (int j = 0; j < nsize; j++)
                new[i][j] = te1[i][j];
        for (int i = 0; i < nsize; i++)
            for (int j = nsize; j < size; j++)
                new[i][j] = te2[i][j - nsize];
        for (int i = nsize; i < size; i++)
            for (int j = 0; j < nsize; j++)
                new[i][j] = te3[i - nsize][j];
        for (int i = nsize; i < size; i++)
            for (int j = nsize; j < size; j++)
                new[i][j] = te4[i - nsize][j - nsize];
        free(p);
        free(q);
        free(r);
        free(s);
        free(t);
        free(u);
        free(v);
        free(te1);
        free(te2);
        free(te3);
        free(te4);
        free(c11);
        free(c12);
        free(c21);
        free(c22);
        free(d11);
        free(d12);
        free(d21);
        free(d22);
    }
}

int main()
{
    int size, p, itr, itr1, i, j, nsize;
    printf("Enter Size of matrix : ");
    scanf("%d", &size);
    int tempS = size;
    if (size & (size - 1) != 0)
    {
        p = log(size) / log(2);
        size = pow(2, p + 1);
    }
    int **a = malloc(size * sizeof(int *));
    int **b = malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        a[i] = malloc(size * sizeof(int));
        b[i] = malloc(size * sizeof(int));
    }
    printf("\nEnter elements of 1st matrix : \n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i >= tempS || j >= tempS)
                a[i][j] = 0;
            else
            {
                printf("a%d%d : ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
        }
    }

    printf("\nEnter elements of 2nd matrix : \n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i >= tempS || j >= tempS)
                b[i][j] = 0;
            else
            {
                printf("b%d%d : ", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
        }
    }
    displaymat(a, size, 'A');
    displaymat(b, size, 'B');
    int **new = malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        new[i] = malloc(size * sizeof(int));
    }
    multiply(a, b, size, size, new, "Final Result", cnt);
    if (tempS < size)
        size = tempS;
    printf("\n\nProduct of the 2 matrices: \n");
    displaymat(new, size, 'C');
    printf("\n");
    return 0;
}

/*
OUTPUT -
PROBLEM 1:
Enter Size of matrix : 2

Enter elements of 1st matrix :
a11 : 10
a12 : 2
a21 : -6
a22 : -8

Enter elements of 2nd matrix :
b11 : 7
b12 : -15
b21 : -11
b22 : 3

A :       10       2
          -6      -8

B :        7     -15
         -11       3

Values Of P, Q, R, S, T :
P = 20
Q = -98
R = -180
S = 144
T = 36
U = 128
V = -80


Product of the 2 matrices:

C :       48    -144
          46      66

PROBLEM 2:
Enter Size of matrix : 4

Enter elements of 1st matrix :
a11 : 2
a12 : -3
a13 : 8
a14 : 5
a21 : -8
a22 : 10
a23 : -6
a24 : 4
a31 : -7
a32 : 9
a33 : 11
a34 : 3
a41 :
5
a42 : -2
a43 : -1
a44 : 4

Enter elements of 2nd matrix :
b11 : -2
b12 : -6
b13 : 8
b14 : 6
b21 : 4
b22 : 10
b23 : -5
b24 : 7
b31 : -1
b32 : -7
b33 : 6
b34 : -8
b41 : 8
b42 : 9
b43 : 12
b44 : 4

A :        2      -3       8       5
          -8      10      -6       4
          -7       9      11       3
           5      -2      -1       4

B :       -2      -6       8       6
           4      10      -5       7
          -1      -7       6      -8
           8       9      12       4

Values Of P, Q, R, S, T :

P :       52    -182
         188     322

Q :       40      96
           0      -4

R :       55      19
        -186     -82

S :       23     -14
          15      -3

T :       84     -72
          84     168

U :      -66     204
          90    -204

V :       25      71
         -25      75



Product of the 2 matrices:

C :       16     -53     139     -53
          94     226    -102      86
          63      82       1     -55
          15      -7      92      40
*/