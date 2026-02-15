#include<bits/stdc++.h>
using namespace std;
vector<int> in;
vector<int> out;
vector<vector<int>> adj;
void dfs1(int u , int par ){
    
    in[u] = 0 ;

    for(int v : adj[u]){
        if(v == par) continue;
        dfs1( v, u ) ;
        in[u] = max( in[u] ,  in[v] + 1  );
    }

}
void dfs2(int u , int par ){

    int m1 = -1 , m2 = -1 ;
    for(int v : adj[u]){
        if( v == par) continue;
        if( in[v] > m1 ){
            m2  = m1 ;
            m1 = in[v];
        }
        else if(in[v] > m2 ){
            m2 =in[v];
        }
    }

    for(int v : adj[u]){
        if( v == par ) continue;
        
        int use = m1 ;
        if(m1 == in[v]) use = m2 ;

        out[v] = max( use + 2  , 1 + out[u] );

        dfs2(v , u );

    }

}
int main(){ 

    int n ;
    cin>>n;
    in.resize(n);
    out.resize(n,0);
    adj.resize(n);
    for(int i = 0 ; i< n-1 ; i++){
        int u , v ; 
        cin>>u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0 , -1 );
    dfs2(0 , -1 ) ;
    int ans = 0 ;
    for(int i =0 ; i< n ;i++){
        ans = max( ans , in[i] + out[i]);
    }
    cout<<ans<<endl;
    return  0;
}