#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<int> vis(n + 1, false);
    int start;
    cin >> start;
    int w = h[start];
    vis[start] = true;
    int end;
    cin >> end; 
    int u = start;
    vector<int> p(n + 1, -1);
    while (1) {
        int par = u;
        bool ok = false;
        for (auto v : g[u]) {
            if (!vis[v] && h[v] < w) {
                w = h[v];
                u = v;
                ok = true;
            }
        }
        if (!ok) {
            cout << "No solution found...";
            cout << "\nTraversal: ";
            vector<int> path;
            for (int curr = u; curr != -1; curr = p[curr]) {
                path.push_back(curr);
            } 
            reverse(path.begin(), path.end());
            for (auto a : path) cout << a << ' ';
            break;
        }
        vis[u] = true;
        p[u] = par;
        if (u == end) {
            cout << "Path found: ";
            vector<int> path;
            for (int curr = end; curr != -1; curr = p[curr]) {
                path.push_back(curr);
            } 
            reverse(path.begin(), path.end());
            for (auto a : path) cout << a << ' ';
            break;
        }
    }
    return 0;
}