#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
vector<ll>arr;
vector<ll>seg;
void build( int si , int low , int high ){

    if( low == high ){
        seg[si] = arr[low ];
        return ;
    }
    int mid = ( low  + high ) / 2 ;

    build( si *2 , low , mid );
    build( si *2 + 1 , mid + 1 ,high );
    seg[si] = seg[si*2] ^ seg[si*2 + 1 ];
}
ll query( int si , int low, int high , int l , int r ){

    if( r < low || high < l ){
        return 0;
    }
    if( l <= low && high <= r  ) return seg[si];

    int mid = ( low + high ) / 2 ;
    ll left = query( si * 2 , low , mid , l , r );
    ll right = query(si * 2 + 1 , mid + 1 , high , l , r );
    return left^right;
}
int main(){
    
    int n ,q  ; 
    cin>>n >> q;
    seg.resize( 4 * (n+1));
    arr.resize( n + 1 );
    for( int i = 1 ; i <= n ; i +=1 )
        cin>>arr[i];
    
    build(1  ,1 , n );

    while( q-- ){
        int l ,r ;
        cin>>l>>r;
        ll res = query( 1 , 1 , n  ,l ,r );
        cout<<res<<endl;    
    }
    

}