/*
Common in 3 Sorted Arrays
Given three sorted arrays in non-decreasing order, return all common elements in non-decreasing order across these arrays. If there are no such elements return an empty array.

Examples :
Input: a[] = [1, 5, 10, 20, 40, 80], b[] = [6, 7, 20, 80, 100], c[] = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: The elements 20 and 80 appear in all three arrays a, b, and c, making them the only common elements, so the output is [20, 80].

Input: a[] = [1, 2, 3, 4, 5], b[] = [6, 7], c[] = [8, 9, 10]
Output: []
Explanation: Since none of the elements in arrays a, b, and c appear in all three arrays, there are no common elements, so the output is [].

Input:  a[] = [1, 1, 1, 2, 2, 2], b[] = [1, 1, 2, 2, 2], c[] = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Ignoring duplicates, 1 and 2 are present in all three arrays, so the output is [1, 2].

Constraints:
1 ≤ a.size(), b.size(), c.size() ≤ 105
-105 ≤ a[i], b[i] , c[i] ≤ 105
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n = a.size();
    int m = b.size();
    int l = c.size();
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while(i < n && j < m && k < l){
        if(a[i] == b[j] && b[j] == c[k]){
            ans.push_back(a[i]);
            int curr = a[i];
            while(i < n && a[i] == curr) i++;
            while(j < m && b[j] == curr) j++;
            while(k < l &&c[k] == curr) k++;
        } else{
            int mini = min({a[i], b[j], c[k]});
            while(i < n && a[i] == mini) i++;
            while(j < m && b[j] == mini) j++;
            while(k < l && c[k] == mini) k++;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 5, 10, 20, 40, 80};
    vector<int> b = {6, 7, 20, 80, 100};
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> result = commonElements(a, b, c);

    cout << "Common elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}