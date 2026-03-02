#include<bits/stdc++.h>
using namespace std;
int fun( int n ) {

    if( n == 1 ) {
        return 0;
    }
    if( n <0 ) return 1e9;
    int ans = 1e9;
    ans = min(ans ,1 +  fun( n - 1 ));
    ans = min(ans ,1 +  fun( ceil(n / 2.0) ));
    ans = min(ans ,1 +  fun( ( 2 * n ) / 3  ));
    return ans;
}
int main(){

    int n;
    cin>>n;

    int res = fun(n);
    cout<<res;
    
    return 0;
}