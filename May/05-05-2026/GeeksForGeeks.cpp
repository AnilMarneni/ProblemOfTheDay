/*
 * Problem Name: Sum of XOR of all pairs
 *
 * Problem Statement:
 * Given an integer array arr[] of size n, compute the sum of the bitwise XOR for all distinct pairs of elements. That is, consider every pair of indices (i, j) such that 0 ≤ i < j < n, and calculate the total sum of (arr[i] XOR arr[j]) over all such pairs.
 * 
 * Examples :
 * Input : arr[] = [7, 3, 5]
 * Output : 12
 * Explanation:
 * All pairs (i, j) such that i < j and their XOR values are:
 * 7 ^ 3 = 4
 * 7 ^ 5 = 2
 * 3 ^ 5 = 6
 * Sum of all XOR values = 4 + 2 + 6 = 12.
 * 
 * Input : arr[] = [5, 9, 7, 6]
 * Output : 47
 * Explanation:
 * All pairs (i, j) such that i < j and their XOR values are:
 * 5 ^ 9 = 12
 * 5 ^ 7 = 2
 * 5 ^ 6 = 3
 * 9 ^ 7 = 14
 * 9 ^ 6 = 15
 * 7 ^ 6 = 1
 * Sum of all XOR values = 12 + 2 + 3 + 14 + 15 + 1 = 47.
 * 
 * Input : arr[] = [10]
 * Output : 0
 * Explanation: Since there are no pairs, sum is 0.
 * 
 * Constraints
 * 1 ≤ n ≤ 105
 * 1 ≤ arr[i] ≤ 105
 */

#include <iostream>
#include <vector>
using namespace std;

long long sumXOR(vector<int> &arr) {
    int n = arr.size();
    long long ans = 0;
    
    for(int bit = 0; bit < 32; bit++){
        long long ones = 0;
        long long zeros = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] & ( 1 << bit)){
                ones++;
            } else{
                zeros++;
            }
        }
        ans += ones * zeros * (1LL << bit);
    }
    return ans;
}

int main() {
    vector<int> arr = {7, 3, 5};
    
    long long result = sumXOR(arr);
    cout << result << endl; // Output: 12
    return 0;
}
