/*
2033. Minimum Operations to Make a Uni-Value Grid
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

Example 1:
Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.

Example 2:
Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.

Example 3:
Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> flattend;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            flattend.push_back(grid[i][j]);
        }
    }
    n = flattend.size();
    int mod = flattend[0] % x;
    for(int i = 0; i < n; i++){
        if(flattend[i] % x != mod){
            return -1;
        }
    }
    sort(flattend.begin(), flattend.end());
    int median = flattend[(n / 2)];
    int ops = 0;
    for(int i = 0; i < n; i++){
        ops += abs(flattend[i] - median) / x;
    }
    return ops;
}

int main() {
    vector<vector<int>> grid1 = {{2,4},{6,8}};
    int x1 = 2;
    cout << minOperations(grid1, x1) << endl; // Output: 4

    vector<vector<int>> grid2 = {{1,5},{2,3}};
    int x2 = 1;
    cout << minOperations(grid2, x2) << endl; // Output: 5

    vector<vector<int>> grid3 = {{1,2},{3,4}};
    int x3 = 2;
    cout << minOperations(grid3, x3) << endl; // Output: -1

    return 0;
}