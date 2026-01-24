#include<bits/stdc++.h>
using namespace std;
void solve( vector<int>&arr){
    int n = arr.size();
    int sum = 0 ,ans = 0 ;
    int maxx = *max_element(arr.begin() ,arr.end() ) ;
    if( maxx <= 0  ) return maxx;
    for(int a : arr ) {
        sum += a ; 
        ans = max( ans , sum ) ;
        if (sum < 0 ) sum = 0 ;
    }
    cout<<ans ;
    return;
}
int main(){
    
    int n ; 
    cin>>n;
    vector<int> arr(n);
    for(int i = =0 ;i < n; i++){
        cin>>arr[i];
    }
    sovle(arr);
    return 0;
}