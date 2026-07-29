#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n)) return 0;
    cin >> m >> k;

    vector<int> layer(n);
    vector<long long> value(n);

    // Group nodes by layer so we can process lower layers first.
    map<int, vector<int>> nodesByLayer ;        

    for (int i = 0; i < n; ++i) {
        cin >> layer[i] >> value[i];
        nodesByLayer[layer[i]].push_back(i);
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> dp = value;

    // Process layers in increasing order.
    for (const auto &entry : nodesByLayer) {
        int currentLayer = entry.first;
        const vector<int> &nodesInLayer = entry.second;

        for (int u : nodesInLayer) {
            for (int v : adj[u]) {
                if (layer[v] > currentLayer) {
                    long long diff = static_cast<long long>(layer[v] - currentLayer);
                    long long penalty = diff * diff;
                    dp[v] = max(dp[v], dp[u] + value[v] - penalty);
                } else if (layer[v] == currentLayer) {
                    // Prevent repeated back-and-forth updates inside the same layer.
                    // This keeps the behavior close to the original Java code.
                    if (v > u) {
                        dp[v] = max(dp[v], dp[u] + value[v]);
                    }
                }
            }
        }
    }

    long long answer = LLONG_MIN;
    for (long long best : dp) {
        answer = max(answer, best);
    }

    cout << answer << '\n';
    return 0;
}