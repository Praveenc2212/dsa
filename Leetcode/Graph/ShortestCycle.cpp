#include<bits/stdc++.h>
using namespace std;
class ShortestCycle {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> level;
    int n  , ans = 1e9;

    void dfs(int u ) {
        visited[u]  =1 ;
         for(int v : adj[u]){
            if(!visited[v]){
                level[v] = level[u] + 1 ;
                dffs(v);
            }
            else if(visited[v] == 1 ){
                ans = min(ans , level[u] - level[v] + 1 ) ;
            }
         }
        visited[u] = 2 ;
    }
    int findShortestCycle(int nn, vector<vector<int>>& edges) {
       n = nn ;
       adj.resize(n);
       visited.resize(n, 0);
       level.resize(n , 1 );
       for(auto e : edges ){
            int u = e[0] , v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
       }
       for(int i = 0 ; i < n ;i++)
       {
            if(!visited[i]){
                dfs( i ) ;
            }
       }
       return ans ==1e9 ? -1 : ans;
    }
    int main(){
    
    }
};
