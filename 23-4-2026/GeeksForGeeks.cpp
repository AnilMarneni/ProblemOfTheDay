/*
Two Equal Sum Subarrays
Given an array of integers arr[], return true if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. If it is not possible then return false.

Examples:
Input: arr[] = [1, 2, 3, 4, 5, 5]
Output: true
Explanation: We can divide the array into [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10.

Input: arr[] = [4, 3, 2, 1]
Output: false
Explanation: We cannot divide the array into two subarrays with equal sum.

Constraints:
1 ≤ arr.size() ≤ 105 
1 ≤ arr[i] ≤ 106
*/

#include <iostream>
#include <vector>
using namespace std;

bool canSplit(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    vector<int> suffixSum(n, 0);
    
    prefixSum[0] = arr[0];
    for(int i = 0; i < n - 1; i++){
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    suffixSum[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    }
    for(int i = 0; i < n - 1; i++){
        if(prefixSum[i] == suffixSum[i + 1]) return true;
    }
    return false;
}

int main(){
    int n = 6;
    vector<int> vec = {1, 2, 3, 4, 5, 5};
    cout << canSplit(vec) << endl;
    return 0;
}