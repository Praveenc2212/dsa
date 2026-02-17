#include<bits/stdc++.h>
using namespace std;
int n ;
vector<int> arr;

int fun(int i , int k) {

    if( k == 0 ){
        return 0 ;
    }

    if( i < 0 ) return -1e9 ;

    freq[]
    int ans = 1e9 ;    
    int cost = 0;

    for(int j = 0 ; j < i ; j+=1 ){
        int fr = map[j];

        cost -= for(fr);
        cost += for(fr + 1);

        ans = min( ans, fun( j -1 , k - 1 )  + cost )  ;
    }   

    return ans ;
}

void solve(){
    int  k =2 ;
    int ans = fun( n - 1  , k  );

}

int main(){

    cin>>n;
    arr.resize( n ) ;
    for(int i = 0 ; i < n ; i++ ){
        cin>>arr[i];
    }
    sovle();
    return 0;
}
