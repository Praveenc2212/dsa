#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> down ;
vector<int> up;
/*
0 --- 1
|
|
2----3
|
|
4

*/
void dfs1(int u , int par ) {
    down[u ] = 1 ;
    for(int v : adj[u]){
        if( v == par ) continue;
        dfs1(v , u ) ;
        down[u] = max( down[u] , down[v] +  1 );
    }
}

void dfs2(int u , int par ) {

        int m1 = -1 , m2 = -1 ; 
        for(int v : adj[u]){
            if( v == par ) continue)
        }

}
int main(){
    int n;
    cin>>n;
    adj.resize(n);
    for(int i= 0 ; i < n-1 ; i++){
        int u , v ;
        cin>>u>>v;
        u-- , v-- ; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    down.resize(n , 0 ) ;
    up.resize(n , 0 ) ;
    dfs1( 0 , -1 );
    for(int a : down ) cout<<a<<" ";

    return 0;
}