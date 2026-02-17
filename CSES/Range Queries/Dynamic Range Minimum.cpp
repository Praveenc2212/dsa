#include<bits/stdc++.h>
using namespace std;
#define int long long
long long maxx = 1e18;
int n , qs ;
#define vi vector<int>
vi seg , arr;
void build(int si , int low , int high  ){

    if(low == high ){
        seg[si] = arr[low];
        return ;
    }
    int mid = (low + high ) / 2 ;

    build( si * 2 , low , mid );
    build( si * 2 , mid + 1 , high );
    seg[si] = min(seg[si*2] , seg[si*2 + 1 ]);
}
int query(int si , int low ,int high , int l , int r ){

    if( r < low || high < l  ) return maxx;

    if( l <= low  && high <= r  ){
        return seg[si];
    }
    int mid = ( low + high ) / 2 ;
    int left = query( si * 2 , low , mid , l , r ) ;
    int right= query(si * 2 + 1 , mid + 1,high ,l , r );

    return min(left, right);

}
void update(int si , int low,  int high , int index, int val ) {

    if( index < low || high < index ) return ;

    if(low == high ){
        seg[si] = val ; 
        return ;
    }
    int mid = ( low  + high ) / 2 ; 
    if( index <= mid )
        update( si * 2 ,low ,mid , index , val );
    else
        update(si * 2 + 1 ,mid + 1 , high , index, val  );

    seg[si] = min( seg[si * 2 ] , seg[si*2 + 1 ] );

}
signed main(){

    cin>>n>>qs;
    arr.resize(n + 1 );
    seg.resize( (n+1) * 4 + 5 );
    for(int i = 1 ; i <= n ; i++) cin>>arr[i];

    build(1 , 1, n );

    while(qs--){
        int type;
        cin>>type;
        int a , b ;
        cin>>a>>b;
        switch (type)
        {
        case 1:{
            update( 1 , 1 ,  n , a , b  );
            break;

        }
        case 2 :{
            
            int res = query( 1 , 1 , n , a , b );
            cout<<res<<endl;
            break;
        }
        }
    }
    return 0;
}