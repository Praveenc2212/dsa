#include<bits/stdc++.h>
using namespace std;

void solve(){


    int n ;
    cin>>n;
    vector<vector<int> > adj(n ) ;
    vector<int> arr(n);
    for(int i = 0 ;i < n ; i++) {
        cin>>arr[i];
    }
    for(int a : arr ) cout<<a<<" ";
    return ;
}
int main(){

    int t =1 ;
    while( t-- ){
        solve()
    }
    return 0;
}