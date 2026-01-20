//Question
/* There are n cities and m flight connections between them.Your task is to determine the length of the shortest route from Syrjala to every city.
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long> dis;
void dijtras(vector<vector<pair<int,long long>>> &adj ){

    priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> > q; 
    q.push({ 0 , 0 } );

    while( !q.empty() ){
        int u = q.top().second;
        long long w = q.top().first;
        q.pop();
        if( dis[u] < w ) continue;
        for(auto it : adj[u] ){
            int n_v = it.first;
            int n_w = it.second;
            if( w + n_w < dis[n_v] ){
                dis[n_v] = w + n_w;
            	q.push( {  dis[n_v] , n_v } );
            }
        }
    }
}
void solve(){
    int n , e ;
    cin>>n>>e;
    dis.resize(n,1e18);

    vector<vector<pair<int,long long>>> adj(n);
    for(int i = 0 ;i < e ;i+=1 ){
        int u, v ;
        long long w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back( { v ,w } );
    }
    dis[0] = 0 ;
    dijtras(adj);
    for(long long a : dis )cout<<  a   <<" ";
    cout<<endl;

}
int main(){
    int t=1 ;
    while(t--)
        solve();
    return 0;
}