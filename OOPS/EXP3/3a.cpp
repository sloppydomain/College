#include <iostream>
using namespace std;
class Complex
{
    float m, n;

public:
    Complex() : m(0), n(0){};
    Complex(int m, int n)
    {
        this->m = m;
        this->n = n;
    }
    void Display()
    {
        cout << "The complex number is : ";
        cout << m << " + " << n << "i";
    }
    friend Complex sum(Complex &, Complex &);
};
Complex sum(Complex &a, Complex &b)
{
    Complex c;
    c.m = a.m + b.m;
    c.n = a.n + b.n;
    return c;
}
int main()
{
    Complex a(2, 3);
    Complex b = Complex(3, 4);
    Complex d(44, 66);
    Complex c, e;
    c = sum(a, b);
    e = sum(d, b);
    c.Display();
    cout << "\n";
    e.Display();
    return 0;
}
/*
OUTPUT -

The complex number is : 5 + 7i
*/