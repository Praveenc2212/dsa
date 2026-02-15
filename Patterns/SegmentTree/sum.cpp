#include<bits/stdc++.h>
using namespace std;
vector<int> arr , seg;

int getSum(int si , int low , int high, int l , int r ){

    if( r < low || high < l )
        return 0;

    if( low <= l && r <= high )
        return seg[si];

    int mid = low + (high - low) /2 ;
    
    int left = getSum(si*2+1 , low , mid , l , r ) ;
    int right = getSum(si*2+2 , mid + 1 ,high , l ,r );
    
    return left + right ;
}

void build(int si , int low , int high ){
    if( low == high ) {
        seg[si] = arr[low];
        return ;
    }
    int mid = low +  ( high - low ) / 2 ;
    build(si*2 + 1 , low , mid ) ;
    build(si*2 + 2 , mid + 1 , high );
    seg[si] = seg[si*2+1] + seg[si*2+2];
}
int main(){

    int n , qs ;
    cin>>n>>qs;
    arr.resize(n);
    seg.resize( 4 * n  );

    for(int i = 0; i < n ;i +=1 ) 
        cin>>arr[i];
    
    build(0 , 0 , n-1) ;

    return 0 ;  
}