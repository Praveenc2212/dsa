#include<bits/stdc++.h>
using namespace std;

int main(){

    int n ;
    cin>>n;
    vector<int> arr( n );

    set<int> st;
    for( int i = 0;i < n;i+=1 ){
        cin>>arr[i];
        st.insert( arr[i ]);
    }

    int sz = st.size();

    int cnt = 1 ;
    int ans = 0 ;
    while( cnt <= sz ){
        ans += 1 ;
        cnt = cnt + cnt ;
    }

    cout<<ans<<endl;
    

    return 0;
}