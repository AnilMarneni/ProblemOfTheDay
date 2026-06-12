/*
3558. Number of Ways to Assign Edge Weights I
Medium
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
Since the answer may be large, return it modulo 109 + 7.
Note: Ignore all edges not in the path from node 1 to x.

Example 1:
Input: edges = [[1,2]]
Output: 1
Explanation:
The path from Node 1 to Node 2 consists of one edge (1 → 2).
Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

Example 2:
Input: edges = [[1,2],[1,3],[3,4],[3,5]]
Output: 2
Explanation:
The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
For example, the path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4).
Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.

Constraints:
2 <= n <= 105
edges.length == n - 1
edges[i] == [ui, vi]
1 <= ui, vi <= n
edges represents a valid tree.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static constexpr int MOD = 1e9 + 7;

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int assignEdgeWeights(vector<vector<int>>& edges) {
    int n = edges.size() + 1;

    vector<vector<int>> g(n + 1);
    for (auto &e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    queue<int> q;
    vector<int> depth(n + 1, -1);

    q.push(1);
    depth[1] = 0;

    int mxDepth = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                mxDepth = max(mxDepth, depth[v]);
                q.push(v);
            }
        }
    }

    return (int)modPow(2, mxDepth - 1);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << assignEdgeWeights(edges) << endl;
    return 0;
}