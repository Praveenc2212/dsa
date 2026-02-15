//Internet Service Provider

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat;
vector<bool> visi;
int n;
int dfs(int u,int v, int cnt)
{
    if(u == v) return cnt;
    visi[u] = true;

    for(int i = 1 ; i <= n ; i++)
    {
        if(mat[u][i] != 0 && !visi[i])
        {
            int res = dfs(i,v,cnt+mat[u][i]);
            if(res != -1)
            {
                return res;
            }
        }
    }
    return -1;
}

int main() {
    int m,r;
    cin >> n >> r >> m;
    mat.resize(n+1,vector<int>(n+1,0));
    
    for(int i = 0; i < m ;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        mat[u][v] = w;
        mat[v][u] = w;
    }
    int queries;    
    cin >> queries;
    int vals = 0;
    for(int i = 0 ;i < queries ; i++)
    {
        int op,u,v,w;
        cin >> op >> u >> v >> w;
        if(op == 1)
        {
            visi.assign(n+1,false);
            vals += dfs(u,v,0);
        }
        else{
            mat[u][v] = w;
            mat[v][u] = w;
        }
    }
    cout << vals;
    
    return 0;
}