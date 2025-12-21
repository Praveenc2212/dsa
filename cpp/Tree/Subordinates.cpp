#include<bits/stdc++.h>
using namespace std;

vector<int> down;

vector<vector<int>> adj;
void dfs1(int u , int par) {
    
    for(int v : adj[u] ) {
        if(v == par) continue;
        dfs1( v , u ) ;
        
        down[u] = max( down[u] , 1 + down[v]);
    }
}
vector<int> up;

void dfs2(int u , int par) {
    int m1 = -1 , m2 = -1 ;
    for(int  v : adj[u] ) {
        if( v == par ) continue;
        
        if( m1 <= down[v]) {
            m2 = m1 ;
            m1 = down[v];
        }
        else if( m2 <= down[v] ) m2 = down[v];
    }
    
    for(int v : adj[u] ) {
        
        if( v == par ) {
            continue;
        }
        int use = m1;
        if( m1 == down[v] )  use = m2;

        up[v] = max( 2 + use , 1 + up[v] );
        dfs2(v , u );


    }
    
}

void solve(){

    int n ;
     cin>>n;
    down.resize(n,0);
    up.resize(n,0);
    adj.resize(n+1);
    
    for(int i = 1 ; i  < n ; i += 1 )
    {
        int v  , u;
        cin>>v>>u;
        v--;
        u--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1( 0 , -1 );
    cout<<"Height"<<endl;
    for(int  a  : down){
        cout<<a<<" ";
    }
    cout<<endl<<"UP side"<<endl;
    for(int a : up ){
        cout<<a << " ";
    }
    cout<<endl;

}

int main(){

    int t =1 ;
    while(t--){
        solve();
    }

    return 0;
}