#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Item
{
public:
    string name;
    string code;
    double cost;
};
int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<Item> v;
    for (int i = 0; i < n; i++)
    {
        Item t;
        cout << "Enter item name of item " << i + 1 << ": ";
        cin.ignore();
        getline(cin, t.name);
        cout << "Enter item code of item " << i + 1 << ": ";
        cin >> t.code;
        cout << "Enter item cost of item " << i + 1 << ": ";
        cin >> t.cost;
        v.push_back(t);
    }
    cout << setw(39) << setfill('-') << "" << endl;
    cout << setfill(' ') << left << setw(20) << "NAME" << setw(15) << "CODE" << setw(15) << "COST" << endl;
    cout << setw(39) << setfill('-') << "" << endl;
    cout << setfill(' ');
    for (const auto &t : v)
    {
        cout << left << setw(20) << t.name << setw(15) << t.code << setw(15) << t.cost << endl;
    }
    return 0;
}