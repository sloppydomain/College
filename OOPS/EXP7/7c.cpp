//Q7c

#include <iostream>
#include <iomanip>
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
        dout << "Value of x : " << setw(5) << t.x << "\n"
             << "Value of y : " << setw(5) << t.y << endl;
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
    temp a;
    a = temp(20, 30);
    cout << setiosflags(ios::left);
    cout << setw(30) << "Initial values:" << endl;
    cout << a << endl;

    cin >> a;
    cout << "\n";
    cout << setw(30) << "Updated values:" << endl;
    cout << a;

    return 0;
}
/*
OUTPUT - 
Initial values:
Value of x : 20   
Value of y : 30   

Enter value of x : 88
Enter value of y : 99

Updated values:
Value of x : 88   
Value of y : 99  


CONCLUSION - C++ CONSOLE I/O FUNXTIONS WERE SUCCESSFULLY STUDIED AND IMPLEMENTED.
*/