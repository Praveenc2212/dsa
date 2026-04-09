#include <bits/stdc++.h>
using namespace std;

#define int long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()

#define endl '\n'
vi arr;

int n;
int k;
int fun(int i , int cur ,int prev  ){

    if( i == n ){
        if( cur-1 == k ){
            return 0;
        }
        else 
            return 1e9;
    }
    
    int ans = 1e9 ;
    if( prev < arr[i]  ){
        ans = min( ans , (i - cur) * ( i - cur ) +  fun( i +1 , cur + 1 , arr[i] )  );
    }
    ans = min( ans , fun( i +1 , cur , prev )  );

    return ans ;

}

void solve(){
    cin >> n;
    arr.resize( n ) ;
    cin>>k;
    for(int i = 0; i < n; i += 1) 
        cin >> arr[i];



    int res = fun( 0 , 0 , -1  );
    cout<<(res >= 1e9) ? -1 : res ;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--)
        solve();

    return 0;
}