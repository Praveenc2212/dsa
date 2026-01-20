#include<bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
    long long n , k, x ,a ,b ,c ;
    cin>>n>>k;
    cin>>x>>a>>b>>c;
    vector<ll>arr(n);
    arr[0] = x;
    for(int i= 1 ;i < n ;i++)
        arr[i] = ( a * arr[i-1] +b ) % c ;
    
    long long ans = 0 ;
    long long sum = 0;
    for(int i =0 ;i < k ;i++)
        sum += arr[i];
    ans = sum;
    for(int i= k;i < n ;i++){
        sum += arr[i];
        sum -=  arr[i-k];
        ans = ans ^ sum ;
    }
    cout<<ans<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1 ;
    while(t--){
        solve();
    }
    return 0;
}