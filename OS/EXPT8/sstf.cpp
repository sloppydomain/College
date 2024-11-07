#include <bits/stdc++.h>
using namespace std;

void calculateDifference(int request[], int head, int diff[][2], int n) {
    for(int i = 0; i < n; i++) {
        diff[i][0] = abs(head - request[i]);
    }
}

int findMIN(int diff[][2], int n) {
    int index = -1;
    int minimum = 1e9;
    for(int i = 0; i < n; i++) {
        if (!diff[i][1] && minimum > diff[i][0]) {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestSeekTimeFirst(int request[], int head, int n) {
    if (n == 0) {
        return;
    }  
    int diff[n][2] = { { 0, 0 } }; 
    int seekcount = 0;
    int seeksequence[n + 1] = {0};
    for(int i = 0; i < n; i++) {
        seeksequence[i] = head;
        calculateDifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;
        seekcount += diff[index][0];  
        head = request[index];
    }
	cout << "\nDisk Movement Sequence:\n";
    cout << "-------------------------------------\n";
    cout << "| From Position | To Position | Seek |\n";
    cout << "-------------------------------------\n";
    seeksequence[n] = head;
	long long tot = 0;
	for (int i = 1; i <= n; i++) {
		int seekDistance = abs(seeksequence[i] - seeksequence[i - 1]);
		tot += seekDistance;
		cout << "|      " << setw(3) << seeksequence[i - 1] 
             << "       |     " << setw(3) << seeksequence[i]
             << "      |  " << setw(3) << seekDistance << " |\n";
	}
	printf("-------------------------------------\n");
    cout << "Total number of seek operations = " << tot << '\n';
    cout << "Seek sequence is : ";
    for(int i = 0; i <= n; i++) {
        cout << seeksequence[i] << " \n"[i == n];
    }
}

int main() {
    int n, head;
    cout << "***** SSTF Disk Scheduling Algorithm *****\n";
    cout << "Enter the number of requests: ";
    cin >> n;
    int request[n];
    cout << "Enter the request sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> request[i];
    }
    cout << "Enter the initial head position: ";
    cin >> head;
    shortestSeekTimeFirst(request, head, n);
    return 0;
}

/*
OUTPUT:
***** SSTF Disk Scheduling Algorithm *****
Enter the number of requests: 8
Enter the request sequence: 176 79 34 60 92 11 41 114
Enter the initial head position: 50

Disk Movement Sequence:
-------------------------------------
| From Position | To Position | Seek |
-------------------------------------
|       50       |      41      |    9 |
|       41       |      34      |    7 |
|       34       |      11      |   23 |
|       11       |      60      |   49 |
|       60       |      79      |   19 |
|       79       |      92      |   13 |
|       92       |     114      |   22 |
|      114       |     176      |   62 |
-------------------------------------
Total number of seek operations = 204
Seek sequence is : 50 41 34 11 60 79 92 114 176
*/