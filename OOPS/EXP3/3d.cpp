#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        count++;
        std::cout << "Object created. Total objects: " << count << std::endl;
    }

    ~MyClass()
    {
        count--;
        std::cout << "Object destroyed. Total objects: " << count << std::endl;
    }

    static int getCount()
    {
        return count;
    }

private:
    static int count;
};

int MyClass::count = 0;

int main()
{
    std::cout << "Creating objects..." << std::endl;

    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    std::cout << "Total objects created: " << MyClass::getCount() << std::endl;

    return 0;
}
/*
OUTPUT -

Creating objects...
Object created. Total objects: 1
Object created. Total objects: 2
Object created. Total objects: 3
Total objects created: 3
Object destroyed. Total objects: 2
Object destroyed. Total objects: 1
Object destroyed. Total objects: 0
*/