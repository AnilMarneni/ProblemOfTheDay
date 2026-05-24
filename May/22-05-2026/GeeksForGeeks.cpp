/*
1s Surrounded by 0s
Medium
Given an n × m binary matrix grid[][], find the total count of all cells containing 1 that are unable to move out of the grid through a path of adjacent 1s.
Adjacency means you can only move in four directions: Up, Down, Left, and Right. Diagonal moves are not allowed.
Assume that the space immediately outside the grid is an open path. Any 1 located directly on the outer boundary of the grid (first row, last row, first column, or last column) can immediately step out, and any 1 connected to it can follow and also step out of the grid.

Examples:
Input: grid[][] = [[0, 0, 0, 0],
		[1, 0, 1, 0],
		[0, 1, 1, 0],
		[0, 0, 0, 0]]
Output: 3
Explanation: The highlighted cells represent the land cells.
 
Input: grid[][] = [[1, 1, 0, 0, 0, 1]
		[0, 1, 1, 0, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 1, 0, 1, 0, 0],
		[1, 1, 0, 0, 0, 1]]
Output: 6
Explanation: The highlighted cells represent the land cells.

Constraints:
1 ≤ n, m ≤ 500
0 ≤ grid[i][j] ≤ 1
*/

#include<iostream>
#include<vector>
using namespace std;

int n, m;

void dfs(int i, int j, vector<vector<int>>& grid) {
    
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        return;
    
    grid[i][j] = 0;
    
    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}

int cntOnes(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    
    for(int i = 0; i < n; i++) {
        
        if(grid[i][0] == 1)
            dfs(i, 0, grid);
            
        if(grid[i][m - 1] == 1)
            dfs(i, m - 1, grid);
    }
    
    for(int j = 0; j < m; j++) {
        
        if(grid[0][j] == 1)
            dfs(0, j, grid);
            
        if(grid[n - 1][j] == 1)
            dfs(n - 1, j, grid);
    }
    
    int cnt = 0;    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            if(grid[i][j] == 1)
                cnt++;
        }
    }
    
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << cntOnes(grid) << endl;
    return 0;
}