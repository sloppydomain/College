#include <bits/stdc++.h>
using namespace std;

vector<long long> dist;
vector<long long> parent;
vector<vector<pair<int, int>>> edges;
void dijkstra(int start, int n) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    parent.assign(n + 1, -1);
    dist.assign(n + 1, LLONG_MAX);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        pair<long long, long long> p = pq.top();
        pq.pop();
        long long w = p.first;
        long long from = p.second;
        if (w > dist[from]) {
            continue;
        }
        for (auto edge : edges[from]) {
            long long to = edge.first;
            long long w_ = edge.second;
            if (dist[from] + w_ < dist[to]) {
                dist[to] = dist[from] + w_;
                parent[to] = from;
                pq.push({dist[to], to});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, e;
    cin >> n >> e;
    edges.resize(n + 1);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start, n);
    cout << "\nRouter table for " << start << '\n';
    cout << "Router\t\tPath\t\t\t\tDistance\n";
    for (int i = 1; i <= n; i++) {
        if (i == start) continue;
        cout << i << "\t\t";
        vector<int> path;
        for (int j = i; j != -1; j = parent[j]) {
            path.push_back(j);
        }
        reverse(path.begin(), path.end());
        for (auto x : path) {
            cout << x;
            if (x != i) {
                cout << " -> ";
            }
        }
        for (int i = 0; i < 6 - path.size(); i++) {
            cout << "\t";
        }
        cout << dist[i] << '\n';
    }
    dijkstra(end, n);
    cout << "\nRouter table for " << end << '\n';
    cout << "Router\t\tPath\t\t\t\tDistance\n";
    for (int i = 1; i <= n; i++) {
        if (i == end) continue;
        cout << i << "\t\t";
        vector<int> path;
        for (int j = i; j != -1; j = parent[j]) {
            path.push_back(j);
        }
        reverse(path.begin(), path.end());
        for (auto x : path) {
            cout << x;
            if (x != i) {
                cout << " -> ";
            }
        }
        for (int i = 0; i < 6 - path.size(); i++) {
            cout << "\t";
        }
        cout << dist[i] << '\n';
    }
    return 0;
}

/*
OUTPUT:
6 9
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 4 11
3 6 2
5 4 6
5 6 9
1 5

Router table for 1
Router          Path                            Distance
2               1 -> 2                          7
3               1 -> 3                          9
4               1 -> 3 -> 4                     20
5               1 -> 3 -> 6 -> 5                20
6               1 -> 3 -> 6                     11

Router table for 5
Router          Path                            Distance
1               5 -> 6 -> 3 -> 1                20
2               5 -> 4 -> 2                     21
3               5 -> 6 -> 3                     11
4               5 -> 4                          6
6               5 -> 6                          9

Conclusion - Dijkstra's routing algorithm was successfully studied and implemented.
*/