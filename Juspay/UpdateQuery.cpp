#include <bits/stdc++.h>
using namespace std;

#define int long long

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second

#define all(x) x.begin(),x.end()

#define sz(x) (int) x.size()

#define endl '\n'
 
const int mxN = 204040;

vpi g[mxN];
pi edges[mxN];

int depth[mxN], val[mxN], in[mxN], out[mxN];
vi jump[21];

int n, q;

int t = 1 ;

int bit[2 * mxN];

void dfs(int u, int par, int d){
    
    depth[u] = d;
    jump[0][u] = par;
    
    in[u] = t;
    t += 1;

    for(int i = 1; i < 21; i += 1){
        jump[i][u] = jump[i - 1][jump[i - 1][u]];
    }

    for(auto& p : g[u]){
        int v = p.F, w = p.S;
        if(v != par){
            val[v] = w;
            dfs(v, u, d + 1);
        }
    }

    out[u] = t;
    t += 1;
}

int lca(int u, int v){
    if(depth[u] > depth[v])
        swap(u, v);

    int diff = depth[v] - depth[u];
    for(int i = 0; i < 21; i += 1){
        if(diff & (1LL << i))
            v = jump[i][v];
    }

    if(u == v)
        return u;
    else{
        for(int i = 20; i >= 0; i -= 1){
            if(jump[i][u] != jump[i][v]){
                u = jump[i][u];
                v = jump[i][v];
            }
        }

        return jump[0][u];
    }
}

void update(int id, int val){
    while(id <= 2 * n){
        bit[id] += val;
        id += id & -id;
    }
}

int query(int id){
    int ans = 0;
    while(id > 0){
        ans += bit[id];
        id -= id & -id;
    }
    return ans;
}
void solve(){
    cin >> n;

    for(int i = 0; i < 21; i++)
        jump[i] = vi(n + 1, 0);

    for(int i = 1; i <= n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = mp(u, v);

        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    dfs(1, 0, 0);

    for(int i = 1; i <= n; i++){
        update(in[i], val[i]);
        update(out[i], -val[i]);
    }

    cin >> q;

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int pos , x ;

            // cin >> pos >> x ;

            // int u = edges[pos].F, v = edges[pos].S;
            int u , v ;
            cin>>u>>v>>x;
            int node = -1;

            if(depth[v] > depth[u]) node = v;
            else node = u;

            int delta = x - val[node];
            val[node] = x;
    
            update(in[node], delta);
            update(out[node],-delta);

        }else{

            int u, v;
            cin >> u >> v;
            int ee;
            cin>>ee;

            int L = lca(u, v);

            int ans = query(in[u]) ;
            ans += query(in[v]) ;
            ans -= 2 * query(in[L]);

            cout << ans << endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}