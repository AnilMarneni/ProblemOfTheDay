/*
Smallest window containing 0, 1 and 2
Given a string s consisting only of the characters '0', '1' and '2', determine the length of the smallest substring that contains all three characters at least once.
If no such substring exists, return -1.

Examples :
Input: s = "10212"
Output: 3
Explanation: The substring "102" is the shortest substring that contains all three characters '0', '1', and '2', so the answer is 3.

Input: s = "12121"
Output: -1
Explanation: The character '0' is not present in the string, so no substring can contain all three characters '0', '1', and '2'. Hence, the answer is -1.

Constraints:
1 ≤ s.size() ≤ 105
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int smallestSubstring(string s) {
    int n = s.size();
    unordered_map<char, int> mp;
    int minLen = n + 1;
    int l = 0;

    for (int r = 0; r < n; r++) {
        mp[s[r]]++;

        while (mp.size() == 3) {
            minLen = min(minLen, r - l + 1);
            mp[s[l]]--;
            if (mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }
    }

    return (minLen == n + 1) ? -1 : minLen;
}

int main() {
    string s = "10212";
    int result = smallestSubstring(s);
    cout << "Length of the smallest substring containing '0', '1', and '2': " << result << endl;
    return 0;
}