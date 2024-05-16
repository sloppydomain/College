// #include <iostream>
// #include <cmath>
// using namespace std;

// class Polar; // Forward declaration

// class Rectangle
// {
//     double x, y;

// public:
//     Rectangle() : x(0), y(0) {}
//     Rectangle(double x, double y) : x(x), y(y) {}

//     void Display()
//     {
//         cout << "Coordinates in Rectangle coordinate System: ";
//         cout << "(" << x << ", " << y << ")" << endl;
//     }
//     friend Polar;
//     Polar ConvertToPolar();
// };

// class Polar
// {
//     double r, a;

// public:
//     Polar() : r(0), a(0) {}
//     Polar(double r, double a) : r(r), a(a) {}

//     void Display()
//     {
//         cout << "Coordinates in Polar coordinate System: ";
//         cout << "(" << r << ", " << a << ")" << endl;
//     }
//     friend Rectangle;
//     Rectangle ConvertToRectangle();
// };

// Polar Rectangle::ConvertToPolar()
// {
//     Polar p;
//     p.r = sqrt(x * x + y * y);
//     p.a = atan2(y, x);
//     return p;
// }

// Rectangle Polar::ConvertToRectangle()
// {
//     Rectangle r;
//     r.x = this->r * cos(a);
//     r.y = this->r * sin(a);
//     return r;
// }

// int main()
// {
//     int choice;
//     while (1)
//     {
//         double r, a, x, y;
//         cout << "\n1. Convert Rectangle to Polar\n";
//         cout << "2. Convert Polar to Rectangle\n";
//         cout << "3. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//         {
//             cout << "Enter x coordinate: ";
//             cin >> x;
//             cout << "Enter y coordinate: ";
//             cin >> y;
//             Rectangle r1(x, y);
//             Polar p1 = r1.ConvertToPolar();
//             p1.Display();
//             break;
//         }
//         case 2:
//         {
//             cout << "Enter r coordinate: ";
//             cin >> r;
//             cout << "Enter a in Radians: ";
//             cin >> a;
//             Polar p2(r, a);
//             Rectangle r2 = p2.ConvertToRectangle();
//             r2.Display();
//             break;
//         }
//         case 3:
//             cout << "Exiting....\n";
//             exit(0);
//         default:
//             cout << "Invalid choice. Try again." << endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;

const double PI = M_PI;

class Polar;

class Rectangle
{
    double x, y;

public:
    Rectangle() : x(0), y(0) {}
    Rectangle(double x, double y) : x(x), y(y) {}

    void Display()
    {
        cout << "Coordinates in Rectangle coordinate System: ";
        cout << "(" << x << ", " << y << ")" << endl;
    }

    friend Polar;
    Polar ConvertToPolar();
};

class Polar
{
    double r, a;

public:
    Polar() : r(0), a(0) {}
    Polar(double r, double a) : r(r), a(a) {}

    void Display()
    {
        cout << "Coordinates in Polar coordinate System: ";
        cout << "(" << r << ", " << a << ")" << endl;
    }
    double ConvertToRad(double x)
    {
        return ((x * PI) / 180.0);
    }
    friend Rectangle;
    Rectangle ConvertToRectangle();
};
Polar Rectangle::ConvertToPolar()
{
    Polar p;
    p.r = sqrt(x * x + y * y);
    p.a = atan2(y, x);
    return p;
}

Rectangle Polar::ConvertToRectangle()
{
    Rectangle r;
    r.x = this->r * cos(ConvertToRad(a));
    r.y = this->r * sin(ConvertToRad(a));
    return r;
}

int main()
{
    while (true)
    {
        int choice;
        cout << "\n1. Convert Rectangle to Polar\n";
        cout << "2. Convert Polar to Rectangle\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            double x, y;
            cout << "Enter x coordinate: ";
            cin >> x;
            cout << "Enter y coordinate: ";
            cin >> y;
            Rectangle r1(x, y);
            Polar p1 = r1.ConvertToPolar();
            p1.Display();
            break;
        }
        case 2:
        {
            double r, a;
            cout << "Enter r coordinate: ";
            cin >> r;
            cout << "Enter a in Degrees: ";
            cin >> a;
            Polar p2(r, a);
            Rectangle r2 = p2.ConvertToRectangle();
            r2.Display();
            break;
        }
        case 3:
            cout << "Exiting....\n";
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
