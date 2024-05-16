// Q4d

#include <iostream>
using namespace std;
class temp
{
    int x;
    int y;

public:
    temp(int a, int b) : x(a), y(b) {}
    temp() : x(0), y(0) {}
    friend ostream &operator<<(ostream &dout, const temp &t)
    {
        dout << "Value of x : " << t.x << "\n"
             << "Value of y : " << t.y << endl;
        return dout;
    }
    friend istream &operator>>(istream &din, temp &t)
    {
        cout << "Enter value of x : ";
        din >> t.x;
        cout << "Enter value of y : ";
        din >> t.y;
        return din;
    }
};
int main()
{
    temp a, b(50, 60);
    a = temp(20, 30);
    cout << a << b;
    cout << "\n";
    cout << "Enter contents of a : " << endl;
    cin >> a;
    cout << "Enter contents of b : " << endl;
    cin >> b;
    cout << "\n";
    cout << a << b;
    return 0;
}
/*
OUTPUT -
Value of x : 20
Value of y : 30

Enter value of x : 80
Enter value of y : 90

Value of x : 80
Value of y : 90
*/

// #include <iostream>
// using namespace std;

// class temp {
//     int x;
//     int y;

// public:
//     temp(int a, int b) : x(a), y(b) {}
//     temp() : x(0), y(0) {}

//     // Member function for operator<<
//     ostream &print(ostream &dout) const {
//         dout << "Value of x : " << x << "\n"
//              << "Value of y : " << y << endl;
//         return dout;
//     }

//     // Member function for operator>>
//     istream &read(istream &din) {
//         cout << "Enter value of x : ";
//         din >> x;
//         cout << "Enter value of y : ";
//         din >> y;
//         return din;
//     }

//     // Member function to overload << as a member
//     temp& operator<<(ostream &dout) {
//         print(dout);
//         return *this;
//     }

//     // Member function to overload >> as a member
//     temp& operator>>(istream &din) {
//         read(din);
//         return *this;
//     }
// };

// int main() {
//     temp a, b(50, 60);
//     a = temp(20, 30);

//     // Using member functions for operator<<
//     a << cout;
//     b << cout;
//     cout << "\n";

//     cout << "Enter contents of a : " << endl;
//     a >> cin;

//     cout << "Enter contents of b : " << endl;
//     b >> cin;

//     cout << "\n";

//     // Using member functions for operator<<
//     a << cout;
//     b << cout;

//     return 0;
// }
