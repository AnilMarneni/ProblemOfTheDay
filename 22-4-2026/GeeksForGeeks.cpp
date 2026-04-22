/*
Mean of range in array
Given an integer array arr[] and a 2D array queries[][]. Each query queries[i] = [l, r] represents a subarray ranging from index l to r (inclusive). For every query, compute the mean (average) of the elements in the specified range, and return the floor value of that mean.
Return an array where each element corresponds to the result of a query.

Examples:
Input: arr[] = [1, 2, 3, 4, 5], queries[][] = [[0, 2], [1, 3], [0, 4]]
Output: [2, 3, 3]
Explanation: The array is [1, 2, 3, 4, 5].
Query 1: l = 0, r = 2 → subarray [1, 2, 3] → sum = 6 → mean = 6/3 = 2
Query 2: l = 1, r = 3 → subarray [2, 3, 4] → sum = 9 → mean = 9/3 = 3
Query 3: l = 0, r = 4 → subarray [1, 2, 3, 4, 5] → sum = 15 → mean = 15/5 = 3
Hence the answer is [2, 3, 3]

Input: arr[] = [6, 7, 8, 10], queries[][] = [[0, 3], [1, 2]]
Output: [7, 7]
Explanation: The array is [6, 7, 8, 10].
Query 1: l = 0, r = 3 → subarray [6, 7, 8, 10] → sum = 31 → mean = 31/4 = 7 (floor value)
Query 1: l = 1, r = 2 → subarray [7, 8] → sum = 15 → mean = 15/2 = 7 (floor value)
Hence the answer is [7, 7]

Constraints: 
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 103
1 ≤ queries.size() ≤ 105
1 ≤ queries[i][0] ≤ queries[i][1] < arr.size()
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
    int n = queries.size();
    int m = arr.size();
    vector<int> prefix(m + 1, 0);
    for(int i = 0; i < m; i++){
        prefix[i + 1] = prefix[i] + arr[i];
    }
    vector<int> ans;
    for(vector<int> query : queries){
        int lft = query[0];
        int rgt = query[1];
        int curSum = prefix[rgt + 1] - prefix[lft];
        int avg = curSum / (rgt - lft + 1);
        ans.push_back(avg);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> queries = {{0, 2}, {1, 3}, {0, 4}};
    vector<int> result = findMean(arr, queries);
    for (int mean : result) {
        cout << mean << " ";
    }
    cout << endl;
    return 0;
}