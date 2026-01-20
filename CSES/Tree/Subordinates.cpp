#include<bits/stdc++.h>
using namespace std;
vector<int> sub;
vector<vector<int>> adj;
void dfs(int u ,int par){
    // sub[u] =1 ;
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v , u );
        sub[u] += sub[v];
    }
}
void solve(){
    int n ;
    cin>>n;
    adj.resize(n);
    sub.resize(n,1);
    for(int i = 1 ;i < n ; i++){
        int par ;
        cin>>par;
        par--;
        //  1 1 2 3
        //  0 0 1 2
        //_ 0 0 1 2 
        //0 1 2 3 4
        adj[par].push_back(i);
        adj[i].push_back(par);
    }

    dfs(0,-1);
    for(int a : sub){
        cout<<a-1<<" ";
    }
    cout<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t =1 ;
    while(t--) solve();
    return 0;
}