#include <iostream>
#include <iomanip>
using namespace std;

int m, n; 
int allocation[10][10], maximum[10][10], need[10][10];
int available[10], total_resources[10];
bool safety() {
    int safe[10], work[10];
    bool finish[10] = { false };
    int count = 0;
    for (int i = 0; i < m; i++)
        work[i] = available[i];
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canFinish = true;
                for (int r = 0; r < m; r++) {
                    if (need[p][r] > work[r]) {
                        canFinish = false;
                        break;
                    }
                }
                if (canFinish) {
                    for (int r = 0; r < m; r++)
                        work[r] += allocation[p][r];
                    safe[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }
    if (count == n) {
        cout << endl << "Safe Sequence: ";
        for (int i = 0; i < n; i++)
            cout << "P" << safe[i] << " -> ";
        cout << "END" << endl;
        return true;
    } else {
        cout << endl << "No safe sequence exists." << endl;
        return false;
    }
}

void display() {
    cout << endl << "Process\t\tAllocation\tMaximum\t\tNeed\t\tAvailable" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << "\t\t";
        for (int j = 0; j < m; j++)
            cout << allocation[i][j] << " ";
        cout << "\t\t";
        for (int j = 0; j < m; j++)
            cout << maximum[i][j] << " ";
        cout << "\t\t";
        for (int j = 0; j < m; j++)
            cout << need[i][j] << " ";
        cout << "\t\t";
        if (i == 0) {
            for (int j = 0; j < m; j++)
                cout << available[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter the number of Processes: ";
    cin >> n;
    cout << "Enter the number of Resource types: ";
    cin >> m;
    cout << "Enter the Total Resources for each type:" << endl;
    for (int i = 0; i < m; i++)
        cin >> total_resources[i];
    cout << "Enter Allocated Resources for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];
    }
    cout << endl << "Enter Maximum Resources for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> maximum[i][j];
    }
    int allocated[10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            allocated[j] += allocation[i][j];
    }
    for (int i = 0; i < m; i++)
        available[i] = total_resources[i] - allocated[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }
    display();
    bool isSafe = safety();
    char ans = 'y';
    do {
        int request[10], p;
        cout << endl << "Enter Process Number: ";
        cin >> p;
        cout << "Enter Request: ";
        for (int i = 0; i < m; i++)
            cin >> request[i];
        bool canGrant = true;
        for (int i = 0; i < m; i++) {
            if (request[i] > need[p][i]) {
                cout << endl << "Process has exceeded its maximum claim." << endl;
                canGrant = false;
                break;
            }
            if (request[i] > available[i]) {
                cout << endl << "Resources not available, process must wait." << endl;
                canGrant = false;
                break;
            }
        }
        if (canGrant) {
            cout<<"\n";
        cout<<"DOING THE RESOURCE REQUEST ALGO"<<endl;
        cout<<"TEMP ALLOCATION SEEN";
            for (int i = 0; i < m; i++) {
                available[i] -= request[i];
                allocation[p][i] += request[i];
                need[p][i] -= request[i];
            }
            display();
            bool allZero = true;
            for (int i = 0; i < m; i++) {
                if (available[i] > 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero) {
                cout << endl << "Request cannot be granted as it leads to all resource types being zero." << endl;
                for (int i = 0; i < m; i++) {
                    available[i] += request[i];
                    allocation[p][i] -= request[i];
                    need[p][i] += request[i];
                }
                cout << endl << "State restored:" << endl;
                display();
            } else {
                cout<<"\n";
                cout<<"EXECUTING SAFETY ALGO"<<endl;
                cout << endl << "Checking system safety after tentative allocation..." << endl;
                isSafe = safety();
                if (!isSafe) {
                    cout << "Request cannot be granted as it leads to an unsafe state." << endl;
                    for (int i = 0; i < m; i++) {
                        available[i] += request[i];
                        allocation[p][i] -= request[i];
                        need[p][i] += request[i];
                    }
                    cout << endl << "State restored:" << endl;
                    display();
                } else {
                    cout << "Safe sequence exists. Request can be granted." << endl;
                    cout<<"NEW PERMANENT ALLOCATION"<<endl;
                    display();
                }
            }
        }
        cout << endl << "Try another process? (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}

/*
OUTPUT:
Enter the number of Resource types: 3
Enter the Total Resources for each type:
10 5 7
Enter Allocated Resources for each process:
P0: 0 1 0
P1: 2 0 0 
P2: 3 0 2
P3: 2 1 1
P4: 0 0 2

Enter Maximum Resources for each process:
P0: 7 5 3
P1: 3 2 2
P2: 9 0 2
P3: 2 2 2
P4: 4 3 3

Process         Allocation      Maximum         Need            Available
P0              0 1 0           7 5 3           7 4 3           3 3 2 
P1              2 0 0           3 2 2           1 2 2 
P2              3 0 2           9 0 2           6 0 0 
P3              2 1 1           2 2 2           0 1 1 
P4              0 0 2           4 3 3           4 3 1 

Safe Sequence: P1 -> P3 -> P4 -> P0 -> P2 -> END

Enter Process Number: 1
Enter Request: 0 2 0

DOING THE RESOURCE REQUEST ALGO
TEMP ALLOCATION SEEN
Process         Allocation      Maximum         Need            Available
P0              0 1 0           7 5 3           7 4 3           3 1 2 
P1              2 2 0           3 2 2           1 0 2 
P2              3 0 2           9 0 2           6 0 0 
P3              2 1 1           2 2 2           0 1 1 
P4              0 0 2           4 3 3           4 3 1 

EXECUTING SAFETY ALGO

Checking system safety after tentative allocation...

Safe Sequence: P1 -> P3 -> P4 -> P0 -> P2 -> END
Safe sequence exists. Request can be granted.
NEW PERMANENT ALLOCATION

Process         Allocation      Maximum         Need            Available
P0              0 1 0           7 5 3           7 4 3           3 1 2 
P1              2 2 0           3 2 2           1 0 2 
P2              3 0 2           9 0 2           6 0 0 
P3              2 1 1           2 2 2           0 1 1 
P4              0 0 2           4 3 3           4 3 1 

Try another process? (Y/N): n

Conclusion: Banker's Algorithm was successfully studied and implemented
*/