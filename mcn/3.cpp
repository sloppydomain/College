/*
    Checksum
*/
#include <bits/stdc++.h>
using namespace std;

string addBinary(const string &a, const string &b) {
    int n = a.size();
    int carry = 0;
    string result(n, '0');
    for (int i = n - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    while (carry) {
        for (int i = n - 1; i >= 0 && carry; i--) {
            int sum = (result[i] - '0') + carry;
            result[i] = (sum % 2) + '0';
            carry = sum / 2;
        }
    }
    return result;
}

string onesComplement(const string &s) {
    string comp = s;
    for (char &ch : comp) {
        ch = (ch == '0') ? '1' : '0';
    }
    return comp;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string data1, data2;
    cout << "Enter first binary string: ";
    cin >> data1;
    cout << "Enter second binary string: ";
    cin >> data2;
    if (data1.size() != data2.size()) {
        cout << "Error: The binary strings must be of equal length." << endl;
        return 1;
    }
    string sumData = addBinary(data1, data2);
    string checksum = onesComplement(sumData);
    cout << "\nData 1      : " << data1 << endl;
    cout << "Data 2      : " << data2 << endl;
    cout << "Sum         : " << sumData << endl;
    cout << "Checksum    : " << checksum << endl;
    string receiverSum = addBinary(sumData, checksum);
    cout << "\nReceiver Side Check (should be all 1's): " << receiverSum << endl;
    return 0;
}

/*
OUTPUT:
Enter first binary string: 1010
Enter second binary string: 0101

Data 1      : 1010
Data 2      : 0101
Sum         : 1111
Checksum    : 0000

Receiver Side Check (should be all 1's): 1111
*/