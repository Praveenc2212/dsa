#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ;
    cin>>n;
    set<long long> st;

    for(int i = 0 ;i < n;i++){
        int a ;
        cin>>a;
        st.insert(a);
    }
    cout<<st.size();
}
int main(){
    int t = 1 ;
    while( t-- )
        solve();

    return 0;
}