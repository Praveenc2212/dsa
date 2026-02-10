#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> level ;

void dfs(int u , int par , int l){

    level[u] = l ; 
    for(int  v: adj[u]){
        if(v == par ) continue;
        dfs(v , u , l + 1 );
    }
}
void solve(){
    int n  ;
    cin>>n;
    adj.resize(n);
    level.resize(n);
    for(int i = 0 ;i < n -1 ; i++){
        int u , v ;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0 , -1 , 0 );
    int r = 0 ;
    for(int i = 0 ; i< n  ; i++){
        if(level[i] > level[r])
            r = i ;
    }

    dfs(r , -1 , 0 );

    for(int i = 0 ;i < n ; i++)
        if( level[i] > level[r]) r= i;

    cout<<level[r]<<endl;
    

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t= 1 ;
    while(t--) solve();
    return 0;
}