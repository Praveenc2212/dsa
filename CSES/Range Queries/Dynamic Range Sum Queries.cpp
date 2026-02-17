#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> segment;
vector<long long> arr;
int find(int si , int low , int high , int l , int r ){
    if( low > r || high < l)
        return 0;
    if( l <= low && r >= high )
        return segment[si];
    int mid = (low + high ) / 2 ;
    int left = find( si * 2 + 1 , low , mid , l , r );
    int right = find( si * 2 + 2 , mid + 1 , high , l , r );
    return left + right;
}
void update( int si , int low , int high   , int index , int val ){

    if( index < low || high < index  ) return;

    if( low == high) 
    {
        segment[si] += val;
        return ;
    }
    int mid = ( low + high ) / 2 ;
    if( index <= mid  )
        update( si * 2 +1 , low , mid  , index, val);
    else
        update( si * 2 +2 , mid + 1 ,high   , index, val);
    segment[si] =  segment[si*2+2] + segment[si*2+1];
}

void build(int si , int low , int high   )
{
    if( low == high ) {
        segment[si] = arr[low];
        return ;
    }
    int mid = (low + high) / 2 ; 
    build( si*2+1 , low  , mid  );
    build( si*2+2 , mid + 1 , high );
    segment[si] =  segment[si*2+1] + segment[si*2+2];
}
signed main(){
    int n , qs;
    cin>>n>>qs;
    segment.resize(n*4+2);
    arr.resize(n);
    for(int i =0 ;i < n ; i++ )
        cin>>arr[i];

    build(0 , 0 , n-1 ); 

    for(int i = 0 ;i < qs ;i++){
        int  op ;
        cin>>op;
        if(op ==1 ){
            int k , val;
            cin>>k>>val;
            k--;
            int delta = val - arr[k];
            arr[k] = val;
            update(0 , 0 , n-1 , k , delta );
        }
        else{
            int l , r ;
            cin>>l>>r;
            l--;
            r--;
            cout<<find(0 , 0 , n-1 , l , r )<<endl;
        }
    }
    return 0;
}