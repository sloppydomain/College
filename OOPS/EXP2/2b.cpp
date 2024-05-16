#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class operations
{
private:
    float a, b;

public:
    void get_data()
    {
        cout << "Enter number 1 : ";
        cin >> a;
        cout << "Enter number 2 : ";
        cin >> b;
    }
    inline void add()
    {
        double add = a + b;
        cout << "Addition of the numbers is : " << add << "\n";
    }
    inline void sub()
    {
        double sub = (a - b);
        cout << "Difference of the numbers is : " << sub << "\n";
    }
    inline void div()
    {
        if (b != 0)
        {
            double div = (float)a / b;
            cout << "Dividing " << a << " by " << b << " gives " << div << "\n";
        }
        else
            cout << "Number cannot be divided by zero..\n";
    }
    inline void mul()
    {
        double mul = a * b;
        cout << "Multiplying " << a << " by " << b << " gives " << mul << "\n";
    }
    inline void power()
    {
        cout << "Power : " << pow(a, b) << "\n";
    }
    inline void mod()
    {
        cout << "Remainder of " << a <<  "/"<<b<<" is "<<fmod(a,b)<<"\n";
    }
    inline void max()
    {
        cout << "Maximum of numbers between " << a << " and " << b << " is " << std::max(a, b) << "\n";
    }
    inline void min()
    {
        cout << "Minimum of numbers between " << a << " and " << b << " is " << std::min(a, b) << "\n";
    }
};
int main()
{
    operations s;
    s.get_data();
    s.add();
    s.sub();
    s.div();
    s.mul();
    s.power();
    s.mod();
    s.max();
    s.min();
    return 0;
}
