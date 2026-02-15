#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define int long long
vii adj;
vi depth;
vii parent;

void dfs(int u, int par, int d)
{

    depth[u] = d;

    parent[0][u] = par;

    for (int v : adj[u])
    {
        if (par == v)
            continue;
        dfs(v, u, d + 1);
    }
}

int lca(int u, int v)
{

    if (depth[u] < depth[v])
    {
        swap(u, v );
    }
    int diff = depth[u] - depth[v];

    for (int i = 0; i < 20; i++)
    {
        if ( diff & (1LL << i))
        {
            u = parent[i][u];
        }
    }

    if ( u == v )
        return u ;

    for (int i = 19 ; i >= 0 ; i -= 1  )
    {
        if (parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , q ;
    cin >> n >> q ;

    adj.resize(n + 1);
    depth.resize(n + 1);
    parent.resize( 20 , vector<int>( n + 1 , 0  ));

    for (int i = 0 ; i < n - 1; i++ )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);

    for(int i =1 ;i < 20 ; i++){
        for(int u = 1 ; u <= n ; u +=1 ){
            parent[i][u] = parent[i-1][parent[i-1][u]];
        }
    }
    while(q--){
        int u , v;
        cin>>u>>v;
        int d1 = depth[u];
        int d2 = depth[v];
        int d3 = depth[lca(u,v)];

        cout<<d1 + d2 - (2 * d3 ) << endl ;  
    }

    return 0;
}