#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void shortestPath(vector<vector<pair<int,ll>> > &adj ){
    int n = adj.size();
    priority_queue<
        pair<ll,pair<int,int>>,
        vector<pair<ll,pair<int,int>>> ,
        greater<pair<ll,pair<int,int>>> 
    > pq;


    pq.push( { 0 , { 0 , 0 }  } );
    vector<vector<ll>> dis(n , vector<ll>(2 , 1e18) );
    dis[0][0] = 0 ;
    while( !pq.empty()){
        int u = pq.top().second.first;
        int used = pq.top().second.second;
        ll w = pq.top().first;
        pq.pop();

        if( w > dis[u][used] ) continue;

        for(auto it : adj[u]){
            int n_v = it.first;
            int n_w = it.second;

            if( w + n_w < dis[n_v][used] ){
                dis[n_v][used]= w + n_w;
                pq.push(  { dis[n_v][used] , { n_v , used } } );
            }

            if(used == 0 ){
                if(( w + n_w/2) < dis[n_v][1] ){
                dis[n_v][1]= w + n_w /2 ;
                pq.push(  { dis[n_v][1] , { n_v , 1 } }   );
            }
            }
        }
    }
    cout<<min(dis[n-1][1], dis[n-1][0])<<endl;
}

void solve(){
    int n , e ;
    cin>>n>>e;
    vector<vector<pair<int,ll>>> adj(n);
    for(int i =0 ;i < e ;i+=1 ){
        int u , v , w ;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back({v,w});
    }
    shortestPath(adj);

}

int main(){
    int t =1 ; 
    while( t-- ){
        solve();
    }
    return 0;
}