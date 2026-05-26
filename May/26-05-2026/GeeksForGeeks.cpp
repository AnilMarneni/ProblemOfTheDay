/*
Minimum Toggle to Partition
Easy
Given an array arr[] containing only 0 and 1. Find the minimum toggles (switch from 0 to 1 or vice-versa) required such the array become partitioned, i.e., it has first 0s then 1s.

Examples:
Input: arr = [1, 0, 1, 1, 0]
Output: 2
Explaination: The changed array will be [0, 0, 1, 1, 1]. So the number of toggles here required is 2.

Input: arr = [0, 1, 0, 0, 1, 1, 1]
Output: 1
Explaination: The changed array will be [0, 0, 0, 0, 1, 1, 1]. Required toggles are 1.

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 1
*/

#include<iostream>
#include<vector>
using namespace std;

int minToggle(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> prefixOnes(n+1, 0);
    for(int i = 0; i < n; i++) {
        prefixOnes[i+1] = prefixOnes[i] + (arr[i] == 1);
    }
    
    vector<int> suffixZeros(n+1, 0);
    for(int i = n-1; i >= 0; i--) {
        suffixZeros[i] = suffixZeros[i+1] + (arr[i] == 0);
    }
    
    int ans = n;
    for(int i = 0; i <= n; i++) {
        int flips = prefixOnes[i] + suffixZeros[i];
        ans = min(ans, flips);
    }
    
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << minToggle(arr) << endl;
    return 0;
}