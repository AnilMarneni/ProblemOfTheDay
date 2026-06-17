/*
Cut rope to maximise product
Medium
Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.

Examples:
Input: n = 2
Output: 1
Explanation: Since 1 cut is mandatory. Maximum obtainable product is 1 * 1 = 1.

Input: n = 5
Output: 6
Explanation: Maximum obtainable product is 2 * 3 = 6.

Constraints:
2 ≤ n ≤ 58
*/

#include <iostream>
using namespace std;

int maxProduct(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;

    long long ans = 1;

    while (n > 4) {
        ans *= 3;
        n -= 3;
    }

    return ans * n;
}

int main() {
    int n;
    cin >> n;
    int result = maxProduct(n);
    cout << result << endl;
    return 0;
}