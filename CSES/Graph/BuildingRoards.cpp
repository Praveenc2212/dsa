#include<bits/stdc++.h>
using namespace std;
int vertex = -1 ;

void dfs(int u , int par , vector<vector<int>> & adj   ,vector<bool>&visited){

    visited[u] =true;
    vertex = u ;
    for(int v : adj[u]) {
        if(v == par )continue;
        dfs(v ,u , adj ,visited);
    }
}

void solve(){
    int n ,es;
    cin>>n>>es;
    vector<vector<int>>adj(n);
    for(int i= 0 ; i< es ;i++){
        int u , v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> com;
    vector<bool>visited(n , false);
    for(int i= 0 ;i < n ;i++){
        if( !visited[i] ){
            dfs(i ,-1 , adj ,visited);
            com.push_back(vertex);
        }
    }
    if( com.size() == 1 ){
        cout<<0<<endl;
    } 
    else{
        cout<<com.size() -1 <<endl;
        for(int i =0; i< com.size() -1  ; i++){
            cout<<com[i] + 1<<1 + com[i+1]<<endl;
        }
    }

}
int main(){
    int t= 1 ;
    while( t--){
        solve();
    }
    return 0;
}