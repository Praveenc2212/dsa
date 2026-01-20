#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

void solve(){
    int n  ;
    cin>>n;
    adj.resize(n);
    for(int i = 0 ;i < n -1 ; i++){
        int u , v ;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t= 1 ;
    while(t--) solve();
    return 0;
}