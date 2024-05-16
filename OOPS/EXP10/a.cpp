// Qa
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, n1, n2;

    cout << "Enter the number of elements of  file1: ";
    cin >> n1;
    cout << "Enter the number of elements of  file2: ";
    cin >> n2;

    ofstream f1, f2;
    f1.open("File1.txt");
    f2.open("File2.txt");

    if (!f1.is_open() || !f2.is_open())
    {
        cout << "File cannot be opened\n";
        return 1;
    }

    int i = 0;
    cout << "Enter the elements for File1: " << endl;
    while (i < n1)
    {
        cout << "Enter Element " << i + 1 << " : ";
        cin >> n;
        f1 << n << " ";
        i++;
    }

    i = 0;
    cout << "Enter the elements for File2: " << endl;
    while (i < n2)
    {
        cout << "Enter Element " << i + 1 << " : ";
        cin >> n;
        f2 << n << " ";
        i++;
    }

    f1.close();
    f2.close();

    int m1, m2, j, k;
    vector<int> v1(n1), v2(n2), v3(n1 + n2);
    ifstream p1, p2;
    ofstream p3;
    p1.open("File1.txt");
    p2.open("File2.txt");
    p3.open("File3.txt");
    for (i = 0; i < n1; i++)
        p1 >> v1[i];
    for (i = 0; i < n2; i++)
        p2 >> v2[i];

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            v3[k++] = v1[i++];
        }
        else
        {
            v3[k++] = v2[j++];
        }
    }
    while (i < n1)
    {
        v3[k++] = v1[i++];
    }
    while (j < n2)
    {
        v3[k++] = v2[j++];
    }
    for (int i = 0; i < n1 + n2; i++)
    {
        p3 << v3[i] << " ";
    }
    cout << "\nElements entered in File3 successfully\n";

    p1.close();
    p2.close();
    p3.close();

    cout << "\nContents of File3 in ascending order: ";
    ifstream q3("File3.txt");
    while (q3 >> n)
    {
        cout << n << " ";
    }
    q3.close();

    return 0;
}

/*
OUTPUT -
Enter the number of elements of  file1: 4
Enter the number of elements of  file2: 5
Enter the elements for File1:
Enter Element 1 : 89
Enter Element 2 : 75
Enter Element 3 : 345
Enter Element 4 : 44
Enter the elements for File2:
Enter Element 1 : 7
Enter Element 2 : 877
Enter Element 3 : 445
Enter Element 4 : 3
Enter Element 5 : 4

Elements entered in File3 successfully

Contents of File3 in ascending order: 3 4 7 44 75 89 345 445 877
*/