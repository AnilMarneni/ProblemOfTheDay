/*
3742. Maximum Path Score in a Grid
You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.
You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.
Each cell contributes a specific score and incurs an associated cost, according to their cell values:
0: adds 0 to your score and costs 0.
1: adds 1 to your score and costs 1.
2: adds 2 to your score and costs 1. ​​​​​​​
Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.
Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

Example 1:
Input: grid = [[0, 1],[2, 0]], k = 1
Output: 2
Explanation:​​​​​​​
The optimal path is:
Cell	grid[i][j]	Score	Total
Score	Cost	Total
Cost
(0, 0)	0	0	0	0	0
(1, 0)	2	2	2	1	1
(1, 1)	0	0	2	0	1
Thus, the maximum possible score is 2.

Example 2:
Input: grid = [[0, 1],[1, 2]], k = 1
Output: -1
Explanation:
There is no path that reaches cell (1, 1)​​​​​​​ without exceeding cost k. Thus, the answer is -1.

Constraints:
1 <= m, n <= 200
0 <= k <= 103​​​​​​​
​​​​​​​grid[0][0] == 0
0 <= grid[i][j] <= 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int help(vector<vector<int>>& grid, int n, int m, int i, int j, int cost, int k, vector<vector<vector<int>>>& dp){
    if(i >= n || j >= m) return INT_MIN;
    int newCost = cost + (grid[i][j] > 0);
    if(newCost > k) return INT_MIN;
    if(i == n - 1 && j == m - 1) return grid[i][j];
    if(dp[i][j][newCost] != -1) return dp[i][j][newCost];

    int right = help(grid, n, m, i + 1, j, newCost, k, dp);
    int down = help(grid, n, m, i, j + 1, newCost, k, dp);
    int best = max(right, down);
    if(best == INT_MIN) return dp[i][j][newCost] = INT_MIN;
    return dp[i][j][newCost] = best + grid[i][j];
}

int maxPathScore(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    int res = help(grid, n, m, 0, 0, 0, k, dp);
    return res == INT_MIN ? -1 : res;
}

int main() {
    vector<vector<int>> grid1 = {{0, 1}, {2, 0}};
    int k1 = 1;
    cout << maxPathScore(grid1, k1) << endl; // Output: 2

    vector<vector<int>> grid2 = {{0, 1}, {1, 2}};
    int k2 = 1;
    cout << maxPathScore(grid2, k2) << endl; // Output: -1

    return 0;
}