#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj( n + 1 );
    int src = -1 ;

    vector<vector<int>> child(n + 1 );
    vector<int> C( n + 1 ) ;
    for(int u = 1 ; u <= n ; u += 1  ){
        
        int par , c  ;
        cin>>par>>c;
        if( par == -1 ) {
            src = u ; 
        }
        adj[par].push_back(u);
        C[u] = c ; 
        if(c){
            child[par].push_back(u);
        }
 
    }

    vector<int> parent(n + 1);
    vector<int> C(n + 1);        // 0 = compliant, 1 = non-compliant

    int root = -1;


   
    vector<int> compliantChildCnt(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int ch : children[i]) {
            if (C[ch] == 0) compliantChildCnt[i]++;
        }
    }

    set<int> removable;

    for (int i = 1; i <= n; i++) {
        if (C[i] == 1 && compliantChildCnt[i] == 0) {
            removable.insert(i);
        }
    }

    vector<int> answer;

    while (!removable.empty()) {
        int u = *removable.begin();
        removable.erase(removable.begin());

        answer.push_back(u);

        int p = parent[u];

        for (int ch : children[u]) {
            parent[ch] = p;
            if (p != -1) {
                children[p].push_back(ch);
                if (C[ch] == 0) compliantChildCnt[p]++;
            }
        }

        // remove u's effect from parent
        if (p != -1) {
            if (C[u] == 0) compliantChildCnt[p]--;

            // check if parent becomes removable
            if (C[p] == 1 && compliantChildCnt[p] == 0) {
                removable.insert(p);
            }
        }
    }
    if (answer.empty()) {
        cout << -1 << "\n";
    } else {
        for (int x : answer) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
