/*
Max Product Subset
Medium
Given an array arr[], find and return the maximum product possible with the subset of elements present in the array.
Note:
The maximum product can be of a single element also.
Since the product can be large, return it modulo 109 + 7.

Examples:
Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24

Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0

Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.

Constraints:
1 ≤ arr.size() ≤ 2 * 104
-10 ≤ arr[i] ≤ 10
*/

#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& arr) {
    int mod = 1e9 + 7;
    int n = arr.size();
    long long product = 1;
    int negativeCount = 0;
    int zeroCount = 0;
    int minNegative = INT_MIN;

    for (int num : arr) {
        if (num < 0) {
            negativeCount++;
            minNegative = max(minNegative, num);
        } else if (num == 0) {
            zeroCount++;
        } else {
            product = (product * num) % mod;
        }
    }

    if (negativeCount % 2 == 0) {
        for (int num : arr) {
            if (num < 0) {
                product = (product * num) % mod;
            }
        }
    } else {
        if (negativeCount == 1 && zeroCount > 0 && product == 1) {
            return 0; // If there's only one negative and at least one zero, the max product is 0
        }
        for (int num : arr) {
            if (num < 0 && num != minNegative) {
                product = (product * num) % mod;
            }
        }
    }

    return product;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxProduct(arr) << endl;
    return 0;
}