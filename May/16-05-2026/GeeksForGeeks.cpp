/*
 * Problem Name: Not a subset sum
 *
 * Problem Statement:
 * Given a array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.
 * 
 * Examples:
 * Input: arr[] = [3, 1, 2]
 * Output: 7
 * Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
 * 
 * Input: arr[] = [3, 10, 9, 6, 20, 28]
 * Output: 1
 * Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
 * 
 * Constraints
 * 1 ≤ arr.size() ≤ 105
 * 1 ≤ arr[i] ≤ 103
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findSmallest(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    long long reachable = 0;

    for (int x : arr) {
        if (x > reachable + 1)
            return reachable + 1;

        reachable += x;
    }

    return reachable + 1;
}

int main() {
    vector<int> arr = {1, 2, 3, 8, 9, 10};

    cout << "Smallest non-representable value: "
         << findSmallest(arr) << endl;

    return 0;
}
