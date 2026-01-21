#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> sol(){
    int n = adj.size();
    vector<int>degree(n , 0 );
    for(int i = 0 ; i < n ;i+=1 ){
        degree[i] = adj[i].size();
    }
    int nodes = n ;
    queue<int> q ;
    for(int i = 0 ;i < n ;i++){
        if(degree[i] == 1 ) {
            q.push(i);
        }
    }
    vector<int> visited(n,false);
    while(!q.empty()){
        int nz = q.size();
        for(int i =0 ;i < nz ;i++){
            int u = q.front();
            q.pop();
            nodes--;
            visited[u] = true;
            for(int v : adj[u]){
                degree[v]--;
                if(degree[v] == 1 ) q.push(v);
            }
        }
        if(nodes == 2 ){
            break;
        }
        if(nodes == 1 )break;
    }
    vector<int> ans;
    for(int i =0 ;i < n;i++){
        if(!visited[i] ){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto e : edges ) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return sol();
        }

int main(){
    int t= 0 ;
    int n;
    cin>>n;
    int es ;
    cin>>es;
    vector<vector<int>> edges;
    for(int i =0 ;i < es ;i +=1 ) {
        int u , v ;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<int> ans = findMinHeightTrees(n , edges);
    for(int a : ans  )cout<<a << " ";
    cout<<endl;
    return 0;
}
