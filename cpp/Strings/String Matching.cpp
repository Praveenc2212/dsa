#include<bits/stdc++.h>
using namespace std;

struct Hasher{
    vector<int> fhash ;
    vector<int> pk ; 
    int sz , p , MOD ;
    void init( string &s , int _p , int _MOD ){
        sz = s.size();
        p = _p;
        MOD = _MOD;
        fhash.resize(sz );
        pk.resize(sz) ;

        pk[0] = 1 ;
        fhash[0] = s[0] - 'a' + 1 ;
        for( int i = 1 ;i < sz ; i += 1 ){
            fhash[i] =( ( fhash[i-1] * p ) % MOD +( s[i] - 'a' + 1)) % MOD ; 
            pk[i] = ( pk[i-1] * p ) % MOD ;
        }
    }

    int getHashValue( int l , int r ){
        if( l == 0 )
            return fhash[r];
        else{
            int hval = fhash[r] - ( fhash[l-1] * pk[r- l + 1 ]  % MOD) % MOD;
            return hval;
        }
    }
};


int quickHash( string s , int p ,int mod) {
    int hashVal = s[0] - 'a' + 1 ;
    int n = s.size();
    for( int i = 1 ; i < n  ; i +=  1 ) 
        hashVal = (( hashVal * p ) % mod  + ( s[i] - 'a' + 1 ) % mod ) % mod ;
    
    return hashVal;
}
void solve(){
    string txt , pattern ;
    cin>>txt>>pattern;

    if( txt == pattern ){
        cout<<1<<endl;
        return;
    }
    int n = txt.size();
    int m = pattern.size();
    int modulo = 999999937;
    int patternHash = quickHash(pattern , 37 , modulo  );

    Hasher hasher;
    hasher.init( txt , 37  , modulo);
    int ans = 0 ;
    for( int i = m-1 ; i < n ; i += 1 ) {
        int txtHash =  hasher.getHashValue( i - (m-1) , i  );
        if( txtHash == patternHash ){
            ans += 1 ;
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    int tc = 1 ;
    while(tc--){
        solve();
    }
    return 0 ;
}