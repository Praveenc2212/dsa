/*
A group of N people are seated around a circular 
table to play a game.
*/

#include<bits/stdc++.h>
using namespace std;
int n, x ,y ;
vector<vector<int>> adj;
vector<int>arr;
vector<int> dis;
int bfs(  ){
    dis.resize( n , 1e9 );
    queue<int> q ;
    q.push( x );
    dis[x] = 0 ;
    
    while( !q.empty()){
        
        int  u = q.front();
        q.pop();
        
        for( int v : adj[u] ){
            if( dis[u] + 1 < dis[v] ){
                dis[v] = dis[u ] + 1 ;
                q.push( v );
            }
        }
    }
    cout<<((dis[y] == 1e9 )? -1 : dis[y]) <<endl;
}

void solve( ){
    adj.resize(n);
    for(int i =0 ;i < n ;i++){
        int u = i;
        int left  = (u + arr[i]) % n ;
        int right =(u - arr[i] + n) % n ;
        adj[u].push_back( left  );
        adj[u].push_back( right );
    }
    bfs();
}
int main(){
    
    cin>>n>>x>>y;
    x--;
    y--;
    arr.resize( n );

    for(int i= 0;i < n;i++){
        cin>>arr[i];
    }
    
    
    solve();
    
    return 0;
}