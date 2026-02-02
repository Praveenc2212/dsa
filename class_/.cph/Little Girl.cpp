#include<bits/stdc++.h>

using namespace std;

vector<int> sweepline(int qs , int n  ) {
    vector<int> arr(n , 0 );
    vector<pair<int,int>> line;
    for(int i =0 ; i< qs ;i++){
        int start , end;
        cin>>start>>end;
        start--;
        end--;
        line.push_back({start , +1 });
        line.push_back({end , -1 });
    }
    sort(line.begin() , line.end());
    int cnt = 0 ;
    for(auto p : line) {
        int a = p.first;
        cnt += p.second;
    }
    sort(arr.begin()  ,arr.begin()); 
    for(int a  : arr) {
        cout<<a<<" " ;
    }
    cout<<endl;
    return arr;
}
int main(){

    int n , qs;
    cin>>n>>qs;
    vector<int>arr(n);
    for(int i=0;i < n ;i++) cin>>arr[i];

    vector<int> sweep;
    sweep = sweepline( qs , n );

    sort(arr.begin() ,arr.end() ) ;
    int ans = 0 ; 
    for(int i = 0 ; i < arr.size() ; i++) {
        ans += ( arr[i] * sweep[i]);
    }

    cout<<ans;

    return 0;
}