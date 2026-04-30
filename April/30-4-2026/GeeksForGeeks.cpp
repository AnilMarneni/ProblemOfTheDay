/*
Check if an Array is Max Heap
Given an array arr[], determine whether it represents the level-order traversal of a valid max heap. Return true if it does; otherwise, return false.

Examples :
Input: arr[] = [90, 15, 10, 7, 12, 2]
Output: true
Explanation: The given array represents the following tree. Each parent node is greater than or equal to its children, so the max-heap property holds.
 
Input: arr[] = [9, 15, 10, 7, 12, 11]
Output: false
Explanation: The given array represents the following tree. It does not satisfy the max-heap property, as 9 is smaller than 15 and 10, and 10 is smaller than 11.
 
Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105
*/

#include <iostream>
#include <vector>
using namespace std;

bool isMaxHeap(vector<int> &arr) {
    int n = arr.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        if(left < n && arr[i] < arr[left]) return false;
        if(right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

int main() {
    vector<int> arr1 = {90, 15, 10, 7, 12, 2};
    vector<int> arr2 = {9, 15, 10, 7, 12, 11};
    
    cout << isMaxHeap(arr1) << endl; // Output: true
    cout << isMaxHeap(arr2) << endl; // Output: false
    
    return 0;
}