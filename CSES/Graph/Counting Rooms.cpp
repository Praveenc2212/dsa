#include<bits/stdc++.h>
using namespace std;
int row , col ;
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0 , 1 , 0 , -1  };
void dfs(int i, int j , vector<vector<char>>&mat , vector<vector<bool>>&visited){
    visited[i][j] = true;
    for(int k =0 ;k < 4 ;k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni < row && ni >=0 && nj < col && nj >=0 && !visited[ni][nj] && mat[ni][nj] == '.'){
            dfs(ni ,nj ,mat,visited);
        }
    }
}
void solve(){
    cin>>row >> col;
    vector<vector<char>> mat(row ,vector<char>(col));
    for(int i =0 ;i < row ; i++){
        for(int j =0 ;j < col ;j += 1 ){
            cin>>mat[i][j];
        }
    }
    int res= 0 ;
    vector<vector<bool>> visited(row,vector<bool>(col ,false)  );
    for(int i =0 ;i <row ; i +=1 ){
        for(int j =0 ;j < col ;j+=1 ){
            if(!visited[i][j] && mat[i][j] == '.' ){
                dfs(i,j, mat,visited);
                res++;
            }
        }
    }
    cout<<res<<endl;
}
int main(){
    int t ;
     t = 1 ;
     while( t-- ){
        solve();
     }
     return 0 ;
}