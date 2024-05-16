#include <iostream>
using namespace std;
int main()
{
    int n, votes, i, spoilt_ballot = 0;
    cout << "Enter the number of votes : ";
    cin >> n;
    int *a = new int[5];
    for (i = 0; i < n; i++)
        a[i] = 0;
    cout << "Enter numbers from 1 to 5 to vote candidates 1 or 2 or 3 or 4 or 5.\n";
    cout << "Enter a negative number to terminate and check result directly.\n";
    for (i = 0; i < n; i++)
    {
        cout << "Enter the number on ballot paper " << i + 1 << " : ";
        cin >> votes;
        if (votes >= 1 && votes <= 5)
            a[votes - 1]++;
        else if (votes >= 5)
        {
            cout << "Candidate with that number does not exist....\n";
            spoilt_ballot++;
        }
        else
            break;
    }
    for (i = 0; i < 5; i++)
    {
        cout << "Number of votes candidate " << i + 1 << " got are " << a[i] << "\n";
    }
    cout << "\nNumber of spoilt ballots are " << spoilt_ballot;
    delete[] a;
    return 0;
}