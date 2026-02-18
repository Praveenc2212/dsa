#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<vi>
int n , q , t = 1 ;
vi val, bit ;
vii adj;
vi in , out ;
void dfs(int u , int par ){
    in[u] = t ;
    t +=1 ;
    for(int v : adj[u])
        if(par != v )
            dfs( v , u );
   out[u ] = t;
   t+=1 ; 
}
void update(int id , int val ){
    while( id <= 2 * n )
    {
        bit[id ] += val;
        id += id & -id ;
    }
}
int query(int id){
    int res =0 ;
    while( id  > 0 )
    {
        res += bit[id];
        id -= id & -id;
    }
    return  res ;
}
void solveQuery(int q){
    while( q--){
        int t;
        cin>>t;
        if( t == 1) {
            int u , x ;
            cin>>u>>x;
            int delta = x - val[u ];
            val[u] = x;
            update( in[u] , delta );
            update( out[u] , -delta);
        }
        else{
            int u ; 
            cin>>u; 
            int res = query( in[u] );
            cout<<res<<endl;
        }
    }
}
void init(){
    val.resize( n + 1 );
    adj.resize( n + 1 );
    in.resize( n + 1);
    out.resize(n + 1);
    bit.resize( 2 * ( n + 1 ) , 0 );
}
signed main(){
    cin>>n>>q;
    init();

    for(int i = 1 ;i <=  n ; i +=1 )
        cin>>val[i];
    
    for(int i = 0;i  < n - 1 ; i++){
        int u , v; 
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs( 1 , 0 );
    for(int u = 1 ; u <= n ; u +=1 ){
        update( in[u ] , val[u ]);
        update( out[u ], -val[u]); 
    }
    solveQuery(q);

    return 0;
}
