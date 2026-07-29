#include<bits/stdc++.h>
using namespace std;
vector<int>depth;
vector<int> value;
vector<vector<int>> jump;
int n ;
vector<vector<int>> adj;


void dfs( int u ,int par , int d ){
    
}

int main(){

    cin>>n;
    value.resize(n);
    
    for(int i = 0 ;i < n; i += 1 ) cin>>value[i];

    adj.resize(n);
    for( int i = 0 ;i < n ;i++) {
        int u , v ;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    return 0;
}