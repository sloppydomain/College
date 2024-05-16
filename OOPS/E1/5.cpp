#include <iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cout << "Enter the number : ";
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            count++;
    }
    if (count >= 1)
    {
        cout << "Number " << n << " is not a prime number";
    }
    else
    cout << "Number " << n << " is a prime number";
    return 0;
}