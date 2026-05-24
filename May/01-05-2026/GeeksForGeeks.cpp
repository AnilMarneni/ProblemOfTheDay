/*
 * Problem Name: Kth Largest in a Stream
 *
 * Problem Statement:
 * Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element) after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion.
 * Return a list of size n, where each element represents the Kth largest value after the corresponding insertion.
 * 
 * Examples :
 * Input: arr[] = [1, 2, 3, 4, 5, 6], k = 4
 * Output: [-1, -1, -1, 1, 2, 3]
 * Explanation:
 * After 1, the steam is [1]. The 4th largest does not exist. Output is -1.
 * After 2, the stream is [1, 2]. The 4th largest does not exist. Output is -1.
 * After 3, the stream is [1, 2, 3]. The 4th largest does not exist. Output is -1.
 * After 4, the stream is [1, 2, 3, 4]. The 4th largest is 1.
 * After 5, the stream is [1, 2, 3, 4, 5]. The 4th largest is 2.
 * After 6, the stream is [1, 2, 3, 4, 5, 6]. The 4th largest is 3.
 * 
 * Input: arr[] = [3, 2, 1, 3, 3], k = 2
 * Output: [-1, 2, 2, 3, 3]
 * Explanation:
 * After 3, the steam is [3]. Tthe 2nd largest does not exist. Output is -1.
 * After 2, the stream is [3, 2]. The 2nd largest is 2.
 * After 1, the stream is [3, 2, 1]. The 2nd largest is 2.
 * After 3, the stream is [3, 2, 1, 3]. The 2nd largest is 3.
 * After 3, the stream is [3, 2, 1, 3, 3]. The 2nd largest is 3.
 * 
 * Constraints:
 * 1 ≤ k ≤ n ≤ 105
 * 1 ≤ arr[i] ≤ 105
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;

    for (int num : arr) {
        minHeap.push(num);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        if (minHeap.size() < k) {
            result.push_back(-1);
        } else {
            result.push_back(minHeap.top());
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 4;
    vector<int> result = kthLargest(arr, k);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
