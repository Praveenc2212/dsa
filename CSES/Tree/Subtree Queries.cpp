#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
int maxx = 1000001;
#define int long long
vii adj;
vi val;
vi in , out , depth;
vi seg , flat ;

int n , q , t = 0 ;

void dfs( int u , int par ){
    in[u] = ++t;
    for(int v : adj[u ])
        if( par != v ) 
          dfs(v, u );
    out[u] = t ;
}

void build(int si, int low , int high ){
    if(low == high ){
        seg[si] = flat[low];
        return ;
    }
    int mid = (low + high ) / 2 ;
    build( si * 2 , low , mid );
    build( si *2 + 1 , mid + 1 ,high );
    seg[si] = seg[si*2] + seg[si*2 + 1];
}
int query(int si , int low , int high , int l , int r ){
    
    if( r < low || high < l )
         return 0;

    if( l <= low && high <= r  ) 
        return seg[si];
    
    int mid = ( low + high ) / 2 ;

    int left = query( si * 2 , low , mid , l , r );

    int right = query(si*2+1, mid + 1, high , l , r );
    
    return left+ right ;
}
void update( int si , int low , int high , int index, int val ){
    if( index < low || high < index )
        return ;
    if( low == high ){
        seg[si] += val;
        return ;
    }
    int mid = ( low + high ) / 2 ;
    if( index <= mid )
        update( si * 2 , low , mid , index , val );
    else
        update( si * 2 + 1, mid + 1, high , index , val );
    seg[si ] = seg[si*2] + seg[si * 2 + 1];
}
void solveQuery(int q){
    
    while( q-- ){
        int t ;
        cin>>t;
        if(t == 1){
            int u , x;
            cin>>u>>x;
            int delta = x - val[u];
            val[u] = x ; 
            update( 1 , 1 , n , in[u] , delta );
        }
        else{
            int u ;
            cin>>u;
            int res = query( 1 , 1 , n , in[u] , out[u] );
            cout<<res<<endl;
        }
    }
}
signed  main(){
    cin>>n>>q;
    val.resize(n + 1 );
    adj.resize( n + 1);
    seg.resize( maxx , 0 );
    in.resize( n + 1);
    depth.resize( n + 1);
    out.resize( n + 1);
    flat.resize( n + 1 );

    for(int i = 1 ; i <= n ; i +=1 ) 
        cin>>val[i];
    
    for(int i = 0 ; i < n - 1 ; i +=1 ) {
        int u , v ;
        cin>>u >> v ; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs( 1, 0 );

    for(int u = 1 ; u <= n ; u++)
        flat[in[u]] = val[u];

    build( 1, 1 , n );

    solveQuery(q);
    return 0;
}