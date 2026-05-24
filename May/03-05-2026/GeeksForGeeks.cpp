/*
 * Problem Name: Sort by Set Bit Count
 *
 * Problem Statement:
 * Given an array arr[] of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements.
 * Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.
 * 
 * Examples:
 * Input: arr[] = [5, 2, 3, 9, 4, 6, 7, 15, 32]
 * Output: [15, 7, 5, 3, 9, 6, 2, 4, 32]
 * Explanation: The integers in their binary representation are:
 * 15 - 1111
 * 7  - 0111
 * 5  - 0101
 * 3  - 0011
 * 9  - 1001
 * 6  - 0110
 * 2  - 0010
 * 4  - 0100
 * 32 - 10000
 * hence the non-increasing sorted order is: [15], [7], [5, 3, 9, 6], [2, 4, 32]
 * 
 * Input: arr[] = [1, 2, 3, 4, 5, 6]
 * Output: [3, 5, 6, 1, 2, 4]
 * Explanation: The integers in their binary representation are:
 * 3  - 0011
 * 5  - 0101
 * 6  - 0110
 * 1  - 0001
 * 2  - 0010
 * 4  - 0100
 * hence the non-increasing sorted order is: [3, 5, 6], [1, 2, 4]
 * 
 * Constraints:
 * 1 ≤ arr.size() ≤ 105
 * 1 ≤ arr[i] ≤ 106
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortBySetBitCount(vector<int>& arr) {
    stable_sort(arr.begin(), arr.end(), [](int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    });
    return arr;
}

int main() {
    vector<int> arr = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    vector<int> sortedArr = sortBySetBitCount(arr);
    
    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
