#include<bits/stdc++.h>
using namespace std;
int n ;
vector<int> par;
void dfs(int u , int p,  vector<vector<int>> & adj){
    par[u] = p ;
    for(int v : adj[u]){
        if( v == p) continue;
        dfs(v , u , adj);
    }
}
vector<int> pathToRoot(int u ){
    vector<int> path;
    while( u != -1  ){
        path.push_back(u);
        u = par[u];
    }
    reverse(path.begin() , path.end());
    return path;
}
void lca(vector<vector<int>> & adj  ,int p1 ,int p2 ) {
     par.resize(n);

     dfs(0 , -1 , adj );
     for(int i = 0;i < n;i++ ){
        cout<<i <<" : "<<par[i]<<endl;
     }
     vector<int> path1 = pathToRoot(p1);
     vector<int> path2 = pathToRoot(p2);
     for(int a : path1 ) cout<<a<<" ";
     cout<<endl;
     for(int a : path2 ) cout<<a<<" ";
}

void solve(){
    cin>>n;
    vector<vector<int>> adj(n);
    int e;
    vector<vector<int>> arr;
    return 
    cin>>e;
    for(int i =0 ;i < e ;i++){
        int u , v ;
        cin>> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int p1 , p2 ; 
    cin>>p1>>p2 ;
    lca(adj , p1 ,p2 ) ; 
}
int main(){

    int t =1 ;
    while(t--)
        solve();
    return 0;
}