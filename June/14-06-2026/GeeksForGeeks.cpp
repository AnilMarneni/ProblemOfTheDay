/*
Exit Point in a Matrix
Medium
Given a matrix mat[][] of size n × m consisting of 0s and 1s. You start at the top-left cell (0, 0). Initially, you are positioned at (0, 0) and facing right (toward (0, 1)). Before each move, apply the rules based on the value of the current cell:
If the current cell contains 0, continue moving in the same direction.
If the current cell contains 1, change your direction to the right (clockwise turn), and update the cell value to 0.
You continue this process until you move outside the boundaries of the matrix. Determine the coordinates (row and column index) of the cell from which you exit the matrix.

Examples:
Input: mat[][] = [[0, 1, 0],
               [0, 1, 1], 
               [0, 0, 0]]
Output: [1, 0]
Explanation: 
From the image we can see that, enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed. Hence, exit point reached at [1, 0].

Input: mat[][] = [[1, 1],
                 [0, 1]]
Output: [1, 0]
Explanation:
Enter the matrix at (0, 0) facing right
-> 1 is encountered at (0, 0)
-> turn right and move to (1, 0)
-> 0 is encountered at (1, 0)
-> continue moving down and cross the matrix boundary. Hence, the exit point is reached at [1, 0].

Constraints:
1 ≤ n, m ≤ 100
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> exitPoint(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = 0;
    int dir = 0;

    while (i >= 0 && i < n && j >= 0 && j < m) {
        if (mat[i][j] == 1) {
            dir = (dir + 1) % 4;
            mat[i][j] = 0;
        }

        if (dir == 0) j++;
        else if (dir == 1) i++;
        else if (dir == 2) j--;
        else i--;
    }

    if (i < 0) i = 0;
    else if (i == n) i = n - 1;

    if (j < 0) j = 0;
    else if (j == m) j = m - 1;

    return {i, j};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    vector<int> result = exitPoint(mat);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}