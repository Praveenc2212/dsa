#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
vi val ; 
vector<vi> adj;
vi depth;
vi in;
vi out;
vi bit;
int n , q , t = 1 ;
void dfs(int u ,int par , int d ){
    in[u] = t ;
    t++;
    depth[u] = d ;

    for(int v : adj[u]){
        if( v == par )  continue;
        dfs(v , u , d + 1 );
    }
    out[u] = t ;
}

void update(int id , int val )
int main(){

    cin>>n>>q;
    adj.resize(n + 1 );
    val.resize( n + 1 );
    bit.resize(n + 2 , 0  ) ;

    for(int i = 1 ;i <= n ; i++) 
        cin>>val[i];

    for(int i =0 ; i< n-1 ; i +=1  ){
        int u , v ;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1 , 0, 0);

    for(int i = 1 ; i <= n ;i++){
        update( in[i] , val[i]);
    }    

    return 0;
}