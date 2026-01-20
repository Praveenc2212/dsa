/*
You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void bellmanFord(vector<vector<pair<int,ll>>>& adj) {
    int n = adj.size();
    vector<ll> dis(n, 0);
    vector<int> parent(n, -1);
    int x = -1;
    for(int i = 0; i < n; i++) {
        x = -1;
        for(int u = 0; u < n; u++) {
            for(auto [v, w] : adj[u]) {
                if(dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    parent[v] = u;
                    x = v;
                }
            }
        }
    }
    if(x == -1) {
        cout << "NO\n";
        return;
    }

    // Move x into the cycle
    for(int i = 0; i < n; i++) {
        x = parent[x];
    }

    vector<int> path;
    int cur = x;
    do {
        path.push_back(cur);
        cur = parent[cur];
    } while(cur != x);

    path.push_back(x);
    reverse(path.begin(), path.end());

    cout << "YES\n";
    for(int v : path)
        cout << v + 1 << " ";
    cout << "\n";
}

void solve() {
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int,ll>>> adj(n);
    for(int i = 0; i < e; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }
    bellmanFord(adj);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
