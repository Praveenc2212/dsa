#include<bits/stdc++.h>
using namespace std;

#define int long long

static bool  com( const vector<int>&a , const vector<int>&b ){
    return a[0] < b[0] ;
}
signed main(){

    int n ; 
    cin>>n;

    vector<vector<int>> arr( n , vector<int>(2));

    for( int i= 0 ;i < n ; i += 1 ){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }


    sort( arr.begin() , arr.end() , com   );

    int time = 0 ; 

    int cost = 0 ;

    for( auto job : arr ) {
        
        int duration = job[0];
        int d = job[1];
        time += duration ;
        cost += (   d - time  );
    }

    cout<<cost<< endl    ;  

    return 0 ;
}