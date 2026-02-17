#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

vector<vector<pair<int,int>>> adj;
int n , m;

void solve(){
    int k;
    cin >> k;

    vector<vector<int>> dist(n, vector<int>(k+1, 1e18));

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<>
    > pq;

    pq.push({0, {0, k}});
    dist[0][k] = 0;

    while(!pq.empty()){
        int u = pq.top().second.first;
        int w = pq.top().first;
        int t = pq.top().second.second;
        pq.pop();

        if( w > dist[u][t]) continue;

        for(auto it : adj[u]){
            int v = it.first;
            int wt = it.second;

            if(dist[v][t] > dist[u][t] + wt){
                dist[v][t] = dist[u][t] + wt;
                pq.push({dist[v][t], {v, t}});
            }

            if(t > 0 && dist[v][t-1] > dist[u][t]){
                dist[v][t-1] = dist[u][t];
                pq.push({dist[v][t-1], {v, t-1}});
            }
        }
    }
    int ans = 1e9 ;
    for(int i = 0; i <= k; i++)
        ans = min( ans, dist[n-1][i] );

    cout << ans << endl;
}

int main(){
    cin >> n >> m;

    adj.resize(n);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    solve();
}
