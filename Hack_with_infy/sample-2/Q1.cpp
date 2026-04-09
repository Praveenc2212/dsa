#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;
    vector<int> arr(n);

    for( int i=0;i < n ; i+=1)
        cin>>arr[i];
    
    int q ;
    cin>>q;
    vector<vector<int>> qs ;

    while( q--){
        int l ,r , x ,y ;
        cin>>l>>r>>x>>y;

        qs.push_back( { l ,r ,x, y  });

        for( int i = l , j = 0  ; i <= r ; i++ , j++ ){

            arr[i] = x + ( y * j );

        }
    }

    int res = accumulate( arr.begin() , arr.end() , 0 );
    cout<<res<<endl;

    return 0;
}