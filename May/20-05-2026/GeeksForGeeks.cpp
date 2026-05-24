/*
 * Problem Name: Product Pair
 *
 * Problem Statement:
 * Given an integer array arr[] and an integer target, determine whether there exists a pair of elements in the array whose product is equal to target.
 * Return true if such a pair exists; otherwise, return false.
 * Examples:
 * Input: arr[] = [10, 20, 9, 40], target = 400
 * Output: true
 * Explanation: As 10 * 40 = 400, the answer is true.
 * Input: arr[] = [-10, 20, 9, -40], target = 30
 * Output: false
 * Explanation: No pair exists with product 30.
 * Input: arr[] = [-10, 0, 9, -40], target = 0
 * Output: true
 * Explanation: As -10 * 0 = 0, the answer is true.
 * Constraints:
 * 2 ≤ arr.size ≤ 105
 * -108 ≤ arr[i] ≤ 108
 * -1018 ≤ target ≤ 1018
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isProduct(vector<int>& arr, long long target) {
    unordered_set<long long> seen;
    int zeroCount = 0;

    for (long long x : arr) {
        if (x == 0) {
            zeroCount++;
            if (target == 0 && zeroCount >= 2) return true;
        } else {
            if (target % x == 0) {
                long long need = target / x;
                if (seen.find(need) != seen.end()) return true;
            }
        }
        seen.insert(x);
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    if(isProduct(arr, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
