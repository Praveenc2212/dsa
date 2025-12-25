#include<bits/stdc++.h>
using namespace std;
int n ;
vector<vector<int>> adj;

void dfs(int u , int par ) {

    for(int v  : adj[u]) {

    }
}

void solve(){
    cin>>n;
    adj.resize(n);
    int e ;
    cin>>e;
    for(int i =0 ;i < e ;i++){
        int u , v ;
        cin>>u >>v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}
int main(){
    int t = 0;
    while( t--){
        solve();
    }
    return 0;
}