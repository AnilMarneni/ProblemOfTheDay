/*
Check if All Bits Set
Basic
Given a number n, check whether every bit in the binary representation of the given number is set or not.
Return true if yes, otherwise false.

Examples :
Input: n = 7
Output: true
Explanation: Binary for 7 is 111 all the bits are set so the output is true.

Input: n = 8
Output: false
Explanation: Binary for 8 is 1000 all the bits are not set so the output is false.

Input: n = 0
Output: false
Explanation: All the bits are 0 so the output is false.

Constraints:
0 ≤ n ≤ 105
*/

#include<iostream>
using namespace std;

bool checkBits(int n){
    if(n == 0) return false;
    return (n & ( n + 1)) == 0;
}

int main(){
    int n;
    cin>> n;
    cout << (checkBits(n) ? "true" : "false") << endl;
    return 0;
}