/*
    Hamming Code
*/

#include <bits/stdc++.h>
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    cout << "Original data: " << s << '\n';

    // sender
    int r = 0;
    while ((1 << r) < n + r + 1) {
        r += 1;
    }
    vector<char> sender(n + r + 1);
    for (int i = 1, j = 0; i <= n + r; i++) {
        if (((i - 1) & i) == 0) {
            continue;
        } else {
            sender[i] = s[j++];
        }
    }
    // total bits = n + r
    for (int i = 1; i <= r; i++) {
        int v = 0;
        for (int j = (1 << (i - 1)) + 1; j <= n + r; j++) {
            if (j & (1 << (i - 1))) {
                v = v ^ (sender[j] - '0');
            }
        }
        sender[(1 << (i - 1))] = (v + '0');
    }
    cout << "Encoded data: ";
    for (int i = 1; i <= n + r; i++) {
        cout << sender[i];
    }

    // reciever
    int p;
    cout << "\nEnter the bit position to introduce error while transmitting: ";
    cin >> p;
    cout << "Recieved data maybe with an error: "; 
    sender[p] = (sender[p] == '0' ? '1' : '0');
    for (int i = 1; i <= n + r; i++) {
        cout << sender[i];
    }
    int bit = 0;
    for (int i = 1; i <= r; i++) {
        int v = 0;
        for (int j = (1 << (i - 1)); j <= n + r; j++) {
            if (j & (1 << (i - 1))) {
                v = v ^ (sender[j] - '0');
            }
        }
        if (v) {
            bit += (1 << (i - 1));
        }
    }
    cout << "\nError at bit " << bit << '\n';
    sender[bit] = (sender[bit] == '0' ? '1' : '0');
    cout << "Decoded data: ";
        for (int i = 1; i <= n + r; i++) {
        cout << sender[i];
    }

    return 0;
}

/*
OUTPUT: 
1011
Original data: 1011
Encoded data: 0110011
Enter the bit position to introduce error while transmitting: 4
Recieved data maybe with an error: 0111011
Error at bit 4
Decoded data: 0110011
*/