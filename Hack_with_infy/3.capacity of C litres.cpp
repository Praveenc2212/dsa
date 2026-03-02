#include<bits/stdc++.h>
using namespace std;
int n , c ;
void solve(vector<int>& arr ){

    int negative= 0 ;
    int ans_negative = 0 ;

    for(int a : arr ){
        negative += a ;
        ans_negative = min( negative, ans_negative );
    }
    if( ans_negative  < 0 ){
        cout<<-ans_negative<<endl;
    }
    else{
        cout<< 0 <<endl;
    }
}
int main(){
    cin>>n>>c;
    vector<int> arr(n );

    for(int i =0 ; i < n; i++)
        cin>>arr[i];

        solve(arr);
    return 0;
}