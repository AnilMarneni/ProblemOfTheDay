/*
Sorted subsequence of size 3
Given an array arr[], find any subsequence of three elements such that, arr[i] < arr[j] < arr[k] and (i < j < k).
If such a subsequence exists, return the three elements as an array. Otherwise, return an empty array.
Note:
The driver code will print 1 if the returned subsequence is valid and present in the array.
The driver code will print 0 if no such subsequence exists.
If the returned subsequence does not satisfy the required format or conditions, the output will be -1.

Examples :

Input: arr[] = [12, 11, 10, 5, 6, 2, 30]
Output: 1
Explanation: As 5 < 6 < 30, and they  appear in the same sequence in the array. So output is 1.

Input: arr[] = [1, 2, 3, 4]
Output: 1 
Explanation: As the array is sorted, for every i, j, k, where i < j < k, arr[i] < arr[j] < arr[k].So output is 1.

Input: arr[] = [4, 3, 2, 1]
Output: 0
Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> find3Numbers(vector<int> &arr) {
    int n = arr.size();
    if(n < 3) return {};
    int potential_left = INT_MAX;
    int left = INT_MAX;
    int second = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] <= potential_left){
            potential_left = arr[i];
        } else if(arr[i] <= second){
            left = potential_left;
            second = arr[i];
        } else{
            return {left, second, arr[i]};
        }
    }
    return {};
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> ans = find3Numbers(arr);
    if(ans.empty()){
        cout << 0 << endl;
    } else{
        cout << 1 << endl;
    }
}