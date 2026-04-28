/*
Longest Repeating Character Replacement
Given a string s of length n consisting of uppercase English letters and an integer k, you are allowed to perform at most k operations.  In each operation, you can change any character of the string to any other uppercase English letter.
Determine the length of the longest substring that can be transformed into a string with all identical characters after performing at most k such operations.

Examples:
Input: s = "ABBA", k = 2 
Output: 4 
Explanation: The string "ABBA" can be fully converted into the same character using at most 2 changes. By replacing both 'A' with 'B', it becomes "BBBB". Hence, the maximum length is 4.

Input: s = "ADBD", k = 1
Output: 3
Explanation: In the string "ADBD", we can make at most 1 change. By changing 'B' to 'D', the string becomes "ADDD", which contains a substring "DDD" of length 3.

Constraints:
1 ≤ n, k ≤ 105
s consists of only uppercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestSubstr(string& s, int k) {
    int n = s.size();
    vector<int> freq(26, 0);
    int left = 0, maxFreq = 0, result = 0;
    for(int right = 0; right < n; right++){
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);
        while((right - left + 1) - maxFreq > k){
            freq[s[left] - 'A']--;
            left++;
        }
        result = max(result, (right - left + 1));
    }
    return result;
}

int main() {
    string s = "ABBA";
    int k = 2;
    cout << longestSubstr(s, k) << endl; // Output: 4
    return 0;
}