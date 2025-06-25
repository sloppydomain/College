/*
    8 puzzle using Hill climbing
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    const string goal = "123456780";
    string start;
    start.reserve(9);
    for (int i = 0, x; i < n * m; i++) {
        cin >> x;
        start.push_back(char('0' + x));
    }
    if (start == goal) {
        cout << 0 << "\n";
        return 0;
    }
    auto is_solvable = [&](const string &s) {
        int inv = 0;
        for (int i = 0; i < n * m; i++) {
            if (s[i] == '0')
                continue;
            for (int j = i + 1; j < n * m; j++) {
                if (s[j] == '0')
                    continue;
                if (s[i] > s[j])
                    inv++;
            }
        }
        return (inv % 2) == 0;
    };
    auto heuristic = [&](const string &s) {
        int h = 0;
        for (int i = 0; i < n * m; i++) {
            if (s[i] != '0' && s[i] - '0' != i + 1)
                h++;
        }
        return h;
    };
    if (!is_solvable(start)) {
        cout << "No solution\n";
        return 0;
    }
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    unordered_set<string> vis;
    unordered_map<string, string> parent;
    vis.insert(start);
    parent[start] = "";
    string curr = start;
    bool solved = false;
    while (true) {
        if (curr == goal) {
            solved = true;
            break;
        }
        int zp = curr.find('0');
        int ci = zp / m, cj = zp % m;
        int currH = heuristic(curr);
        string best = curr;
        int bestH = currH;
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k], nj = cj + dj[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                continue;
            string next = curr;
            swap(next[ci * m + cj], next[ni * m + nj]);
            if (vis.count(next))
                continue; 
            int hnext = heuristic(next);
            if (hnext < bestH) {
                bestH = hnext;
                best = next;
            }
        }
        if (best == curr)
            break;
        vis.insert(best);
        parent[best] = curr;
        curr = best;
    }
    if (!solved) {
        cout << "No path...\n";
    } else {
        vector<string> path;
        for (string s = goal; !s.empty(); s = parent[s])
            path.push_back(s);
        reverse(path.begin(), path.end());
        string moves;
        for (int i = 0; i < (int)path.size() - 1; i++) {
            int p1 = path[i].find('0');
            int p2 = path[i + 1].find('0');
            int i1 = p1 / m, j1 = p1 % m;
            int i2 = p2 / m, j2 = p2 % m;
            if (i2 == i1 - 1)
                moves += 'U';
            else if (i2 == i1 + 1)
                moves += 'D';
            else if (j2 == j1 - 1)
                moves += 'L';
            else if (j2 == j1 + 1)
                moves += 'R';
        }
        cout << "Solution: ";
        cout << moves << "\n";
    }
    return 0;
}