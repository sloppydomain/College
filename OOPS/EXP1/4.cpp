#include <iostream>
#define MIN 50.0
using namespace std;
class Customer
{
private:
    string Name;
    int units;
    double cost;

public:
    void get_Data()
    {
        cout << "Enter the Name of Customer : ";
        cin.ignore();
        getline(cin, Name);
        cout << "Enter the number of units consumed : ";
        cin >> units;
    }
    void Calculate_total()
    {
        if (units <= 100)
            cost = MIN + (60 * units) / 100;
        else if (units >= 100 && units <= 300)
            cost = MIN + (80 * units) / 100;
        else
            cost = MIN + (90 * units) / 100;

        if (cost > 300)
            cost += 0.15 * cost;
    }
    void Display()
    {
        cout << Name << "\t\t " << cost << "\n";
    }
};

int main()
{
    int n, i;
    cout << "Enter the number of customers : ";
    cin >> n;
    Customer *c = new Customer[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter the details of customer " << i + 1 << " ...\n";
        c[i].get_Data();
        c[i].Calculate_total();
        // c[i].Display();
        cout << "\n\n";
    }
    cout << "Name"
         << "\t\t"
         << "Total Cost\n";
    for (i = 0; i < n; i++)
        c[i].Display();

    delete[] c;
    return 0;
}