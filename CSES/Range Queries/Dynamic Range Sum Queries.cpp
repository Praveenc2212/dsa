#include<bits/stdc++.h>
using namespace std;
vector<int> segment;
vector<long long> arr;

int find(int si , int low , int high , int l , int r ){
        
    if( low > r || high < l) {
        return 1e9;
    }
    if( l <= low && r >= high )
        return segment[si];

    int mid = (low + high ) / 2 ;
 
    int left = find( si * 2 + 1 , low , mid , l , r );
    int right = find( si * 2 + 2 , mid + 1 , high , l , r );

    return min(left , right);
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
    segment[si] = min( segment[si*2+1] , segment[si*2+2] );
}
int main(){
    int n , qs;
    cin>>n>>qs;`
    segment.resize(n*4+2);
    arr.resize(n);
    for(int i =0 ;i < n ; i++ )
        cin>>arr[i];

    build(0 , 0 , n-1 ); 

    for(int i = 0 ;i < qs ;i++){
        int l , r , op ;
        cin>>op>>l>>r;
        l-- ;
        r--;
        if(op ==1 ){
            update();
        }
        else{
            
        }
        cout<<find(0 ,0 ,n-1 ,l ,r )<<endl;
    }
    return 0;
}