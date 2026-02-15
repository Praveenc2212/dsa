#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pb(x) push_back(x)
vii adj;
vi depth;
vii table;
void dfs(int u , int par ,int d ){

    depth[u] = d ;
    table[u][0] = par ;
    for(int i = 1 ;i < 20 ; i++){
        table[u][i] = table[table[u][i-1]][i-1]; 
    }
    
    for(int v : adj[u] ){
        if(par == v ) continue;
        dfs(v , u  , d + 1 );
    }
}
int main(){
    int n , qs ;
    cin>>n>>qs;
    depth.resize(n+1);
    table.resize(n+1 , vector<int>(20));
    adj.resize(n +1) ;
    
    for(int v = 2 ; v <= n ; v++){
        int u ;
        cin>>u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs(1 , 0 , 0 ) ;

    while(qs--){
        int x , k ;
        cin>>x>>k;

        if(depth[x] < k ) {
            cout<<-1<<endl;
        }
        else{
            int a = x ;
            for(int i = 0 ; i < 20 ;i++){
                if( k & ( 1 << i ) ){
                    a = table[a][i];
                }
            } 
            cout<<a<<endl;

        }
    }
    return  0 ;
}