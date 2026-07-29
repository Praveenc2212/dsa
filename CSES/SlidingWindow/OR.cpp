#include<bits/stdc++.h>
using namespace std;
int ns = 65;
long long num[65];
long long current = 0 ;
void add( long long x ){
    for(int i =0 ;i < ns ;i += 1 ) {
        if(x & ( 1LL << i )){
            num[i]++;
            if( num[i] == 1 ){
                current =  current | (1LL << i );
            }
        }
    }
}
void remove(long long x){
    for(int i =0 ;i < ns ;i += 1 ) {
        if(x&( 1LL << i )){
            num[i]--;
            if( num[i] == 0 ){
                current -= ( 1LL << i );
            }
        }
    }
}
void solve(){
    memset(num , 0 , sizeof( num ));
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
    ans = current;
     for(int i = k; i < n ; i++){
         add(arr[i]);
         remove(arr[i-k]);;
        ans = ans ^ current ;
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
