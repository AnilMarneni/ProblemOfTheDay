/*
Segregate 0s and 1s
Given an array arr[] consisting of only 0's and 1's. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :
Input: arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 0, 0, 1, 1, 1, 1, 1].

Input: arr[] = [1, 1]
Output: [1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1]

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 1
*/

#include <iostream>
#include <vector>
using namespace std;

void segregate0and1(vector<int> &arr) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while(l < r){
        while(l < n && arr[l] == 0){
            l++;
        }
        while(r >= 0 && arr[r] == 1){
            r--;
        }
        if(l < r){
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    segregate0and1(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}