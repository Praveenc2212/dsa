#include<bits/stdc++.h>
using namespace std;
int row ,col ;
string ans ="";
int dx[] = {-1 , 0 ,1 ,0 };
int dy[] = { 0 ,1 ,0 ,-1 };
void fun( int i , int  j , int target_i , int target_j , vector<vector<char>>& mat ,string current , vector<vector<bool>>& visited ) {
   
    if(i  >= row || j >= col || j < 0 || i < 0 ) return;
    
    if(i == target_i && target_j == j ){
        if( ans.empty() || current.size() < ans.size()){
            ans = current;
            return ;
        }
    }

    // int a = 0; // U L D R
    string d= "";
    // visited[i][j] = true;
    for(int k =0 ;k < 4 ;k+=1){
        int ni = i + dx[k];
        if(k ==0 ) d= "U";
        if(k == 1  ) d= "R";
        if(k == 2 ) d= "D";
        if(k == 3 ) d= "L";
        int nj = j + dy[k];
        if(ni < row && ni >=0 && nj < col && nj >=0 && !visited[ni][nj] && mat[ni][nj] != '#' ){
            visited[ni][nj] = true;
            fun(ni ,nj , target_i ,target_j , mat, current +  d  , visited );
            visited[ni][nj] = false ;
        }
    }
    return ;
}
void solve(){
    cin>>row >> col;
    vector<vector<char>> mat(row ,vector<char>(col));
    vector<vector<bool>> visited(row ,vector<bool>(col , false));
    int start_i , start_j , target_i , target_j;
    for(int i=0;i < row ;i++){
        for(int j = 0 ;j < col ; j++) {
            cin>>mat[i][j];
            if(mat[i][j] == 'A') {
                start_i = i;
                start_j = j;
            }    
            if(mat[i][j] == 'B'){
                target_i =i ;
                target_j = j;
            }
        }
    }
    visited[start_i][start_j] = true;
    fun( start_i , start_j , target_i , target_j , mat , "" , visited ) ;
    if( ans == "" ){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
} 
int main(){
    int t = 1 ;
    while(t--)  solve();
    return 0;
}