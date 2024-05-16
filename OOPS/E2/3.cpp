#include <iostream>
using namespace std;
int main()
{
    int i, j;
    int n;
    cout<<"Enter the height of triangle : ";
    cin >> n;
    cout<<"The triangle is : ";
    for (i = 0; i < n; i++)
    {
        int a = 0, b = 1, c;
        for (j = 0; j < i; j++)
        {
            cout << b << " ";
            c = a + b;
            a = b;
            b = c;
        }
        cout << endl;
    }
    return 0;
}