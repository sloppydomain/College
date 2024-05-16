#include <iostream>
using namespace std;
long reverse(int n)
{
    long long r, term = 0;
    while (n != 0)
    {
        r = n % 10;
        term = term * 10 + r;
        n /= 10;
    }
    return term;
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << "Reverse of number " << n << " is " << reverse(n) << endl;
    return 0;
}