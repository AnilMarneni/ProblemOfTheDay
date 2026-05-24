/*
 * Problem Name: 1861. Rotating the Box
 *
 * Problem Statement:
 * You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:
 * A stone '#'
 * A stationary obstacle '*'
 * Empty '.'
 * The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
 * It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.
 * Return an n x m matrix representing the box after the rotation described above.
 * 
 * Example 1:
 * Input: boxGrid = [["#",".","#"]]
 * Output: [["."],
 * ["#"],
 * ["#"]]
 * 
 * Example 2:
 * Input: boxGrid = [["#",".","*","."],
 * ["#","#","*","."]]
 * Output: [["#","."],
 * ["#","#"],
 * ["*","*"],
 * [".","."]]
 * 
 * Example 3:
 * Input: boxGrid = [["#","#","*",".","*","."],
 * ["#","#","#","*",".","."],
 * ["#","#","#",".","#","."]]
 * Output: [[".","#","#"],
 * [".","#","#"],
 * ["#","#","*"],
 * ["#","*","."],
 * ["#",".","*"],
 * ["#",".","."]]
 * 
 * Constraints:
 * m == boxGrid.length
 * n == boxGrid[i].length
 * 1 <= m, n <= 500
 * boxGrid[i][j] is either '#', '*', or '.'.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();

    vector<vector<char>> result(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result[i][j] = box[j][i];
        }
    }

    for(vector<char>& row : result) {
        reverse(begin(row), end(row));
    }

    for(int j = 0; j < m; j++) {
        int spaceBottomRow = n-1;
        for(int i = n-1; i >= 0; i--) {
            if(result[i][j] == '*') {
                spaceBottomRow = i-1;
                continue;
            }

            if(result[i][j] == '#') {
                result[i][j] = '.';
                result[spaceBottomRow][j] = '#';
                spaceBottomRow--;
            }
        }
    }

    return result;
}

int main() {
    vector<vector<char>> boxGrid = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };

    vector<vector<char>> result = rotateTheBox(boxGrid);

    for (const auto& row : result) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
