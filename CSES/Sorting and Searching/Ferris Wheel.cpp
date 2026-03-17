#include<bits/stdc++.h>
using  namespace std;


void solve( int  n ,int x , vector<int>&arr){

    sort( arr.begin()  , arr.end()  );


    int cnt = 0 ;
    for( int a : arr ){
        if( x-a >=0 ){
            x =x -a ;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main(){

    int n , x ;
    cin>>n>>x;

    vector<int> arr( n );

    for( int i= 0 ; i< n ; i++)
        cin>>arr[i];
    
    solve( n , x ,arr );

    return 0;
}