#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int dp[1000001];
int fun(int index, int target , vector<int>&dice){

    if(target == 0 ){
        return 1 ;
    }
    if(target < 0 || index >= 6 ){
        return 0;
    }
    if(dp[target] != -1) return dp[target] % mod ;
    
    int ans = 0;
    ans += fun( index, target - dice[index] , dice ) % mod ;
    ans += fun( index + 1, target  , dice ) % mod ;
    return dp[target] = ans % mod  ;
}
void solve(){
    int n ;
    cin>>n;
    memset(dp,-1 , sizeof(dp));
    vector<int> dice(6);
    for(int i = 1 ;i <= 6 ; i+=1 )
        dice[i-1] = i ;
    int res = fun(0 , n ,dice )  % mod ;
    cout<<res <<endl;
}
int main(){
    int t = 1 ;
     while( t-- ) {
        solve();
     }
    return 0;
}