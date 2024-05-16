#include <iostream>
using namespace std;
long long solve(int x, int n)
{
    long long term = 1;
    for (int i = 0; i < n; i++)
    {
        term = term * x;
    }
    return term;
}
int main()
{
    int x, n;
    cout << "Enter the base : ";
    cin >> x;
    cout << "Ente the exponent : ";
    cin >> n;
    cout << "The value is " << solve(x, n) << endl;

    return 0;
}