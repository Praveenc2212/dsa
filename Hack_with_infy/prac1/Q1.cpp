#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int n) {
    unordered_map<int,int> mp;
    int res=0;
    for(int i=0;i<n;i++) {
        int dist = min(i,n-i-1);
        int val = nums[i] - dist ;
        mp[val]++;
        res = max(res,mp[val]);
    }
    return n - res ;
}

int main() {
    int n;cin>>n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) cin>>nums[i];
    cout<<solve(nums,n);
}