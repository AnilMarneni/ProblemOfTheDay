/*
 * Problem Name: 1345. Jump Game IV
 *
 * Problem Statement:
 * Given an array of integers arr, you are initially positioned at the first index of the array.
 * In one step you can jump from index i to index:
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * Return the minimum number of steps to reach the last index of the array.
 * Notice that you can not jump outside of the array at any time.
 * 
 * Example 1:
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
 * 
 * Example 2:
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You do not need to jump.
 * 
 * Example 3:
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 * 
 * Constraints:
 * 1 <= arr.length <= 5 * 104
 * -108 <= arr[i] <= 108
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }

    queue<int> q;
    vector<bool> vis(n, false);

    q.push(0);
    vis[0] = true;

    int steps = 0;

    while (!q.empty()) {

        int sz = q.size();

        while (sz--) {

            int i = q.front();
            q.pop();

            if (i == n - 1)
                return steps;

            // Same value jumps
            for (int nei : mp[arr[i]]) {
                if (!vis[nei]) {
                    vis[nei] = true;
                    q.push(nei);
                }
            }

            // Left jump
            if (i - 1 >= 0 && !vis[i - 1]) {
                vis[i - 1] = true;
                q.push(i - 1);
            }

            // Right jump
            if (i + 1 < n && !vis[i + 1]) {
                vis[i + 1] = true;
                q.push(i + 1);
            }

            // Optimization
            mp[arr[i]].clear();
        }

        steps++;
    }

    return -1;
}

int main() {

    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    cout << minJumps(arr);

    return 0;
}
