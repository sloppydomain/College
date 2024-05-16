// Q7a
//  #include <iostream>
//  #include <math.h>
//  using namespace std;
//  int main()
//  {
//      cout.fill('*');
//      cout.setf(ios ::left, ios ::adjustfield);
//      cout.width(10);
//      cout << "VALUE";
//      cout.width(18);
//      cout.setf(ios::right, ios::adjustfield);
//      cout << "MULT OF VALUE";
//      cout.fill('.');
//      cout.setf(ios::showpos);
//      cout << endl;
//      for (int i = 1; i <= 4; i++)
//      {
//          cout.setf(ios::internal, ios::adjustfield);
//          cout.width(5);
//          cout << i;
//          cout.unsetf(ios::internal);
//          cout.width(23);
//          cout.setf(ios::right, ios::adjustfield);
//          cout.precision(3);
//          cout.setf(ios::showpoint);
//          cout.setf(ios::fixed, ios::floatfield);
//          cout << (float)2 * i << endl;
//      }
//      return 0;
//  }
/*
OUTPUT -
VALUE**********MULT OF VALUE
+...1.................+2.000
+...2.................+4.000
+...3.................+6.000
+...4.................+8.000
*/
#include <iostream>
#include <iomanip>
using namespace std;
ostream &first(ostream &dout)
{
    dout.fill('*');
    dout.setf(ios::left, ios::adjustfield);
    dout.width(10);
    dout << "VALUE";
    dout.width(18);
    dout.setf(ios::right, ios::adjustfield);
    dout << "MULT OF VALUE";
    dout.fill('.');
    dout.setf(ios::showpos);
    dout << endl;
    return dout;
}
ostream &second(ostream &dout, int value, double mult)
{
    dout.setf(ios::internal, ios::adjustfield);
    dout.width(5);
    dout << value;
    dout.unsetf(ios::internal);
    dout.width(23);
    dout.setf(ios::right, ios::adjustfield);
    dout.precision(3);
    dout.setf(ios::showpoint);
    dout.setf(ios::fixed, ios::floatfield);
    dout << mult;
    return dout;
}

int main()
{
    cout << first;
    for (int i = 1; i <= 4; i++)
    {
        // second(cout, i, (double)(2 * i));
        cout << second << i << (double)(2 * i) << endl;
    }
    return 0;
}
