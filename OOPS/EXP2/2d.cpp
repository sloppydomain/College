#include <iostream>
using namespace std;
class ClassB;
class ClassA
{
private:
    int a1, b1;

public:
    ClassA(int a1, int b1)
    {
        this->a1 = a1;
        this->b1 = b1;
    }

    void Display()
    {
        cout << "The contents of ClassA are : " << endl;
        cout << "a1 = " << a1 << endl
             << "b1 = " << b1 << endl;
    }
    friend void Swap(ClassA &, ClassB &);
};
class ClassB
{
private:
    int a2, b2;

public:
    ClassB(int a2, int b2)
    {
        this->a2 = a2;
        this->b2 = b2;
    }

    void Display()
    {
        cout << "The contents of ClassB are : " << endl;
        cout << "a2 = " << a2 << endl
             << "b2 = " << b2 << endl;
    }
    friend void Swap(ClassA &, ClassB &);
};
void Swap(ClassA &obj1, ClassB &obj2)
{
    int tempA1 = obj1.a1;
    int tempB1 = obj1.b1;

    obj1.a1 = obj2.a2;
    obj1.b1 = obj2.b2;

    obj2.a2 = tempA1;
    obj2.b2 = tempB1;
}
int main()
{
    ClassA obj1(12, 13);
    ClassB obj2(23, 24);
    cout << "Contents before swapping are : " << endl;
    obj1.Display();
    obj2.Display();
    Swap(obj1, obj2);
    cout << "Contents after swapping are : " << endl;
    obj1.Display();
    obj2.Display();
    return 0;
}
// #include <iostream>
// using namespace std;

// class ClassB;  // Forward declaration for ClassB

// class ClassA {
// private:
//     int a1, b1;

// public:
//     ClassA(int a1, int b1) : a1(a1), b1(b1) {}

//     void Display() {
//         cout << "The contents of ClassA are : ";
//         cout << "a1 = " << a1 << endl << "b1 = " << b1 << endl;
//     }

//     friend void Swap(ClassA &obj1, ClassB &obj2);
// };

// class ClassB {
// private:
//     int a2, b2;

// public:
//     ClassB(int a2, int b2) : a2(a2), b2(b2) {}

//     void Display() {
//         cout << "The contents of ClassB are : ";
//         cout << "a2 = " << a2 << endl << "b2 = " << b2 << endl;
//     }

//     friend void Swap(ClassA &obj1, ClassB &obj2);
// };

// void Swap(ClassA &obj1, ClassB &obj2) {
//     int tempA1 = obj1.a1;
//     int tempB1 = obj1.b1;

//     obj1.a1 = obj2.a2;
//     obj1.b1 = obj2.b2;

//     obj2.a2 = tempA1;
//     obj2.b2 = tempB1;
// }

// int main() {
//     ClassA obj1(12, 13);
//     ClassB obj2(23, 24);

//     cout << "Contents before swapping are : " << endl;
//     obj1.Display();
//     obj2.Display();

//     // Swap contents using the friend function
//     Swap(obj1, obj2);

//     cout << "Contents after swapping are : " << endl;
//     obj1.Display();
//     obj2.Display();

//     return 0;
// }
