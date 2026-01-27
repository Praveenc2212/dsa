#include<bits/stdc++.h>
using namespace std;
map<int,set<pair<int,int>> > mp ;
vector<vector<int>> adj;
vector<bool> visited;
bool check(int u , int v , int time){

    if( mp.find(u) != mp.end()){
        
        if( mp[u].find({  v , time  }) != mp[u].end() ){
            return false;
        }

    }
    return true;
}
int n ;
int gans = 1e9 ;  
int dfs(int u , int time ){
    
    if( u == n - 1 ){
        return time;
    }
    visited[u] = true ; 
    int ans = 1e9;
    for(int v : adj[u]) {
        if(!visited[v]){
            if(check( u , v , time )  ){
                ans = min( ans , dfs( v , time + 1 ));
            }
            else 
                ans = min( ans , dfs( u , time + 1  ));
        }
    }
    visited[u] = false;
    return ans;
}
void bfs(){

    queue<int> q ;
    q.push(0);

    visited[0] = true;
    vector<int>dis(n);
    dis[0] = 0 ;  
    while(!q.empty()){

        int sz = q.size();


    }

}
void solve(){
    int res= dfs(0 , 0 );
    if( res == 1e9 ) res = -1 ;
    cout<< res <<endl ;
}
int main(){
    int es ;
    cin>>n>>es;

    adj.resize(n);
    visited.resize( n , false );
     for(int i =0 ;i < es ;i++){
        int u , v ; 
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     int k ;
     cin>>k;
     for(int i =0 ;i < k ;i++){
        int u , v , t ;
        cin>>t>>u>>v;
        u--;
        v--;
        // mp[t] = { u , v  };
        mp[u].insert( { v , t } );
        mp[v].insert( { u , t } );
     }
     solve() ;
    return 0 ;
}