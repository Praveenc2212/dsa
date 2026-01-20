
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> sub_tree;
vector<int> height;
void dfs(int u ,int par) {
    sub_tree[u] = 1 ;
    height[u] = 1; 
    for(int v : adj[u]  ) {
        if(v == par ) continue;
        dfs(v , u );
        height[u] = max( height[v] + 1  , height[u] );
        sub_tree[u] += sub_tree[v];
    }
}
void solve(){
    int n , e ; 
    cin>>n>>e;
    adj.resize(n);
    sub_tree.resize(n,0);
    height.resize(n);
    for(int i =0 ;i < e ;i++ ) {
         int u , v ;
        cin>>u>>v;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    dfs(0 , -1 ) ;
    for(int a: height)
        cout<<a<<" ";
    cout<<endl;
}
int main(){

    int t  =  1 ;
     while( t-- ){
        solve() ;
     }
    return 0 ;
}

/*
9
8
0 1
0 2
1 3
1 4
3 7
3 8
2 5
2 6
*/