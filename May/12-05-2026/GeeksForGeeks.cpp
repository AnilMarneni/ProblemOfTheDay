/*
 * Problem Name: Range LCM Queries
 *
 * Problem Statement:
 * Given an array arr[]  and a list of queries queries[][]. Each query can be one of the following two types:
 * Update Query: [1, index, value] --> Update the element at position index in the array to the given value.
 * Range Query: [2, L, R] --> Compute and return the Least Common Multiple (LCM) of all elements in the subarray from index L to R (inclusive).
 * Process all queries sequentially and return a list containing the results of all Type 2 queries.
 * Note: All operations follow 0-based indexing.
 * 
 * Examples :
 * Input: arr[] = [2, 3, 4, 6, 8, 16], queries[][] = [[2, 0, 2], [1, 3, 8], [2, 2, 5]]
 * Output: [12, 16]
 * Explanation: The queries are processed sequentially, updating the array when required.
 * [2, 0, 2]: LCM of [2, 3, 4] = 12
 * [1, 3, 8]: array becomes [2, 3, 4, 8, 8, 16]
 * [2, 2, 5]: LCM of [4, 8, 8, 16] = 16
 * 
 * Input: arr[] = [1, 2, 3, 4],  queries[][] = [[2, 0, 3], [1, 0, 5], [2, 0, 1]]
 * Output: [12, 10]
 * Explanation: The queries are processed sequentially, updating the array when required.
 * [2, 0, 3]: LCM of [1, 2, 3, 4] = 12
 * [1, 0, 5]: array becomes [5, 2, 3, 4]
 * [2, 0, 1]: LCM of [5, 2] = 10
 * 
 * Constraints:
 * 1 ≤ arr.size() ≤ 104
 * 1 ≤ queries.size() ≤ 105
 * 0 ≤ L ≤ R ≤ arr.size() - 1
 * 0 ≤ index ≤ arr.size() - 1
 * 1 ≤ arr[i], value ≤ 104
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

#define ll long long int

ll lcm(ll a, ll b) 
{
    return (a*b)/__gcd(a, b);
}

void build(int node, int start, int end, vector<ll> &segTree, vector<int> &arr) 
{
    if (start == end) {
        segTree[node] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    
    build(2 * node, start, mid, segTree, arr);
    build(2 * node + 1, mid + 1, end, segTree, arr);
    
    segTree[node] = lcm(segTree[2 * node], segTree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, int val, vector<ll> &segTree) {
    if (start == end) 
    {
        segTree[node] = val;
        return;
    }
    
    int mid = (start + end) / 2;
    
    if (idx <= mid)
    {
        update(2 * node, start, mid, idx, val, segTree);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, idx, val, segTree);
    }
    
    segTree[node] = lcm(segTree[2 * node], segTree[2 * node + 1]);
}

long long query(int node, int start, int end, int l, int r, vector<long long> &segTree) {
    if (r<start || end<l)
    {
        return 1;
    }
    
    if (l<=start && end<=r)
    {
        return segTree[node];
    }
    
    int mid = (start + end) / 2;
    
    ll left = query(2 * node, start, mid, l, r, segTree);
    ll right = query(2 * node + 1, mid + 1, end, l, r, segTree);
    
    return lcm(left, right);
}

vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
    // code here
    int n = arr.size();
    vector<ll> segTree(4*n);
    
    build(1, 0, n - 1, segTree, arr);
    vector<ll> ans;
    for (auto &q : queries) 
    {
        if (q[0] == 1) 
        {
            int idx = q[1];
            int val = q[2];
            arr[idx] = val;
            update(1, 0, n - 1, idx, val, segTree);
        }
        else 
        {
            int l = q[1];
            int r = q[2];
            ans.push_back(query(1, 0, n - 1, l, r, segTree));
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 4, 6, 8, 16};
    vector<vector<int>> queries = {{2, 0, 2}, {1, 3, 8}, {2, 2, 5}};
    
    vector<long long> result = RangeLCMQuery(arr, queries);
    
    for (long long res : result) {
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}
