/*
Print Diagonally
Give a n * n square matrix mat[][], return all the elements of its anti-diagonals from top to bottom.

Examples :
Input: n = 2, mat[][] = 
[
 [1, 2],
 [3, 4]
]
Output: [1, 2, 3, 4]
Explanation: 

Input: n = 3, mat[][] = 
[
 [1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]
]
Output: [1, 2, 4, 3, 5, 7, 6, 8, 9]
Explanation: 

Constraints:
1 ≤ n ≤ 103
0 ≤ mat[i][j] ≤ 106
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> diagView(vector<vector<int>> mat) {
    int n = mat.size();
    vector<int> ans;
    
    for(int col = 0; col < n; col++) {
        int curRow = 0;
        int curCol = col;
        while(curRow < n && curCol >= 0) {
            ans.push_back(mat[curRow][curCol]);
            curRow++;
            curCol--;
        }
    }
    for(int row = 1; row < n; row++) {
        int curRow = row;
        int curCol = n - 1;
        while(curRow < n && curCol >= 0) {
            ans.push_back(mat[curRow][curCol]);
            curRow++;
            curCol--;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    vector<int> result = diagView(mat);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
}