#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n , k ;
    cin>>n>>k;
    long long x ,a, b ,c ;
    cin>>x>>a>>b>>c;
    vector<long long> arr(n);
    arr[0] = x ;
    for(int i =1 ;i < n; i++){
        arr[i] = (a * arr[i-1] + b )% c ;
    }
    vector<long long > ans ;
    long long sum =0 ;
    for(int i =0 ;i < k ; i+=1){
        sum = sum ^ arr[i];
    }
    long long as = sum ; 
    ans.push_back(sum);
    for(int i = k ;i < n; i += 1 ){
        sum = sum ^ arr[i];
        sum = sum ^ arr[i-k];
        ans.push_back(sum);
        as = as ^ sum ;
    }
    cout<<as<<endl;
}
int main(){

    int t= 1;
    while(t--){
        solve();
    }
    return 0;
}