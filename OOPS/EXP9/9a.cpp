//Q9a

#include <iostream>
using namespace std;
template <typename T>
void swap(const T &a, const T &b)
{
    T x = a;
    a = b;
    b = x;
}
int main()
{
    int x = 3;
    int y = 4;
    cout << "Values before swapping : " << endl;
    cout << "x = " << x << "\n"
         << "y = " << y << endl;
    swap(x, y);
    cout << "Values after swapping : " << endl;
    cout << "x = " << x << "\n"
         << "y = " << y << endl;
    return 0;
}
/*
OUTPUT - 
Values before swapping : 
x = 3
y = 4
Values after swapping : 
x = 4
y = 3
*/