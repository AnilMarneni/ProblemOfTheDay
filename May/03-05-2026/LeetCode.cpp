/*
 * Problem Name: 796. Rotate String
 *
 * Problem Statement:
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 * 
 * Example 1:
 * Input: s = "abcde", goal = "cdeab"
 * Output: true
 * 
 * Example 2:
 * Input: s = "abcde", goal = "abced"
 * Output: false
 * 
 * Constraints:
 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.
 */

#include <iostream>
#include <string>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;
    string check = s + s;
    if(check.find(goal) == -1){
        return false;
    }
    return true;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";
    
    bool result = rotateString(s, goal);
    cout << (result ? "true" : "false") << endl;
    
    return 0;
}
