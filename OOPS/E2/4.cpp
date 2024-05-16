#include <iostream>
using namespace std;
int main()
{
    int t = 1, n;
    cout<<"Enter the number : ";
    cin >> n;
    int num = n / 10;
    while (num != 0)
    {
        t = t * 10;
        num /= 10;
    }
    cout << "The first digit is " << (n / t) << endl;
    int last_digit = n % 10;
    cout << "The last digit is " << last_digit << endl;
    return 0;
}
