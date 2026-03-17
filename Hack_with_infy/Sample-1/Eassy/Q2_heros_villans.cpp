#include<bits/stdc++.h>
using namespace std;

bool check( int mid ,vector<int>&arr  , int health , int heros ){

        int cnt =  1 ;
        int consthealth = health ;
        for( int i = mid ; i < arr.size() ;i++){
            if( health >= arr[i]  ){
                health -= arr[i];
            }
            else{
                cnt++;
                health = consthealth;
                if( health >= arr[i]  ){
                    health -= arr[i];
                }
                else
                    return false;
            }
        }
        return cnt <= heros;
}

int main(){
    int n ;
    cin>>n;// villans
    int m , h ; // no.of heros ;
    cin>>m;
    // health of heros
    cin>>h;
    vector<int> arr(n);
    for( int i = 0; i < n ;i += 1  )
        cin>>arr[i];

    
    int ans , low = 0 , high = n ;

    while( low <= high ){
        int mid = low + ( high - low ) / 2 ;

        if( check( mid , arr , h ,m  ) ){
            ans = mid ;
            high = mid -1 ;
        }
        else
            low = mid + 1 ;
    }
    cout<<ans<<endl;
    return 0;
}