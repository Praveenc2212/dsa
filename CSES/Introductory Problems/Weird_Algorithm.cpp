#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ; 
    cin>>n;
    cout<<n<<" ";
    if(n==1)return;
    while(n != 1 ){
        if(n&1){
            n = (n*3) + 1 ;
        }
        else{
            n = n/2; 
        }
        cout<<n<<" ";
    }
}
int main(){ 
    int t = 1; 
    while(t--)
        solve();
    return 0;
}