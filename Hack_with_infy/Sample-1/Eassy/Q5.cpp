#include<bits/stdc++.h>
using namespace std;

int gcd( int a , int b){

    if( b == 0 ) return a;

    return gcd( b , a % b );
}
int main(){

    string str;
    cin>>str;

    map<char,int> mp;
    for( char ch :  str )
        mp[ch]++;
    
    
    // int ans = 0 ;
    vector<int> freqs;
    for( auto it : mp ){
        freqs.push_back(it.second);
    }
    if( freqs.size() == 1  ){
        cout<<str.size()<<endl;
        return 0;
    }
    int ans = gcd( freqs[0] , freqs[1]);
    for( int i = 2 ;i < freqs.size() ; i += 1 ){
        ans = gcd( ans , freqs[i]);
    }

    cout<<ans<<endl;

    return 0;
}