#include<bits/stdc++.h>
using namespace std;
int row ,col ;
vector<vector<char>> mat;
vector<vector<int>> vis ; 
string ans = "";
void dfs( int i , int j , string cur ){

    if( mat[i][j] == 'B' ){
        if( ans == "" ||  ans.size() > cur.size())
            ans = cur ;
        return ;
    }
    vis[i][j] = 1 ;            
    // UP
    if( i - 1 >= 0 && mat[i-1][j] != '#' && !vis[i-1][j] ){
        dfs( i - 1 , j , cur + "U" );
    }
    // Right 
    if( j + 1 < col && mat[i][j+1] != '#' && !vis[i][j+1] ){
        dfs( i , j + 1 , cur + "R");
    }
    // Down 
    if( i + 1 < row && mat[i+1][j] != '#' && !vis[i+1][j] ){
        dfs( i  + 1 , j , cur + "D");
    }
    // Left 
    if( j - 1 >= 0 && mat[i][j-1] != '#' && !vis[i][j-1] ){
        dfs( i , j - 1 , cur + "L");
    }
    vis[i][j] = 0 ;
    return ;
}

int main(){ 
    cin>>row >> col ;
    mat.resize( row , vector<char>(col) );
    int si = -1 , sj = -1 ;
    for( int i = 0 ;i < row ; i  += 1 ){
        for (int j = 0 ; j < col ; j += 1  ){
            cin>>mat[i][j];
            if( mat[i][j] == 'A'){
                si = i , sj = j ;
            }
        }
    }
    dfs( si ,sj , "" );
    if(ans == ""){
        cout<<"NO"<<endl;
        return 0;
    }   
    else{
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    

    return 0;
}