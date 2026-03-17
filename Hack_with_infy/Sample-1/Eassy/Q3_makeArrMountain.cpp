#include<bits/stdc++.h>
using namespace std;

int main(){


    int n ;
    cin>> n;
    vector<int> arr( n );
    for( int i = 0 ;i < n ;i += 1 ){
        cin>>arr[i];
    }

    if( n & 1 == 1 ){
        // 0 1 2 3 4 5 6 == 7
        int i = n/2 ;
        int j = i;
        int cnt = 0 ;
        i++;
        // 1 2 3 4 5 15 16 15 5 4 3 2 1 
        j--;
        while(  i < n && j >= 0 ){

            if( arr[i]+1 )

        }

    }
    else{
        // 0 1 2 3 4 5 6 7   == 6
        int j = n / 2; 
        int i = j-1;

        



    }


    return 0;
}