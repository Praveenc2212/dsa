/*
You have to complete n courses. There are m requirements of the form "course a has to be completed before course b". Your task is to find an order in which you can complete the courses.
*/
#include<bits/stdc++.h>
using namespace std;
void toposort(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int> indegree( n, 0 ) ;
    for(int u = 0;u < n; u += 1 ){
        for(int v : adj[u]){
                indegree[v]++;
        }
    }
    queue<int> q ;
    for(int u = 0; u < n ; u +=1  ){
        if(indegree[u] == 0 )
            q.push(u);
    }
    int cnt= 0  ;
    vector<int> topo;
    while(!q.empty() ) {
        int  u = q.front();
        q.pop();
        cnt++;
        topo.push_back(u+1);
        // cout<<u+1<<" ";
        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v]== 0 ){
                q.push(v);
            }
        }
    }
    if(cnt < n ){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(int a : topo ) 
            cout<<a<<" ";
        cout<<endl;
        }


    return;
}
void solve(){
    int n , e ;
    cin>>n>>e;
    vector<vector<int>> adj( n );
    for(int i =0 ;i < e ; i++){
        int u ,v ;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    toposort(adj);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t= 1 ;
    while(t--)
        solve();
    return 0 ; 
}