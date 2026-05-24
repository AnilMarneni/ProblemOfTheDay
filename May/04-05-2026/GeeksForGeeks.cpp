/*
 * Problem Name: Palindrome Binary
 *
 * Problem Statement:
 * Given an integer n, determine whether its binary representation forms a palindrome. Return true if the binary representation of n is a palindrome; otherwise, return false.
 * Note: A binary representation is considered a palindrome if it reads the same forward and backward.
 * 
 * Examples:
 * Input: n = 17
 * Output: true
 * Explanation: Binary representation of 17 is (10001)2, which reads the same forward and backward, so it is a palindrome.
 * 
 * Input: n = 16
 * Output: false
 * Explanation: Binary representation of 16 is (10000)2, which is not a palindrome.
 * 
 * Constraints:
 * 1 ≤ n ≤ 109
 * 
 * Expected Complexities
 * Time Complexity: O(log n)
 * Auxiliary Space: O(1)
 */

#include <iostream>
using namespace std;    

bool isBinaryPalindrome(int n) {
    long long temp = n;
    long long rev = 0;
    while(temp){
        if(temp & 1){
            rev |= 1;
        }
        temp >>= 1;
        if(temp){
            rev <<= 1;
        }
    }
    return n == rev;
}

int main() {
    int n = 17;
    
    bool result = isBinaryPalindrome(n);
    cout
