#include<bits/stdc++.h>
using namespace std;

class DSU{
public :
    vector<int> parent , rank;
    int components ; 
    DSU(int n ){
        parent.resize(n);
        rank.resize(n , 0);
        components = n ;
        for(int i = 0 ;i < n; i++)
            parent[i]= i;
    }

    int find(int u ){
        if( parent[u] == u ) return u;
        return find(parent[u]);
    }

    void unite( int u , int v  ){
        int x = find(u);
        int y = find(v);

        if( x == y ) return ;

        //union by rank
        if( rank[x] < rank[y]){
            parent[x] = y;
        }
        else if( rank[y] < rank[x] ){
            parent[y] = x ;
        }
        else{
            parent[y] = x ;
            rank[x]++;
        }
        components--;
    }
};

static bool com( const vector<int>&a  , const vector<int>& b){
    return a[0] < b[0];
}

int main(){

    
    int n , k ;
    cin>>n>>k;

    vector<vector<int>> logs(k);

    for(int i=0 ;i < k ; i+=1 ){
        int day , u , v;
        cin>>day >> u >> v ;
        logs.push_back({ day , u , v });
    }

    sort( logs.begin() , logs.end() , com );


    for( auto log : logs ){
        int d = log[0];
        int u = log[1];
        
    }



    return 0;
}