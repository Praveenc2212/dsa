#include<bits/stdc++.h>
using namespace std;

int row , col;
vector<vector<char>> mat;
vector<vector<bool>> vis;
int dx[]=  { -1 , 0 , 1 ,  0 };
int dy[] = { 0 , 1 ,0 ,-1 };
bool check( int i , int j ){
    return i >=0 && i < row && j < col && j >=0 && !vis[i][j] && (mat[i][j] == '.');
}
void dfs( int i ,int j ){
    vis[i][j] = true;
    for(int p =0 ;p < 4 ; p += 1 ){
        int ni = i + dx[p];
        int nj = j + dy[p] ;
        if(check(ni,nj)){
            dfs( ni,nj );
        }
    }
}
int main(){
    cin>>row>>col;
    mat.resize( row ,vector<char> (col));
    vis.resize( row , vector<bool>( col , false));
    for(int i =0 ; i <row ; i +=1 ){
        for(int j = 0; j < col ; j+=1 ){
            cin>>mat[i][j];    
        }
    }
    int ans = 0 ;
    for(int i =0 ; i < row ;i +=1 ){
        for(int j= 0 ; j < col ; j +=1 ){
            if(mat[i][j] == '.' &&  !vis[i][j] )
            {
            ans +=1 ;
            dfs( i, j );
            }
        }
    }
    cout<<ans<<endl;
    return 0 ;
}