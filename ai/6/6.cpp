#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> edges(n);
        
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
    
        int start, end;
        cin >> start >> end;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({h[start], start});
        
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        visited[start] = true;
        
        vector<int> traversal;
        bool found = false;
        
        while (!pq.empty()) {
            auto [curr_h, curr] = pq.top();
            pq.pop();
            traversal.push_back(curr);
            
            if (curr == end) {
                found = true;
                break;
            }
            
            for (int neighbor : edges[curr]) {
                if (!visited[neighbor]) {
                    pq.push({h[neighbor], neighbor});
                    visited[neighbor] = true;
                    parent[neighbor] = curr;
                }
            }
        }
        
        cout << "Traversal: ";
        for (int node : traversal) {
            cout << node << " ";
        }
        cout << endl;

        if (!found) {
            cout << "Path: No path found" << endl;
        } else {
            vector<int> path;
            int cur = end, cost = 0;
            while (cur != -1) {
                cost += h[cur];
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());
            
            cout << "Path: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
            cout << "Total cost: " << cost << endl;
        }
    }
    
    return 0;
}
