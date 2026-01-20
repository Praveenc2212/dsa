#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int fun(int index, int target , vector<int>&coins) {
    
    if( target == 0 ) 
        return 0;
    
    if( target < 0 || index  >= coins.size() ) return 1e9;

    if(dp[target] != -1 ) return dp[target];
    
    int ans = 1e9 ;
    ans = min( ans , fun( index  , target - coins[index] , coins ) + 1  );
    ans = min( ans , fun( index + 1   , target , coins ) );
    return dp[target] =  ans ; 
}

void solve(){

    int n , target ;
    cin>>n>>target;
    vector<int> coins(n);
    memset(dp ,-1 ,sizeof(dp));
    for(int i =0 ;i < n; i+=1 )
        cin>>coins[i];
    int res = fun( 0 , target , coins);
    cout<<res<<endl;
}
int main(){
    int t = 1 ;
    while(t--){
        solve();
    }
    return 0;
}