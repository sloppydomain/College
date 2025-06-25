#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string goal = "123456780";  
    string start = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            start.push_back(x + '0');
        }
    }
    if (start == goal) {
        cout << "0\n";
        return 0;
    }
    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};
    vector<char> dir = {'U', 'D', 'L', 'R'};
    map<string, string> par;     
    par[start] = "-1";
    unordered_set<string> vis;       
    auto h = [&](string s) {
        int d = 0;
        for (int i = 0; i < n * m; i++) {
            if (s[i] != '0') {
                if ((s[i] - '0') != i + 1) {
                    d += 1;
                }
            }
        }
        return d;
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({h(start), start});  
    vis.insert(start);
    bool ok = false;
    while (!pq.empty()) {
        auto [f, curr] = pq.top();
        pq.pop();
        if (curr == goal) {
            cout << "Solution: ";
            ok = true;
            vector<string> path;
            for (string p = curr; p != "-1"; p = par[p]) {
                path.push_back(p);
            }
            reverse(path.begin(), path.end());
            string moves = "";
            for (int idx = 0; idx < path.size() - 1; idx++) {
                int p1 = path[idx].find('0');
                int p2 = path[idx + 1].find('0');
                int i1 = p1 / m;
                int j1 = p1 % m;
                int i2 = p2 / m;
                int j2 = p2 % m;
                if (i2 == i1 - 1) moves += 'U';
                else if (i2 == i1 + 1) moves += 'D';
                else if (j2 == j1 - 1) moves += 'L';
                else if (j2 == j1 + 1) moves += 'R';
            }
            cout << moves << "\n";
            break;
        }
        int pos = curr.find('0');
        int i = pos / m;
        int j = pos % m;
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                string neig = curr;
                int idx1 = i * m + j;
                int idx2 = ni * m + nj;
                swap(neig[idx1], neig[idx2]);
                if (!vis.count(neig)) {
                    par[neig] = curr;
                    int heuristic = h(neig);
                    pq.push({heuristic, neig});
                    vis.insert(neig);
                }
            }
        }
    }
    if (!ok) {
        cout << "No solution\n";
    }
    return 0;
}

/*
OUTPUT:
1 2 3 4 0 6 7 5 8
Solution: DR
*/