#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(int i=0;i < n ;i++){
        cin>>arr[i];
    }

    vector<int> ans;
    map<long long ,long long> mp;
    for(int i=0;i < k;i++){
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    for(int i= k ; i < n ;i++){
        mp[arr[i]]++;
        mp[arr[i-k]]--;
        if(mp[arr[i-k]] == 0 ){
            mp.erase(arr[i-k]);
        }
        ans.push_back(mp.size());
    }
    for(auto a : ans ){
        // cout<<"Praveen";
        cout<<a<<" ";
    }
    cout<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    while(t--)
        solve();
    return 0;
}