//                                                  ASSIGNMENT - 2
//NAME - YASH MALVIYA
//ROLL NO - 22B-CO-075
#include <iostream>
#include <cstdlib>
using namespace std;
class DB;
class DM
{
    double metres;
    double centimetres;

public:
    DM() : metres(0), centimetres(0) {}
    void getData()
    {
        cout << "Enter distance in metres : ";
        cin >> metres;
        cout << "Enter distance in centimetres : ";
        cin >> centimetres;
    }
    void Display()
    {
        cout << "Distance is " << metres << "." << centimetres << " or " << metres * 100 << "centimetres" << endl;
    }
    friend void add(DM &, DB &);
};
class DB
{
    double feet;
    double inches;

public:
    DB() : feet(0), inches(0) {}
    void getData()
    {
        cout << "Enter distance in feet : ";
        cin >> feet;
        cout << "Enter distance in inches : ";
        cin >> inches;
    }
    void Display()
    {
        cout << "Distance is " << feet << "." << inches << " feet or " << feet * 12 << "inches" << endl;
    }
    friend void add(DM &, DB &);
};
void add(DM &m, DB &b)
{
    int choice;
    float totalmetres = m.metres + b.inches * 0.0254 + b.feet * 12 + m.centimetres / 100;
    float totalfeet = b.inches * 12 + m.metres * 3.281 + b.feet + m.centimetres * 0.394;
    while (1)
    {
        cout << "\n1. Display result in metres and centimetres\n";
        cout << "\n2. Display result in feet and inches\n";
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            m.metres = static_cast<int>(totalmetres);
            m.centimetres = ((totalmetres - static_cast<int>(totalmetres)) * 100);
            cout << "Total distance is " << m.metres << " metres and " << m.centimetres << " centimetres " << endl;
            break;
        case 2:
            b.feet = static_cast<int>(totalmetres * 3.28084);
            b.inches = ((totalfeet - static_cast<int>(totalfeet)) * 12);
            cout << "Total distance is " << b.feet << " feet and " << b.inches << " inches " << endl;
            break;
        case 3:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid choice..\n";
            break;
        }
    }
}
int main()
{
    DM a;
    DB b;
    a.getData();
    b.getData();
    add(a, b);
    return 0;
}
/*
OUTPUT - 
Enter distance in metres : 3
Enter distance in centimetres : 2
Enter distance in feet : 4.5
Enter distance in inches : 5.5

1. Display result in metres and centimetres

2. Display result in feet and inches
Enter choice : 1
Total distance is 57 metres and 15.9698 centimetres 

1. Display result in metres and centimetres

2. Display result in feet and inches
Enter choice : 2
Total distance is 187 feet and 1.57196 inches 

1. Display result in metres and centimetres

2. Display result in feet and inches
*/