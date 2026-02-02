#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i= 0 ;i < n ; i+=1 ){
        cin>>arr[i];
    }

    int maxx = *max_element( arr.begin()  , arr.end() );
    cout<< maxx * n << endl ;
}
int main(){

    int t ;
    cin>>t;
    while(t--){
        solve();
    }

    return 0 ;
}