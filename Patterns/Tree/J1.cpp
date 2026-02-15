#include <bits/stdc++.h>
using namespace std;

#define int long long

#define vi vector<int>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

const int mxN = 204040;

vpi g[mxN];
pi edges[mxN];

int depth[mxN], val[mxN], in[mxN], out[mxN];
vi jump[21];

int n, q;
int t = 1;

// ================= SEGMENT TREE =================

int seg[8 * mxN];
int lazy[8 * mxN];

void push(int idx, int l, int r) {
    if (lazy[idx] == 0) return;

    seg[idx] += lazy[idx];

    if (l != r) {
        lazy[idx * 2] += lazy[idx];
        lazy[idx * 2 + 1] += lazy[idx];
    }

    lazy[idx] = 0;
}

void update(int idx, int l, int r, int ql, int qr, int val) {
    push(idx, l, r);
    if (qr < l || r < ql) return;

    if (ql <= l && r <= qr) {
        lazy[idx] += val;
        push(idx, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(idx * 2, l, mid, ql, qr, val);
    update(idx * 2 + 1, mid + 1, r, ql, qr, val);
}

int query(int idx, int l, int r, int pos) {
    push(idx, l, r);

    if (l == r) return seg[idx];

    int mid = (l + r) / 2;
    if (pos <= mid) return query(idx * 2, l, mid, pos);
    return query(idx * 2 + 1, mid + 1, r, pos);
}

// ================= DFS =================

void dfs(int u, int par, int d) {
    depth[u] = d;
    jump[0][u] = par;

    in[u] = t++;

    for (int i = 1; i < 21; i++)
        jump[i][u] = jump[i - 1][ jump[i - 1][u] ];

    for (auto &p : g[u]) {
        int v = p.F, w = p.S;
        if (v == par) continue;

        val[v] = w;
        dfs(v, u, d + 1);
    }

    out[u] = t - 1;
}

// ================= LCA =================

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    int diff = depth[v] - depth[u];
    for (int i = 0; i < 21; i++)
        if (diff & (1LL << i))
            v = jump[i][v];

    if (u == v) return u;

    for (int i = 20; i >= 0; i--) {
        if (jump[i][u] != jump[i][v]) {
            u = jump[i][u];
            v = jump[i][v];
        }
    }

    return jump[0][u];
}

// ================= SOLVE =================

void solve() {
    cin >> n;

    for (int i = 0; i < 21; i++)
        jump[i] = vi(n + 1, 0);

    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = mp(u, v);

        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    dfs(1, 0, 0);

    // initialize segment tree with initial weights
    for (int i = 1; i <= n; i++) {
        if (val[i] != 0)
            update(1, 1, 2 * n, in[i], out[i], val[i]);
    }

    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        // ===== EDGE UPDATE =====
        if (type == 1) {
            int pos, x;
            cin >> pos >> x;

            int u = edges[pos].F;
            int v = edges[pos].S;

            int node = (depth[u] > depth[v] ? u : v);

            int delta = x - val[node];
            val[node] = x;

            update(1, 1, 2 * n, in[node], out[node], delta);
        }

        // ===== PATH QUERY =====
        else {
            int u, v;
            cin >> u >> v;

            int L = lca(u, v);

            int ans =
                query(1, 1, 2 * n, in[u]) +
                query(1, 1, 2 * n, in[v]) -
                2 * query(1, 1, 2 * n, in[L]);

            cout << ans << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
