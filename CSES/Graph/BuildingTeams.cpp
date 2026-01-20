#include<bits/stdc++.h>
using namespace std;

void fun(int u , vector<vector<int>>&adj , vector<int>&visited){

   
}
void solve(){
    int n , e;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    for(int i= 0 ; i  < e ; i++) {
        int u , v ;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> visited( n , 0 ) ;
    for(int i =0 ; i< n ; i++){
        if( visited[i]== 0 ){
            fun( i , adj , visited);
        }
    }
}
int main(){
    int t = 1 ;
    while( t--)
        solve();
    return 0 ;
}
// n^2
