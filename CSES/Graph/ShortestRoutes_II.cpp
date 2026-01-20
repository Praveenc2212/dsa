/*
YOur task id to process q queries where you have to determine the length of th eshortest route between two given cities.
*/

#include<bits/stdc++.h>
using namespace std;
void floyd(vector<vector<long long>>& mat) {
    int n =mat.size();

    for(int k =0 ;k < n; k += 1 ){
        for(int i = 0 ;i < n ; i+=1 ){
            for(int j =0 ;j < n; j += 1 ){
                if(mat[i][k] < 1e18 && mat[k][j] < 1e18 ) {
                    mat[i][j] = min( mat[i][j] , mat[i][k] + mat[k][j] );
                }
            }
        }
    }
}
void solve(){
    int n , e ,q ;
    cin>>n>>e>>q;
    vector<vector<long long>> mat(n ,vector<long long>(n,1e18));
    for(int i =0 ;i <e ;i++){
        int u , v;
        long long w ;
        cin>>u>>v>>w;
        mat[u-1][v-1] = min( mat[u-1][v-1] , w ) ;
        mat[v-1][u-1] = min(mat[v-1][u-1] , w ) ;
    }
    for(int i = 0 ;i < n ;i +=1 ) mat[i][i ] = 0;
    floyd(mat);
    vector<long long> ans(q);
    for(int i =0 ; i< q ; i += 1 ){
        int u , v ;
        cin>>u>>v;
        u--;
        v--;
        if( mat[u][v] >= 1e18 ){
            ans[i] = -1 ;
        } 
        else{
            ans[i] = mat[u][v];
        }
    }
    for(long long a : ans ) 
        cout<<a<<endl;
}
int main(){
    int t= 1 ;
    while( t-- ) {
        solve();
    }
    return 0;
}