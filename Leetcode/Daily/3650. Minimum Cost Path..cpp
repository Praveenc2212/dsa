#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<pair<int,int> >> adj;
    int minCost(int n, vector<vector<int>>& edges) {

        adj.resize(n);

        for(auto e : edges ) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({ v , w  });
            adj[v].push_back({ u , w * 2 });
        }

        priority_queue<pair<int,int> , vector<pair<int,int> , greater<vector<pair<int,int>>> > pq;

        
    }
};

/*
1. Minimal Time to Reach Node N
You are given an undirected graph with N nodes numbered from 1 to N. You always start from node 1 and want to reach node N.

Key Rules:
Each move from one node to an adjacent node takes exactly 1 unit of time
Time starts at t = 0
At certain K specific time moments, some edges temporarily disappear
When an edge disappears at time t, it cannot be used at that exact time
The edge reappears immediately at time t+1
You may wait at a node (waiting also consumes 1 unit of time)

Goal:
Find the minimum time required to reach node N. If it is impossible, return -1.

Input Format:
N M
u1 v1
u2 v2
...
uM vM
K
t1 x1 y1
t2 x2 y2
...
tK xK yK
Where:
N → Number of nodes
M → Number of edges
Each of the next M lines defines an undirected edge
K → Number of moments when edges disappear
Each of the next K lines:
ti → Time at which the edge disappears
xi yi → Edge that disappears at time ti

Output Format:
Minimum time to reach node N or -1

Sample Input:
5 5
1 2
2 3
3 5
1 4
4 5
1
1 2 3

Sample output:
2

Explanation:
Start at node 1 at time 0
Path: 1 → 2 → 3 → 5
Edge (2,3) disappears at time = 1
So at time 1, we wait at node 2
Then proceed safely
*/