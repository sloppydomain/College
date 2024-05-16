#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    int t, rev = 0, num = n;
    while (num != 0)
    {
        t = num % 10;
        rev = rev * 10 + t;
        num /= 10;
    }
    if (n == rev)
        cout << "Number is a palindrome";
    else
        cout << "Number is not a palindrome";
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    solve(n);
    return 0;
}