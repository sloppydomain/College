// Q7b
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    setiosflags(ios::showpoint);
    cout << setw(5) << "n" << setw(15) << "Inverse of n" << setw(20) << "Sum of terms\n\n";
    double t, sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        t = 1.0 / float(i);
        sum += t;
        cout << setw(5) << i;                                                     // Value of number
        cout << setw(14) << setprecision(4) << setiosflags(ios::scientific) << t; // Print terms
        cout << setw(12) << resetiosflags(ios::scientific) << sum << endl;        // Print sum
    }
    return 0;
}
/*
OUTPUT -
 n   Inverse of n      Sum of terms

    1   1.0000e+000       1.000
    2   5.0000e-001       1.500
    3   3.3333e-001       1.833
    4   2.5000e-001       2.083
    5   2.0000e-001       2.283
    6   1.6667e-001       2.450
    7   1.4286e-001       2.593
    8   1.2500e-001       2.718
    9   1.1111e-001       2.829
   10   1.0000e-001       2.929
   */