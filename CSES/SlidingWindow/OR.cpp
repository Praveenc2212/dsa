#include<bits/stdc++.h>
using namespace std;
int ns = 60 ;
vector<long long> num(ns , 0 );
void add( long long x ){
    for(int i =0 ;i < ns ;i += 1 ) {
        if(x & ( 1LL << i )){
            num[i]++;
        }
    }
}
void remove(long long x){
    for(int i =0 ;i < ns ;i += 1 ) {
        if(x&( 1LL << i )){
            num[i]--;
        }
    }
}
long long get(){
    long long res = 0 ;
    for(int i = 0 ;i < ns ; i+=1 ) {
        if(num[i] > 0 ){
            res = res | (1 << i);
        }
    }
    return res;
}
void solve(){
    long long n , k ,x, a ,b,c ;
    cin>>n>>k;
    cin>>x>>a>>b>>c;
    vector<long long> arr(n);
    arr[0] = x;
    for(int i= 1 ; i < n ;i++){
        arr[i] = ( a * arr[i-1] + b ) % c ; 
    }
    long long ans = 0 ;
    for(int i = 0 ;i < k ;i++){
        add(arr[i]);
    }
    ans = get();
     for(int i = k; i < n ; i++){
         add(arr[i]);
         remove(arr[i-k]);;
        ans = ans ^ get();
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t= 1 ;
    while(t--){
        solve();
    }
    return 0; 
}
// [3,0,1,8,2]
/*
0 0 0 0 1 0 2 2
*/
// [3,0,1,8,2]
/*
0 0 0 0 1 0 2 2
*/