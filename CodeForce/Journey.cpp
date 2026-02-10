#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> sub;
int dfs(int u , int par  ) {

    int ans = 0 ;
    for(int v : adj[u]){
        if(par == v ) continue;
        ans += dfs( v , u ) + 1 ;
        sub[u] = sub[v] ;    
    return ans;
}
string findans(double a){

    string str = to_string(a);
    stringstream ss(str);
    string val;

    vector<string> arr;
    while(getline(ss,val,'.')){
        arr.push_back(val);
    }
    if(arr.size() == 1 ){
        string ans = arr[0]+ ".000000000000000";
        return ans;
    }
    else{
        int sz= arr[1].size();
        string aaa = arr[0]  + "." + arr[1];
        for(int i = sz ; i < 15 ; i++){
            aaa += "0";
        }
        return aaa;
    }

}
int main(){
    int n;
    cin>>n;
    adj.resize(n);
    sub.resize(n , 1 );
    for(int i = 0 ;i < n-1 ;i++){
        int u , v ;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0 ;
    for(int i =0;i<n;i++){
        if( adj[i].size() ==1 ) cnt++;
    }

    int res= dfs(0 , -1 );
    double anss = res/ (double)cnt ;
    for(int a : sub ){
        cout<<a<<" ";
    }
    cout<<findans(anss);
    // cout<<anss;
    return 0 ;
}