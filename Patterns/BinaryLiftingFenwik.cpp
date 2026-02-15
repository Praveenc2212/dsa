
#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>

#define vii vector<vi>

#define int long

vi depth;
vi in;
vi out;
vector<pair<int,int>> adj;

int t = 0 ;

void dfs(int u , int par , int d ) {

    in[u] =  t ;
    t+=1 ;

    for(auto p : adj[u]){
        int v = p.first;
        if(par == v ) continue;

        dfs( v , u , d + 1 ) ;
        
    }


    out[u] = t;
    t += 1 ;

}



int main(){
    
    int n ;

    cin >> n ;

    for( int i = 0 ; i < n - 1 ; i++ ){

        int u , v , w ;

        cin>>u>>v>>w;

        adj[u].push_back( make_pair( v , w ) ) ;

        adj[v].push_back( make_pair( u , w ) ) ;

    }

    dfs( 0 ,0 ,0 );

    
    return 0 ;
}