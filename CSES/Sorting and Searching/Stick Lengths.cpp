#include<bits/stdc++.h>
using namespace std;

signed  main(){

    int n;
    cin>>n;

    vector<int> arr( n ) ;

    for( int  i = 0;i < n; i++) cin>>arr[i];

    int sum = accumulate( arr.begin() , arr.end() , 0LL ); 

    int avg = sum / n;

    int ans = 0 ;

    for( int i = 0 ;i < n ; i++ ){
        int diff = abs( arr[i]  -  avg  );
        ans += diff ;
    } 
    cout<<ans<<endl;

    return 0;
}