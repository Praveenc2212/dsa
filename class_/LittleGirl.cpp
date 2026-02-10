#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> query;
vector<int> arr;
int n ,qs ;

void solve(){

    vector<int>prefix(n,0);
    for(auto q : query ){
        int l = q[0] , r = q[1];
        prefix[l]++;
        if(r + 1 < n)
            prefix[r+1]--;
    }
    for(int i = 1 ;i < n ; i++){
        prefix[i] = prefix[i-1 ] + prefix[i];
    }
    sort(prefix.begin() , prefix.end() ) ;
    sort(arr.begin() , arr.end());

    long long ans = 0 ;
    for(int  i =0 ;i < n ;i++){
        ans += ( arr[i] * prefix[i] );
    }
    cout<<ans;

}
int main(){

    cin>>n>>qs;
    arr.resize(n);
    for(int i =0 ; i< n ; i +=  1 )
        cin>>arr[i];
    for(int i = 0;i < qs ;i += 1 ) {
        int l ,r ;
        cin>>l>>r;
        l--;
        r--;
        query.push_back({l,r});
    }
    solve();

    return 0;
}