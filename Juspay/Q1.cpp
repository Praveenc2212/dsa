#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 200005;
const int LOG = 20;

vector<pair<int,int>> adj[MAXN];
int parent[MAXN][20];
int depth[MAXN];
int tin[MAXN], tout[MAXN];
int timer = 0;
int n;

// Fenwick Tree
int fenwick[MAXN];

void fenwickAdd(int i, int v) {
    for ( ; i <= n ;  i += (i&-i))
        fenwick[i] += v ;
}
int fenwickSum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i ) 
        s += fenwick[i];
    return s;
}

void rangeAdd(int l, int r, int val) {
    fenwickAdd(l, val);
    fenwickAdd(r + 1, -val);
}

// get value at position
int pointQuery(int i) {
    return fenwickSum(i);
}

void dfs(int u, int p, int d) {
    parent[u][0] = p;
    depth[u] = d;
    tin[u] = ++timer;

    for (int k = 1; k < LOG; k++) {
        parent[u][k] = parent[parent[u][k-1]][k-1];
    }

    for (auto [v, w] : adj[u]) {
        if (v == p) continue;

       
        rangeAdd(timer + 1, timer + 1, w);

        dfs(v, u, d + 1);
    }

    tout[u] = timer;
}

int lca(int u, int v) {

    if (depth[u] < depth[v]) 
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int k = 0; k < 20; k++)
        if (diff & (1 << k))
            u = parent[u][k];

    if (u == v) return u;

    for (int k = 19 ; k >= 0; k--) {
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    return parent[u][0];
}

int distRoot(int u) {
    return pointQuery(tin[u]);
}

int dist(int u, int v) {
    int L = lca(u, v);
    return distRoot(u) + distRoot(v) - 2 * distRoot(L);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    dfs(1, 1, 0);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type ;

        if (type == 1) {
            int x, y;
            cin >> x >> y;
            cout << dist(x, y) << "\n";
        }
        else {
            // update edge i to new weight
            int idx, newW;
            cin >> idx >> newW;
            idx--;

            auto &[u, v, oldW] = edges[idx];

            int child = (parent[u][0] == v) ? u : v;
            int diff = newW - oldW;

            rangeAdd(tin[child], tout[child], diff);

            oldW = newW;
        }
    }
}
