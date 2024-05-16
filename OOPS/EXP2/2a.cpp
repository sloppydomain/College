#include <iostream>
using namespace std;
long int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * fact(n - 1));
}
void k_num(int &num)
{
    int t = num;
    int sum = 0;
    while (t > 0)
    {
        int r = t % 10;
        sum = sum + fact(r);
        t = t / 10;
    }
    if (sum == num)
    {
        cout << "Number is a krishnamurty number...";
    }
    else
        cout << "Number is not a krishnamurty number...";
}
int main()
{
    int n;
    long long int sum = 0;
    cout << "Enter the number : ";
    cin >> n;
    k_num(n);
    return 0;
}