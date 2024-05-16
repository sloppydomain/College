#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(39) << setfill('-') << "" << endl;
    cout << setfill(' ') << left << setw(20) << "NAME" << setw(15) << "CODE" << setw(15) << "COST" << endl;
    cout << setw(39) << setfill('-') << "" << endl;
    return 0;
}