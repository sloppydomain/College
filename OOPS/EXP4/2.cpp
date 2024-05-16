#include <iostream>
using namespace std;

class MyClass
{
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    MyClass operator+(const MyClass &other)
    {
        return MyClass(value + other.value);
    }

    MyClass operator*(const MyClass &other)
    {
        return MyClass(value * other.value);
    }

    MyClass operator-(const MyClass &other)
    {
        return MyClass(value - other.value);
    }

    friend MyClass operator+(int val,const MyClass &other)
    {
        return MyClass(other.value + val);
    }

    void display()
    {
        cout << "Value: " << value << endl;
    }
};


int main()
{
    MyClass x(5);
    MyClass y(3);
    
    x = 5 + y;
    cout << "i. x = 5 + y:" << endl;
    x.display();

    x = MyClass(5);
    y = MyClass(3);

    
    x = x * y;
    cout << "ii. x = x * y:" << endl;
    x.display();

    x = MyClass(5);
    y = MyClass(3);

    x = y - MyClass(5);
    cout << "iii. x = y - 5:" << endl;
    x.display();

    return 0;
}
