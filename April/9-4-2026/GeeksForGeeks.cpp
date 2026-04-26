/*
Intersection of Two Sorted Arrays
Given two sorted arrays a[] and b[], where each array may contain duplicate elements, return the elements in the intersection of the two arrays in sorted order.
Note: Intersection of two arrays can be defined as the set containing distinct common elements that are present in both of the arrays.

Examples:
Input: a[] = [1, 1, 2, 2, 2, 4], b[] = [2, 2, 4, 4]
Output: [2, 4]
Explanation: Distinct common elements in both the arrays are: 2 and 4.

Input: a[] = [1, 2], b[] = [3, 4]
Output: []
Explanation: No common elements.

Input: a[] = [1, 2, 3], b[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation: All elements are common.

Constraints:
1 ≤ a.size(), b.size() ≤ 105
-109 ≤ a[i], b[i] ≤ 109
*/

#include <iostream>
#include <vector>
#include<set>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    // code here
    int n = a.size();
    int m = b.size();
    set<int> st;
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            i++;
        }else if(a[i] > b[j]){
            j++;
        }else{
            st.insert(a[i]);
            i++; 
            j++;
        } 
    }
    for(int ele : st){
        ans.push_back(ele);
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector<int> ans = intersection(a, b);
    for(int ele : ans){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}