/*
Consecutive 1's not allowed
Medium
Given a positive integer n, count all possible distinct binary strings of length n such that there are no consecutive 1’s.

Examples :
Input: n = 3
Output: 5
Explanation: 5 strings are ("000", "001", "010", "100", "101").

Input: n = 2
Output: 3
Explanation: 3 strings are ("00", "01", "10").

Input: n = 1
Output: 2

Constraints:
1 ≤ n ≤ 44
*/

#include<iostream>
using namespace std;

int countStrings(int n) {
    long long zero = 1;
    long long one = 1;

    for(int i = 2; i <= n; i++) {
        long long newZero = zero + one;
        long long newOne = zero;

        zero = newZero;
        one = newOne;
    }

    return zero + one;
}

int main(){
    int n;
    cin >> n;
    cout << countStrings(n) << endl;
    return 0;
}