#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> generate(vector<int>& nums){

    int n = nums.size();

    vector<int> arr;
    for(int mask = 0; mask < ( 1 << n ); mask += 1){
        int summ = 0;
        for(int i = 0; i < n; i += 1){
            if(  ( 1 << i ) & mask  ) summ += nums[i];
        }
        arr.push_back(summ);
    }
    sort( arr.begin() ,arr.end()) ;
    return arr;
}
void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for(int i =0 ;i < n ;i++)
        cin>>arr[i];

    vector<int> parts[2];
    for(int i = 0; i < n; i += 1)
        parts[i % 2].push_back(arr[i]);

    vector<int> left =  generate(parts[0]);
    vector<int> right = generate(parts[1]);

    int ans = 0;
    for(int a : left){
        int b = x - a;
        auto it1 = lower_bound(right.begin(), right.end(), b);
        auto it2 = upper_bound(right.begin(), right.end(), b);

        ans += (it2 - it1);
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}