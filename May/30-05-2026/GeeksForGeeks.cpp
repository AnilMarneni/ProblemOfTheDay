/*
Replace with XOR of Adjacent
Easy
Given an array arr[] of n integers, modify the array in-place such that each element is replaced with the XOR of its adjacent elements.
For the first element, update arr[0] = arr[0] ^ arr[1].
For the last element, update arr[n-1] = arr[n-2] ^ arr[n-1].
For all other elements, update arr[i] = arr[i-1] ^ arr[i+1].
Note: Here, a ^ b represents the XOR operation between a and b. 

Examples :
Input : arr[] = [2, 1, 4, 7]
Output : [3, 6, 6, 3]
Explanation:
At index 0, arr[0] ^ arr[1] = 2 ^ 1 = 3
At index 1, arr[0] ^ arr[2] = 2 ^ 4 = 6
At index 2, arr[1] ^ arr[3] = 1 ^ 7 = 6
At index 3, arr[2] ^ arr[3] = 4 ^ 7 = 3
Thus, the updated array becomes [3, 6, 6, 3].

Input : arr[] = [5, 9, 2, 6, 7]
Output: [12, 7, 15, 5, 1]
Explanation:
At index 0, arr[0] ^ arr[1] = 5 ^ 9 = 12
At index 1, arr[0] ^ arr[2] = 5 ^ 2 = 7
At index 2, arr[1] ^ arr[3] = 9 ^ 6 = 15
At index 3, arr[2] ^ arr[4] = 2 ^ 7 = 5
At index 4, arr[3] ^ arr[4] = 6 ^ 7 = 1
Thus, the updated array becomes [12, 7, 15, 5, 1]. 

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ 107
*/

#include<iostream>
#include<vector>
using namespace std;

void replaceElements(vector<int>& arr) {
    int n = arr.size();

    int prev = arr[0];
    arr[0] ^= arr[1];

    for (int i = 1; i < n - 1; i++) {
        int cur = arr[i];
        arr[i] = prev ^ arr[i + 1];
        prev = cur;
    }

    arr[n - 1] = prev ^ arr[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    replaceElements(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}