/*
 * Problem Name: Mother Vertex
 *
 * Problem Statement:
 * Given a directed graph with V vertices labeled from 0 to V-1 and a list of edges edges[][], where each edge is represented as [u, v] indicating a directed edge from vertex u to vertex v, find a Mother Vertex of the graph.
 * A Mother Vertex is a vertex from which all other vertices can be reached.
 * If multiple such vertices exist, return the one with the smallest value.
 * If no such vertex exists, return -1.
 * 
 * Examples:
 * Input: V = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]
 * Output: 0
 * Explanation: Vertices 0, 1, and 2 can each reach all other vertices in the graph. Among them, 0 is the smallest, so the output is 0.
 * 
 * Input: V = 3, edges[][] = [[0, 1], [2, 1]]
 * Output: -1
 * Explanation: No vertex can reach all other vertices in the graph. Hence, there is no Mother Vertex, and the output is -1.
 * 
 * Constraints:
 * 1 ≤ V ≤ 105
 * 1 ≤ edges[i][0], edges[i][1] ≤ V-1
 */

#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    
    for(int nei : adj[node]) {
        if(!vis[nei]) {
            dfs(nei, adj, vis);
        }
    }
}

int findMotherVertex(int V, vector<vector<int>>& edges) {
    
    vector<vector<int>> adj(V);
    
    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]);
    }
    
    vector<int> vis(V, 0);
    
    int candidate = -1;
    
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis);
            candidate = i;
        }
    }
    
    fill(vis.begin(), vis.end(), 0);
    dfs(candidate, adj, vis);
    
    for(int i = 0; i < V; i++) {
        if(!vis[i]) return -1;
    }
    
    int ans = candidate;
    
    for(int i = 0; i < candidate; i++) {
        fill(vis.begin(), vis.end(), 0);
        dfs(i, adj, vis);
        
        bool ok = true;
        
        for(int j = 0; j < V; j++) {
            if(!vis[j]) {
                ok = false;
                break;
            }
        }
        
        if(ok) {
            ans = i;
            break;
        }
    }
    
    return ans;
}

int main() {
    int V = 5;

    vector<vector<int>> edges = {
        {0, 2},
        {0, 3},
        {1, 0},
        {2, 1},
        {3, 4}
    };

    int ans = findMotherVertex(V, edges);

    cout << "Mother Vertex: " << ans << endl;

    return 0;
}
