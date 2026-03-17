#include<bits/stdc++.h>
using  namespace std;


void solve( int n , int m , int k ,vector<int>&arr1 , vector<int>&arr2 ){

    sort( arr1.begin()  , arr1.end() );
    sort( arr2.begin() , arr2.end() );



    int i = 0 , j = 0 , cnt = 0 ;

    while( i < n && j < m ){

        if( abs( arr1[i] - arr2[j] ) <= k  ){
            cnt++;
            i++;
            j++;
        }
        else{
            if( arr1[i] < arr2[j] ){
                i++;
            }else{
                j++;
            }
        }     
    }
    cout<<cnt;
}
int main(){

    int n , m , k ;
    cin>>n>>m>>k;

    vector<int> arr1( n ) ;
    vector<int> arr2( m ) ;

    for(int i = 0;i < n ; i++)
        cin>>arr1[i];
    
    for(int i = 0; i < m ;i++)
        cin>>arr2[i];
    
    solve( n , m , k , arr1 , arr2 );

    return 0;
}