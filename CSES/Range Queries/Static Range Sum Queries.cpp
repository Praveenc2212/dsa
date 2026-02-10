#include<bits/stdc++.h>
using namespace std;

int main(){ 

    int n ,qs;
    cin>>n>>qs;

    vector<long long> arr(n);
    
    for(int i =0 ;i < n ; i +=1 )
        cin>>arr[i];

    vector<long long > prefix(n);
    prefix[0] = arr[0];

    for(int i =1 ; i< n ; i +=1 )
        prefix[i] = prefix[i-1] + arr[i];

    for(int  i = 0 ;i <qs ;i++){
        int l, r ;
        cin>>l>>r;
        l--;
        r--;
        
        if( l-1 >= 0 ){
            cout<<prefix[r] - prefix[l-1]<<endl; 
        }
        else{
            cout<<prefix[r]<<endl;
        }
    }
}