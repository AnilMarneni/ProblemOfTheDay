/*
 * Problem Name: Count Spanning Trees in a Graph
 *
 * Problem Statement:
 * Given a connected undirected graph with n vertices and m edges, where each edge is represented as edges[i]=[u,v]  indicating an edge between vertices u and v.
 * Determine the total number of distinct spanning trees that can be formed from the graph.
 * Note: A spanning tree is a subgraph of the given graph that includes all n vertices, has exactly n-1 edges, is connected, and contains no cycles; therefore, every connected undirected graph always has at least one spanning tree.
 * 
 * Examples:
 * Input: n = 6, edges = [[0, 3], [0, 1], [1, 2], [1, 5], [3, 4]]
 * Output: 1
 * Explanation: The graph has 6 vertices and 5 edges, and it is connected, so it is already a tree (m = n-1). A tree has only one spanning tree, which is the graph itself, so the answer is 1.
 * 
 * Input: n = 3, edges = [[0, 1], [0, 2], [1, 2]]
 * Output: 3
 * Explanation: There are exactly 3 possible spanning trees for the given graph.
 * 
 * Input: n = 1, edges = []
 * Output: 1
 * Explanation: With 1 vertex, a spanning tree needs 0 edges. The graph already satisfies this, so the answer is 1.
 * 
 * Constraints:
 * 1 ≤ n ≤ 10
 * n -1  ≤ m ≤ n*(n-1)/2
 * 0 ≤ edges[i][0], edges[i][1] ≤ n-1
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

long long determinant(vector<vector<double>> mat, int n) {
    double det = 1;

    for (int i = 0; i < n; i++) {

        int pivot = i;
        for (int j = i; j < n; j++) {
            if (fabs(mat[j][i]) > fabs(mat[pivot][i]))
                pivot = j;
        }

        if (fabs(mat[pivot][i]) < 1e-9)
            return 0;

        if (i != pivot) {
            swap(mat[i], mat[pivot]);
            det *= -1;
        }

        det *= mat[i][i];

        for (int j = i + 1; j < n; j++) {
            double factor = mat[j][i] / mat[i][i];

            for (int k = i; k < n; k++) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    return round(det);
}

int countSpanTree(int n, vector<vector<int>>& edges) {

    if (n == 1) return 1;

    vector<vector<double>> lap(n, vector<double>(n, 0));

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];

        lap[u][u]++;
        lap[v][v]++;

        lap[u][v]--;
        lap[v][u]--;
    }

    vector<vector<double>> cof(n - 1, vector<double>(n - 1));

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            cof[i][j] = lap[i][j];
        }
    }

    return determinant(cof, n - 1);
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {{0, 3}, {0, 1}, {1, 2}, {1, 5}, {3, 4}};
    cout << countSpanTree(n, edges) << endl; // Output: 1

    n = 3;
    edges = {{0, 1}, {0, 2}, {1, 2}};
    cout << countSpanTree(n, edges) << endl; // Output: 3

    n = 1;
    edges = {};
    cout << countSpanTree(n, edges) << endl; // Output: 1

    return 0;
}
