#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

      int n , k ; 
      cin>> n>> k;
      vector<int> arr( n );
      for(int  i= 0 ;i < n ; i +=1 ){
            cin>>arr[i];
      }

      int ans = 0 ;     

      int i = 0 , j = 0 ;
      int sum = 0 ;
      int neg = 0 ;
      while( i  <  n ){

        if( arr[i] < 0 ) neg++;

        while( neg > k ){
            // 1 -2 3 4 -4 2 1 -5 k = 2
            sum -= arr[j];
            if( arr[j] < 0 ) neg--;
            j++;
        }

        sum += arr[i];
        if( sum < 0 ) sum = 0 ; 
        ans = max( ans , sum );
        i++;
      }
      cout<< ans <<endl;
      return 0;
}
