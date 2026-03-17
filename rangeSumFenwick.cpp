#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , q ;
vector<int> bit;
void update( int id , int val ){
    while( id <= n ){
        bit[id] = min(bit[id] , val );
        id += id & -id ;
    }
}

int query( int id ){
    int res = 0;
    while( id > 0 ){
        res = min( res , bit[id] );
        id -= id & -id ;
    }
    return res;
}

int rangeSum( int l , int r ){
    
    if( l-1 >= 1  ){
        return min(query(r) , query( l-1) );
    }
     return query( r );
}

signed main(){

    cin>>n>>q;

    vector<int> arr(n+1);
    bit.resize( n + 1 , 1e9 );
    for( int i= 1 ; i <= n ;i++){
        cin>>arr[i];
        update( i , arr[i]);
    }

    while( q-- ){
        int l , r ;
        cin>>l>>r;
        int ans = rangeSum( l , r );
        cout<<ans<<endl;
    }

    return 0;
}

