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

#define len(x) (int) x.size()

#define endl '\n'

const int maxn = 1e5 + 5;

int n, m, k;
vi g[maxn];
int l_val[maxn], val[maxn];

int pen(int u, int v){
    int d = l_val[v] - l_val[u];
    return d * d;
}

int dp[maxn];

int rec(int u){
    if(dp[u] != -1)
        return dp[u];

    int ans = val[u];
    for(int v : g[u]){
        if(l_val[u] < l_val[v] )
            ans = max(ans, val[u] - pen(u, v) + rec(v));
        else if( l_val[u] == l_val[v] && u < v )
            ans = max(ans, val[u] - pen(u, v) + rec(v));
    }

    return dp[u] = ans;
}

void solve(){
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= n; i += 1)
        cin >> l_val[i] >> val[i];

    for(int i = 1; i <= m; i += 1){
        int u, v;
        cin >> u >> v;

        u += 1; v += 1;

        g[u].pb(v);
        g[v].pb(u);
    }

    int best = INT_MIN;
    for(int i = 1; i <= n; i += 1){
        int ans = rec(i);
        best = max(best, ans);
    }

    cout << best << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}