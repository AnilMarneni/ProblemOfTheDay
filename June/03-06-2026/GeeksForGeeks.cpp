/*
Subarray Frequency Count Queries
Medium
Given an array arr[] of n integers and a 2D array queries[][] representing q queries, where each queries[i] consists of three integers: l, r, and x. For each query determine how many times the element x appears in the arr[] from index l to r (both inclusive).
Return a list of integers where the i-th value represents the answer to the i-th query.

Examples: 
Input: arr[] = [1, 2, 1, 3, 1, 2, 3], queries[][] = [[0, 4, 1], [2, 5, 2], [1, 6, 3], [0, 6, 5]]
Output: [3, 1, 2, 0]
Explanation:
query [0, 4, 1] -> Subarray = [1, 2, 1, 3, 1], 1 appears 3 times
query [2, 5, 2] -> Subarray = [1, 3, 1, 2], 2 appears 1 time
query [1, 6, 3] -> Subarray = [2, 1, 3, 1, 2, 3] 3 appears 2 times
query [0, 6, 5] -> Subarray = [1, 2, 1, 3, 1, 2, 3],  5 appears 0 times

Input: arr[] = [11, 21, 51, 101, 11, 51], queries[][] = [[0, 4, 11], [2, 5, 51]]
Output: [2, 2]
Explanation:
query [0, 4, 11] -> Subarray = [11, 21, 51, 101, 11], 11 appears 2 times
query [2, 5, 51] -> Subarray = [51, 101, 11, 51], 51 appears 2 times

Constraints:
1 ≤ arr.size(), queries.size() ≤ 105
1 ≤ arr[i], queries[i][2] ≤ 105
0 ≤ queries[i][0] ≤ queries[i][1] < arr.size()
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
    unordered_map<int, vector<int>> pos;

    for (int i = 0; i < arr.size(); i++) {
        pos[arr[i]].push_back(i);
    }

    vector<int> ans;

    for (auto &q : queries) {
        int l = q[0];
        int r = q[1];
        int x = q[2];

        if (!pos.count(x)) {
            ans.push_back(0);
            continue;
        }

        auto &v = pos[x];

        int left = lower_bound(v.begin(), v.end(), l) - v.begin();
        int right = upper_bound(v.begin(), v.end(), r) - v.begin();

        ans.push_back(right - left);
    }

    return ans;
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    vector<int> ans = freqInRange(arr, queries);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}