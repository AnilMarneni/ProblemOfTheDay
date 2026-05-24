/*
 * Problem Name: Max Profit from Two Machines
 *
 * Problem Statement:
 * Given two machines, Machine A and Machine B, and a set of n tasks. The profit earned for performing each task is given in two arrays a[] and b[] such that if Machine A performs the i-th task, the profit is a[i], and if Machine B performs it, the profit is b[i].
 * Machine A can process at most x tasks, and Machine B can process at most y tasks. It is guaranteed that x + y ≥ n, so all tasks can be assigned. Return the maximum possible profit after assigning each task to either Machine A or Machine B.
 * 
 * Examples:
 * Input: x = 3, y = 3, a[] = [1, 2, 3, 4, 5], b[] = [5, 4, 3, 2, 1]
 * Output: 21
 * Explanation: Machine A performs tasks with indices [2, 3, 4], and Machine B performs the rest [0, 1], giving profits (3 + 4 + 5) + (5 + 4) = 21.
 * 
 * Input: x = 4, y = 4, a[] = [1, 4, 3, 2, 7, 5, 9, 6], b[] = [1, 2, 3, 6, 5, 4, 9, 8]
 * Output: 43
 * Explanation: Machine A performs tasks with indices [1, 4, 5, 6], and Machine B performs the rest [0, 2, 3, 7], giving profits (4 + 7 + 5 + 9) + (1 + 3 + 6 + 8) = 43.
 * 
 * Input: x = 3, y = 4, a[] = [8, 7, 15, 19, 16, 16, 18], b[] = [1, 7, 15, 11, 12, 31, 9]
 * Output: 110
 * Explanation: Machine A performs tasks with indices [0, 3, 6], and Machine B performs the rest [1, 2, 4, 5], giving profits (8 + 19 + 18) + (7 + 15 + 12 + 31) = 110.
 * 
 * Constraints:
 * 1 ≤ a.size() == b.size() ≤ 105
 * 1 ≤ x, y ≤ 105
 * 1 ≤ a[i], b[i] ≤ 104
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<pair<int, int>> arr;
    
    for(int i = 0; i < n; i++){
        arr.push_back({abs(a[i] - b[i]), i});
    }
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    
    int ans = 0;
    int cntA = 0;
    int cntB = 0;
    
    for(auto &it : arr){
        int i = it.second;
        if(a[i] >= b[i]){
            if(cntA < x){
                ans += a[i];
                cntA++;
            } else{
                ans += b[i];
                cntB++;
            }
        } else{
            if(cntB < y){
                ans += b[i];
                cntB++;
            } else{
                ans += a[i];
                cntA++;
            }
        }
    }
    return ans;
}

int main() {
    int x = 3, y = 3;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {5, 4, 3, 2, 1};
    cout << maxProfit(x, y, a, b) << endl; // Output: 21
    return 0;
}
