/*
3559. Number of Ways to Assign Edge Weights II
Hard
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
Return an array answer, where answer[i] is the number of valid assignments for queries[i].
Since the answer may be large, apply modulo 109 + 7 to each answer[i].
Note: For each query, disregard all edges not in the path between node ui and vi.

Example 1:
Input: edges = [[1,2]], queries = [[1,1],[1,2]]
Output: [0,1]
Explanation:
Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

Example 2:
Input: edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]
Output: [2,1,4]
Explanation:
Query [1,4]: The path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
Query [3,4]: The path from Node 3 to Node 4 consists of one edge (3 → 4). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
Query [2,5]: The path from Node 2 to Node 5 consists of three edges (2 → 1, 1 → 3, and 3 → 5). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.

Constraints:
2 <= n <= 105
edges.length == n - 1
edges[i] == [ui, vi]
1 <= queries.length <= 105
queries[i] == [ui, vi]
1 <= ui, vi <= n
edges represents a valid tree.
*/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

static constexpr int MOD = 1000000007;


vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int n = edges.size() + 1;
    int LOG = 0;
    while ((1 << LOG) <= n) LOG++;

    vector<vector<int>> adj(n + 1);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1);
    vector<vector<int>> up(LOG, vector<int>(n + 1));

    function<void(int, int)> dfs = [&](int u, int p) {
        up[0][u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    };

    dfs(1, 0);

    for (int k = 1; k < LOG; k++) {
        for (int v = 1; v <= n; v++) {
            up[k][v] = up[k - 1][up[k - 1][v]];
        }
    }

    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k)) a = up[k][a];
        }

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return up[0][a];
    };

    vector<long long> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    vector<int> ans;
    for (auto &q : queries) {
        int u = q[0], v = q[1];

        int p = lca(u, v);
        int d = depth[u] + depth[v] - 2 * depth[p];

        if (d == 0) ans.push_back(0);
        else ans.push_back(pow2[d - 1]);
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> ans = assignEdgeWeights(edges, queries);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}