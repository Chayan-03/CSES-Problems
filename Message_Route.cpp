#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    q.push(1);
    dist[1] = 0;
    parent[1] = -1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto neighbor : adj[node]) {
            if(dist[neighbor] == INT_MAX) {
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if(dist[n] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for(int cur = n; cur != -1; cur = parent[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for(auto v : path)
            cout << v << " ";
        cout << endl;
    }

    return 0;
}
