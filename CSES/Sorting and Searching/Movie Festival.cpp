#include<bits/stdc++.h>
using namespace std;
#define int long long 
static bool com( const vector<int>&a , const vector<int>&b){
    return a[1] < b[1];
}

void solve(){
    int n ;
    cin>> n ; 
    vector<vector<int>> arr( n , vector<int>(2) );

    for(int i = 0 ;i < n ;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }

    sort( arr.begin() ,arr.end() , com) ;


    int ans = 0 ;

    int finish = -1 ;

    for( int i =0 ;i   < n ;i++){
        int startTime = arr[i][0];
        int endTime = arr[i][1];

        if( finish <= startTime   ){
            ans++;
            finish = endTime ;
        }
        
    }
    cout<<ans<<endl;

}
signed main(){

    solve();

    return 0 ;
}