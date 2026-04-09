#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define vi vector<int>
#define vii vector<vi>

#define pb push_back
#define bp pop_back


struct node{
    int summ;
    int l1 , l2 ;
    node() {
        l1 = 0 , l2 = 0 ;
        summ = 0 ;
    }
};
vector<node> seg ;

node merge( node a , node b ){
    node c ;
    c.summ = a.summ + b.summ;
    return c ; 
}
vector<int> arr;
int n , q ; 

void build( int si , int low  , int high  ){
    if( low == high ){
        seg[si].summ= arr[low];
        return ;
    }
    int mid = ( low + high )  >> 1 ;
    build( si << 1 , low , mid ) ;
    build( si << 1 | 1 , mid + 1 , high ) ;
    seg[si] = merge( seg[si << 1 ] , seg[si << 1 | 1 ]);
}
void push_down( int si , int low ,int high ){

}
void apply1( int si ,int len , int add ){

    seg[si].summ += (add * len) ;
    seg[si].l1 += add ;

    

}
void rangeUpdate( int si ,int low ,int high , int ql , int qr , int val ){
    
    if( qr < low || ql > high ) 
        return ;
    
    if( ql <= low && high <= qr ){
        apply1(si , high - low + 1 , val );
    }
    else{
        push_down( si , low, high );
        int mid = ( low + high  )  >> 1 ;
        rangeUpdate( si << 1 , low ,mid , ql ,qr , val  );
        rangeUpdate( si << 1 | 1 ,  mid + 1 , high , ql ,qr , val );
        seg[si] = merge( seg[si << 1 ] , seg[si<<1 | 1 ]);
    }
}
int rangeSum( int si , int low , int high , int ql ,int qr ){

    if( qr < low || ql > high  ) 
        return 0;
    if( ql <= low && high <= qr  )
        return seg[si].summ;
    push_down( si , low , high  );
    int mid = ( low + high ) >> 1 ;
    int left = rangeSum( si >> 1 , low , mid  , ql , qr  );
    int right = rangeSum( si >> 1 | 1 , mid + 1 , high , ql , qr );

    return left + right ;
}


int getRangeSum( int  l ,  int r ) {
    int res = rangeSum( 0 , 0 , n - 1 , l ,r );
    return res ;
}



void solve(){

    cin>>n>>q;
    seg.resize( n * 4 , node()) ;
    arr.resize(n);
    for(int i = 0 ;i < n ; i +=1 ) {
        cin>>arr[i];
    }
    
    build( 0 , 0 , n-1  );

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}