
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = LLONG_MAX;

int n, qs;
vector<ll> seg, arr;

void build(int si, int low, int high) {
    if (low == high) {
        seg[si] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    build(si * 2, low, mid);
    build(si * 2 + 1, mid + 1, high);

    seg[si] = min(seg[si * 2], seg[si * 2 + 1]);

}

ll query(int si, int low, int high, int l, int r) {

    if (r < low || high < l) return INF;

    if (l <= low && high <= r) {
        return seg[si];
    }

    int mid = (low + high) / 2;
    ll left = query(si * 2, low, mid, l, r);
    ll right = query(si * 2 + 1, mid + 1, high, l, r);

    return min(left, right);
}

void update(int si, int low, int high, int index, ll val) {

    if (low == high) {
        seg[si] = val;
        return;
    }

    int mid = (low + high) / 2;

    if (index <= mid)
        update(si * 2, low, mid, index, val);
    else
        update(si * 2 + 1, mid + 1, high, index, val);

    seg[si] = min(seg[si * 2], seg[si * 2 + 1]);
}

int main() {
    
    ios::sync_with_stdio( false);
    cin.tie( nullptr) ;
    cout.tie(nullptr);

    cin >> n >> qs;

    arr.resize(n + 1);
    seg.resize(4 * (n + 1));

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while (qs--) {
        int type;
        cin >> type;

        int a, b;
        cin >> a >> b;

        if (type == 1) {
        
            update(1, 1, n, a, b);

        } 
        else if (type == 2) {

            cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}

