#include <iostream>
#include <string.h>
#include <math.h>
#define PI 4.0 * atan(1.0)
using namespace std;
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * fact(n - 1));
}
int main()
{
    float t, x, n, r, sum;
    cout << "Enter number of terms : ";
    cin >> n;
    cout << "Enter angle in degrees : ";
    cin >> x;
    r = PI * x / 180;
    t = r;
    sum = t;

    for (int i = 1; i < n; i++)
    {
        t *= r * r * (-1) / fact(2 * i + 1);
        sum += t;
    }
    cout << "Sum of " << n << " terms of sine series is " << sum;
    ;

    return 0;
}