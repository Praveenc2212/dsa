#include<bits/stdc++.h>
using namespace std;


int main(){

    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i =0 ;i < n ;i++){
        cin>>arr[i];
    }

    int k ;
    cin>>k;

    deque<int> dq ;

    for( int i = 0 ;i <= k ; i += 1 ){

        if(!dq.empty() || arr[dq.front()]    arr[i]  )
    }

    return 0;
}