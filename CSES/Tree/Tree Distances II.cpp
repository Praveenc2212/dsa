#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
vi dist;
vi subtree;
vi sol;
vii adj;
int n ;
void dfs1(int u , int par , int d ) {

    subtree[u] = 1 ;

    for(int v : adj[u]){
        if(v == par ) continue;

        dfs1(v , u , d + 1 ) ;
        
        subtree[u] += subtree[v];
    }
}

void dfs2(int u, int par , int sum ) {
    sol[u] = sum;
    for(int v : adj[u]){
        if(par == v ) continue;

        dfs2(v , u  , sum - subtree[v] + n - subtree[v] );

    }
}

int main(){
    cin>>n;
    adj.resize(n);
    dist.resize(n);
    subtree.resize(n);
    sol.resize(n);
    for(int i = 0 ; i < n-1 ; i++){
        int u  , v ;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0 , -1  , 0 ); 
    int t = accumulate(dist.begin() , dist.end() , 0 ) ;
    dfs2(0 , -1 , t );
    
    for(int a : sol ) cout<<a<<" ";
    return 0;
}