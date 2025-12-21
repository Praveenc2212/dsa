#include<bits/stdc++.h>
using namespace std;
int n ,e ,pos1 ,pos2 , target ;

void fun(vector<vector<int>> &adj) {
    
    vector<int>dis(n , 1e9);

    dis[target] = 0 ;
    queue<int> q ;
    q.push(target);

    while(!q.empty() ){
        int u = q.front();
        q.pop();
        for(int v : adj[u] ){
            if( dis[v] == 1e9 ){
                dis[v] = dis[u] + 1 ;
                q.push(v);    
            }
        }
    }

    int p1 = pos1 , p2 = pos2;
    vector<bool> visited(n , false);
    visited[p1] = true;
    visited[p2] = true;
    
    while(true){
        if(p1 == target ){
            cout<<"Player1"<<endl;
            break;
        }
        int best = 1e9;
        int new_node = -1 ;
        for(int v : adj[p1]){
            if(!visited[v] && dis[v] < best ){
                best = dis[v];
                new_node = v ;
            }
        }
        if( new_node == -1 ){
            cout<<"player2"<<endl;
            break;
        }
        p1 = new_node;
        visited[p1] =true;
        if(p1 == target ){
            cout<<"Player1"<<endl;
            break;
        }
        // player 2 
        if(p2 == target ){
            cout<<"Player2" <<endl;
            break;
        }
        new_node = -1 ;
        best = 1e9;
        for(int v : adj[p2]){
            if(!visited[v] && dis[v] < best ){
                best = dis[v] ;
                new_node = v ;
            }
        }
        if(new_node == -1 ){
            cout<<"player1"<<endl;
            break;
        }
        p2 = new_node;
        visited[p2] =true;
        if(p2 == target ){
            cout<<"Player2"<<endl;
            break;
        }
    }
}
void solve(){
    cin>>n >>e;
    vector<vector<int>> adj(n);

    for(int i =0 ;i < e ;i++){
        int u ,v ;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>pos1>>pos2>>target;
    fun( adj);

}
int main(){

    int t =1 ;
    while( t-- ) {
        solve();
    }
    return 0;
}