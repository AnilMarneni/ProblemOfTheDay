/*
Count Derangements
Given a number n, find the total number of Derangements of elements from 1 to n. A Derangement is a permutation of n elements, such that no element appears in its original position, i.e., 1 should not be the first element, 2 should not be second, etc. For example, [5, 3, 2, 1, 4] is a Derangement of first 5 elements.
Note: The answer will always fit into a 32-bit integer.

Examples:
Input: n = 2
Output: 1
Explanation: For [1, 2], there is only one possible derangement: [2, 1].

Input: n = 3
Output: 2
Explanation: For the set [1, 2, 3], there are only two possible derangements: [2, 3, 1] and [3, 1, 2].

Constraints:
1 ≤ n ≤ 12
*/

#include<iostream>
#include<vector>
using namespace std;

int derangeCount(int n) {
    int mod = 10e9 + 7;
    if(n == 1) return 0;
    if(n == 2) return 1;
    
    int a = 0;
    int b = 1;
    for(int i = 3; i <= n; i++){
        int c = (i - 1) * (a + b) % mod;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 3;
    cout << derangeCount(n) << endl; // Output: 2
}