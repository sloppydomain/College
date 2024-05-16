//Q3
#include <iostream>
using namespace std;
class a
{
public:
    int x;
    void display()
    {
        cout << "\nThis is class a \n";
        x = 111;
    }
};
class b
{
public:
    void display()
    {
        a s;
        cout << "Now member function 'display()' of class a is calling from class b \n";
        s.display();
        cout << " x = " << s.x << "\n";
    }
};
int main()
{
    b t; // t is a object of class b.
    t.display();
    return 0;
}
/*
OUTPUT - 
Now member function 'display()' of class a is calling from class b 

This is class a 
 x = 111
 */