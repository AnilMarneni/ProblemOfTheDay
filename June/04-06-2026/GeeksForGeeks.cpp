/*
Substring with Max Zero-One Diff
Medium
Given a binary string s consisting of 0s and 1s. Find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in a substring of the string.
Note: In the case of all 1s, the answer will be -1.

Examples:
Input : s = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6. 

Input: s = "111111"
Output: -1
Explanation: s contains 1s only 

Constraints:
1 ≤ s.size() ≤ 105
*/

#include<iostream>
#include<string>
using namespace std;

int maxSubstring(string& s) {
    int cur = 0, ans = INT_MIN;

    for (char ch : s) {
        int val = (ch == '0') ? 1 : -1;

        cur = max(val, cur + val);
        ans = max(ans, cur);
    }

    return ans < 0 ? -1 : ans;
}

int main(){
    string s;
    cin >> s;

    cout << maxSubstring(s) << endl;

    return 0;
}