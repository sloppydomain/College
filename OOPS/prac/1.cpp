#include <iostream>
using namespace std;
int m = 0;
class Complex
{
    double real;
    double img;

public:
    Complex(double x, double y) : real(x), img(y) {}
    Complex() : real(0), img(0) {}
    friend ostream &operator<<(ostream &dout, const Complex &obj);
    friend istream &operator>>(istream &din, Complex &obj);
};
ostream &operator<<(ostream &dout, const Complex &obj)
{
    cout << "\n";
    dout << obj.real << " + " << obj.img << "i\n";
    return dout;
}
istream &operator>>(istream &din, Complex &obj)
{
    m++;
    cout << "Enter Real part of number " << m << " : ";
    din >> obj.real;
    cout << "Enter Imaginary part of number " << m << " : ";
    din >> obj.img;
    return din;
}
template <typename T>
class Vector
{
    T *v;
    int n;

public:
    Vector() : v(nullptr), n(0) {}
    Vector(int n)
    {
        this->n = n;
        v = new T[n];
    }
    T &operator[](int i)
    {
        return v[i];
    }
};
int main()
{
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    Vector<Complex> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";
    return 0;
}
