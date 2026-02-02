#include<bits/stdc++.h>
using namespace std;

    vector<pair<int,int> > teleport;
    int row , col ;
    vector<vector<bool>> vis;

    void digis( vector<vector<int>> &mat , int k ) {

        priority_queue< pair<int,vector<int> >  , vector<pair<int,vector<int> >> , greater<pair<int,vector<int> >>  > pq ;

        pq.push( {0 , { 0 , 0, 0 } });
        vector<vector<vector<int> >> dis(row ,vector<vector<int>>(col , vector<int>( k  + 1 , 1e9 )) );
        dis[0][0][0] = 0 ;
        while( !pq.empty() ) {
            int i = pq.top().second[0]; 
            int j = pq.top().second[1]; 
            int t = pq.top().second[2];
            int distance = pq.top().first ;    
            pq.pop();
            if( distance <  dis[i][j][t]   ) continue;
            if( i == row -1 && j == col - 1  ) {
                cout<<"Answer : " << distance<<endl;
                return;
            }
            if( i + 1 < row && distance +  mat[i+1][j]  < dis[i+1][j][t]   ){
                dis[i+1][j][t] = distance + mat[i+1][j];
                pq.push({ dis[i+1][j][t]  , { i+1 , j , t  }});
            } 
            if( j + 1 < col && distance  + mat[i][j+1] < dis[i][j+1][t]  ) {  
                dis[i][j+1][t] = distance + mat[i][j+1];
                pq.push({ dis[i][j+1][t]  , { i , j + 1  , t }});
            }

            if( t < k ) {
                for(auto  p : teleport ){
                    int x = p.first;
                    int y = p.second;
                    if( mat[i][j] < mat[x][y] ) break;
                    
                    if( distance < dis[x][y][t+1]  ){
                        dis[x][y][t+1] = distance ;
                        pq.push( { distance , { x , y , t + 1 } } );
                    }
                }
            }
            

        }
        cout<<endl<<-1<<endl;
}

int minCost(vector<vector<int>>& mat, int k) {
        row = mat.size();
        col  = mat[0].size();

        vis.resize(row , vector<bool>(col , false));

        for(int i = 0 ; i < row ; i += 1 ){
            for(int j = 0 ;j < col ; j += 1 ) {
                teleport.push_back( { i , j } ) ; 
            }
        }
        sort( teleport.begin() , teleport.end() , [&](const pair<int,int>&a , const pair<int,int>&b){
            return mat[a.first][a.second] < mat[b.first][b.second];
        } );

        // for(auto p : teleport) {
        //      cout<<p.first<<" : "<<p.second<<endl; 
        // }
        // vis[0][0] = 1 ;
        digis(mat, k ) ;
        return 0 ;
        // return dfs(  0 , 0 , mat , k );
    }

    int main(){
        int n , m ;
        cin>>n>>m;
        vector<vector<int>> pp(n , vector<int>(m));
        int k;
        cin>>k;
        for(int i= 0 ;i < n ;i++){
            for(int j = 0 ;j < m ; j++){
                cin>>pp[i][j];
            }
        }
        cout<<minCost(pp , k );
    }