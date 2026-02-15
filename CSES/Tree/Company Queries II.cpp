#include<bits/stdc++.h>
using namespace std ;
#define vi vector<int>
#define vii vector<vi>

vi depth;
vii adj;
vii parent;

void dfs(int u , int par , int d ) {

    depth[u] = d ;
        
    parent[u][0] = par ;
    for(int i = 1 ; i< 20 ; i++)
        parent[u][i] = parent[parent[u][i-1]][i-1];


    for(int v : adj[u]){
        if( v == par ) continue;
        dfs(v , u , d + 1 ) ;
    }
}

void queries(int q){

    while(q--){
        int u , v ;
        cin>>u>>v ;

        if( depth[u] < depth[v]){
            swap(u,v);
        }
        int diff = depth[u] - depth[v];

        for(int i = 0 ; i < 20 ; i++){
            if( diff & ( 1 << i ) ){
                u = parent[u][i];
            }
        }
        if( u == v ) {
            cout<<v<<endl;
        }
        else{

            for(int i  = 19 ; i >= 0 ; i -=1 ) {
                if(parent[u][i] != parent[v][i]){
                    u = parent[u][i];
                    v = parent[v][i];
                }
            }
            cout<<parent[u][0]<<endl;
        }
    }
}
int main(){
    
    int n , q ;
    cin>>n>>q;
    depth.resize(n+1);
    adj.resize(n+1);
    parent.resize(n+1 , vi(20, 0 ));

    for(int v = 2 ; v <= n ; v += 1 ){
        int u ;
        cin>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1 , 0, 0 ) ;

    queries(q);   

    return 0 ;
}