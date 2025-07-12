/*
    CRC
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // sender
    string original;
    string data, divisor;
    cin >> data >> divisor;
    cout << "Sender data: " << data << '\n' << "Divisor: " << divisor << '\n';
    int m = divisor.length();
    for (int i = 0; i < m - 1; i++) {
        data.push_back('0');
    }
    int n = data.length();
    original = data;
    cout << "Sender data after appending " << m - 1 << " bits: " << data << '\n';
    int i = 0;
    while (i + m < n) {
        if (data[i] == '1') {
            for (int j = 0; j < m; j++) {
                data[i + j] = (data[i + j] == divisor[j]) ? '0' : '1';
            }
        }
        while (i < n && data[i] != '1') {
            i++;
        }
    }
    cout << "Remainder: " << data << '\n';
    for (int i = n - m; i < n; i++) {
        original[i] = data[i];
    }


    // reciever
    cout << "Reciever data: " << original << '\n';
    i = 0;
    while (i + m < n) {
        if (original[i] == '1') {
            for (int j = 0; j < m; j++) {
                original[i + j] = (original[i + j] == divisor[j]) ? '0' : '1';
            }
        }
        while (i < n && original[i] != '1') {
            i++;
        }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (original[i] == '1') {
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << "No error, remainder is: " << original;
    } else {
        cout << "Error in data\n";
    }
    return 0;
}

/*
OUTPUT:
11010011101100
1011
Sender data: 11010011101100
Divisor: 1011
Sender data after appending 3 bits: 11010011101100000
Remainder: 00000000000000100
Reciever data: 11010011101100100
No error, remainder is: 00000000000000000
*/