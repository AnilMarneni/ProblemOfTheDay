/*
Binary Strings with Equal Sum of Two Halves
Medium
Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits. 
Note: Since the anwer can be very large, so return the answer modulo 109+7.

Examples:
Input: n = 2
Output: 6
Explanation: There are 6 sequences of length 2*n, the sequences are 0101, 0110, 1010, 1001, 0000 and 1111.

Input: n = 1
Output: 2
Explanation: There are 2 sequence of length 2*n, the sequence are 00 and 11. 

Constraints:
1 ≤ n ≤ 105
*/

#include <iostream>
#include <vector>
using namespace std;

static const int MOD = 1000000007;

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int computeValue(int n) {
    vector<long long> fact(2 * n + 1);

    fact[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    long long ans = fact[2 * n];
    ans = ans * power(fact[n], MOD - 2) % MOD;
    ans = ans * power(fact[n], MOD - 2) % MOD;

    return (int)ans;
}

int main() {
    int n;
    cin >> n;
    cout << computeValue(n) << endl;
    return 0;
}