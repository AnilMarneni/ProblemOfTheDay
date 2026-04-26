/*
Partitions with Given Difference

Given an array arr[] and an integer diff, count the number of ways to partition the array into two subsets such that the difference between their sums is equal to diff.

Note: A partition in the array means dividing an array into two subsets say S1 and S2 such that the union of S1 and S2 is equal to the original array and each element is present in only one of the subsets.

Examples :
Input: arr[] = [5, 2, 6, 4], diff = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : [6, 4], [5, 2]. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

Input: arr[] = [1, 1, 1, 1], diff = 0 
Output: 6 
Explanation: We can choose two 1's from indices [0,1], [0,2], [0,3], [1,2], [1,3], [2,3] and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 

Input: arr[] = [3, 2, 7, 1], diff = 4  
Output: 0
Explanation: There is no possible partition of the array that satisfy the given difference. 

Constraint:
1 ≤ arr.size() ≤ 50
0 ≤ diff ≤ 50
0 ≤ arr[i] ≤ 6
*/

#include <iostream>
#include <vector>
using namespace std;

int countPartitions(vector<int>& arr, int diff) {
    int totalSum = 0;
    for (int x : arr) totalSum += x;

    if ((totalSum + diff) % 2 != 0) return 0;

    int target = (totalSum + diff) / 2;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num : arr) {
        for (int j = target; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[target];
}

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int diff = 3;
    cout << countPartitions(arr, diff) << endl; // Output: 1
    return 0;
}