#include<bits/stdc++.h>
using namespace std;

bool check(int mid, int k, vector<int>& arr) {
    int n = arr.size();
    int cnt = 0 ; 
    int dis = 0;

    for(int i = 1; i < n; i++) {
        dis += (arr[i] - arr[i-1]);

        if(dis >= mid) {
            cnt++;
            dis = 0;
        }
    }
    return cnt >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int low = 0;
    int high = arr[n-1] - arr[0];

    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(check(mid, k, arr)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
}
