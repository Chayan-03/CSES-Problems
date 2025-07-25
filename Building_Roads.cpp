#include <bits/stdc++.h>
using namespace std;
vector<int> heads;

void bfs(long long i, vector<vector<long long>> &adj, vector<bool> &visited) {
  visited[i] = true;
  queue<long long> q;
  q.push(i);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto it : adj[node]) {
      if (!visited[it]) {
        visited[it] = true;
        q.push(it);
      }
    }
  }
}

int main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> adj(n + 1);
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> visited(n + 1, false);
  for (long long i = 1; i <= n; i++) {
    if (!visited[i]) {
      heads.push_back(i);
      bfs(i, adj, visited);
    }
  }
  cout<< heads.size()-1 << endl;
  for(long long m = 0;m<heads.size()-1;m++){
    cout<<heads[m]<<" "<<heads[m+1]<<endl;
  }
}