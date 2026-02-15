#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
map<pair<int,int>,int> mp;

int timer;
int n,e,q,sum = 0;
int LOG = 20;

vector<vector<int>> jump;
vector<int> depth;
vector<int> in;
vector<int> out;
vector<int> dist;

/* ================= FENWICK TREE ================= */

vector<int> bit;

void fenwick_add(int idx, int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int fenwick_sum(int idx){
    int s = 0;
    while(idx > 0){
        s += bit[idx];
        idx -= idx & -idx;
    }
    return s;
}

// range add [l, r]
void range_update(int l, int r, int val){
    fenwick_add(l, val);
    fenwick_add(r + 1, -val);
}

int point_query(int pos){
    return fenwick_sum(pos);
}

/* ================= TREE DFS ================= */

void dfs(int u, int par, int d , int currDist){
    
    in[u] = ++timer;
    dist[u] = currDist;

    depth[u] = d;
    

    range_update(in[u], in[u], currDist);
    

    jump[u][0] = par;
    for(int i = 1 ; i <= LOG ; i++)
            jump[u][i] = jump[jump[u][i-1]][i-1];

    for(auto k : adj[u] ){

        int v = k.first;
        int wt = k.second;

        if(v != par){
            dfs( v , u , d + 1 , currDist + wt );
        }
    }

    out[u] = timer;

}

/* ================= LCA ================= */

int lca(int u, int v){

    if( depth[u] < depth[v] )
        swap(u , v );

    int diff = depth[u] - depth[v];

    for(int i = 0 ; i < 20 ; i++){
        if( diff & ( 1 << i) ){
            u = jump[u][i];
        }
    }
    if( u == v ) 
        return u;
        
    for(int i = 19 ; i >= 0 ;i -= 1 ){
        if( jump[u][i] != jump[v][i] ){
            u = jump[u][i];
            v =jump[v][i];
        }
    }
    return jump[u][0];
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>e;
    adj.resize(n+1);
    
    for(int i = 0 ; i < e ; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
        
        if(u > v) swap(u,v);
        mp[{u,v}] = wt;
    }
    
    timer  = 0;
    depth.assign(n+1,0);
    in.assign(n+1,0);
    out.assign(n+1,0);
    dist.assign(n+1,0);
    jump.assign(n+1,vector<int> (LOG+1,-1));
    
    bit.assign(n+2,0);
    
    dfs( 1, 0 , 0, 0);
    
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        
        if(ch == 1 ){
                int u,v,x;
                cin>>u>>v>>x ;   
                
                int d1 = point_query(in[u]);
                int d2 = point_query(in[v]);
                int ca = lca(u,v);
                int d3 = point_query(in[ca]);
                
                sum += (d1 + d2 - 2*d3);
                break;
        }            
        // edge update
        else{
                int u,v,nwt;
                cin>>u>>v>>nwt;
                
                int child = (depth[u] > depth[v] ? u : v);
                
                if(u>v) swap(u,v);
                int old_W = mp[{u,v}];
                int dif = nwt - old_W;
                
                mp[{u,v}] = nwt;
                
                // update subtree
                range_update(in[child], out[child], dif);
                break;
    
        }
    }
    
    cout<<sum;

    return 0;

}

