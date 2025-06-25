#include <bits/stdc++.h>
using namespace std;

/*
    a* algorithm
    f(n) = g(n) + h(n)
    f(n) -> total cost
    g(n) -> distance from start
    h(n) -> heuristic function
*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, e;
    cin >> n >> e;
    vector<vector<array<int, 2>>> adj(n + 1);
    for (int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    int start, end;
    cin >> start >> end;
    priority_queue<array<long long, 2>, vector<array<long long, 2>>, greater<array<long long, 2>>> pq;
    const long long M = 1e18;
    vector<long long> f(n + 1, M);
    vector<int> par(n + 1, -1);
    pq.push({h[start], start});
    f[start] = h[start];
    while (pq.size() > 0){
        auto fro = pq.top();
        pq.pop();
        int u = fro[1];
        if (f[u] < fro[0]) {
            continue;
        }
        for (auto to : adj[u]){
            int v = to[0], w = to[1];
            if (f[v] > w + h[v] + (f[u] - h[u])){
                par[v] = u;
                f[v] = w + h[v] + (f[u] - h[u]);
                pq.push({f[v], v});
            }
        }
    }
    vector<int> path;
    for (int i = end; i != -1; i = par[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << "\nCost: " << f[end] << '\n';
    return 0;
}