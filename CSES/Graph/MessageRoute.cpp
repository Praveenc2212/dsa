#include<bits/stdc++.h>
using namespace std;

vector<int>path;
vector<int>parent;
void solve(){
    int n , e;
    cin>>n>>e;
    parent.resize(n,-1);
    vector<vector<int>> adj(n);
    for(int i=0 ;i < e ;i++){
        int u ,v ;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n ,false);
    queue<int> q ; 
    q. push( 0);
    visited[0 ] = true;
    while(!q.empty()) {
            int u = q.front() ;
            q.pop();
            for(int v : adj[u] ) {
                if( !visited[v] ){
                    visited[v] =true;
                    q.push(v ) ;
                    parent[v] = u ;
                }
            }
    }
    vector<int>ans ;
    int v = n-1 ;
    while( v != -1 ) {
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin() , ans.end() ) ;
    cout<<ans.size()<<endl;
    for(int a : ans ) cout<<a+1<< " ";
}

int main(){
    int  t=  1 ;
    while(t--)
        solve();
    return 0;
}