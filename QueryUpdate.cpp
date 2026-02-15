#include <bits/stdc++.h>
using namespace std;

#define int long long

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
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

int seg[8 * mxN];   // segment tree

/* ---------------- SEGMENT TREE ---------------- */

void update(int idx, int l, int r, int pos, int delta) {
    if (l == r) {
        seg[idx] += delta;
        return;
    }
    int mid = (l + r) / 2 ;

    if (pos <= mid)
        update( 2 * idx , l, mid, pos, delta);
    else
        update(2 * idx + 1, mid + 1, r, pos, delta);

    seg[idx] = seg[2 * idx ] + seg[2 * idx + 1];
}

int query(int idx, int l, int r, int ql, int qr) {
   
    if (qr < l || r < ql)
        return 0;

    if (ql <= l && r <= qr)
        return seg[idx];

    int mid = (l + r) / 2;

    return query(2 * idx, l, mid, ql, qr)
         + query(2 * idx + 1, mid + 1, r, ql, qr);
}

/* ---------------- DFS + LCA ---------------- */

void dfs(int u, int par, int d) {
    depth[u] = d;

    in[u] = t++;

    jump[0][u] = par;
    for (int i = 1; i < 21; i++)
        jump[i][u] = jump[i - 1][jump[i - 1][u]];

    for (auto &p : g[u]) {
        int v = p.F, w = p.S;
        if (v != par) {
            val[v] = w;
            dfs(v, u, d + 1);
        }
    }
    out[u] = t++;
}
int lca(int u, int v) {

    if (depth[u] > depth[v])
        swap(u, v);

    int diff = depth[v] - depth[u];

    for (int i = 0; i < 21; i++)
        if (diff & (1LL << i))
            v = jump[i][v];

    if (u == v)
        return u;

    for (int i = 20; i >= 0; i--) {
        if (jump[i][u] != jump[i][v]) {
            u = jump[i][u];
            v = jump[i][v];
        }
    }

    return jump[0][u];
}

/* ---------------- SOLVE ---------------- */

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

    // build initial segment tree using point updates
    for (int i = 1; i <= n; i++) {
        update(1, 1, 2 * n, in[i], val[i]);
        update(1, 1, 2 * n, out[i], -val[i]);
    }

    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos, x;
            cin >> pos >> x;

            int u = edges[pos].F;
            int v = edges[pos].S;

            int node = (depth[v] > depth[u]) ? v : u;

            int delta = x - val[node];
            val[node] = x;

            update(1, 1, 2 * n, in[node], delta);
            update(1, 1, 2 * n, out[node], -delta);

        } else {
            int u, v;
            cin >> u >> v;

            int L = lca(u, v);

            int ans = query(1, 1, 2 * n, 1, in[u]);
            ans += query(1, 1, 2 * n, 1, in[v]);
            ans -= 2 * query(1, 1, 2 * n, 1, in[L]);

            cout << ans << endl;
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
