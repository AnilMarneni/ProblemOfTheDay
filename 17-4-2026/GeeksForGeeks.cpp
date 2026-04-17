/*
Anagram Palindrome
Given a string s, determine whether its characters can be rearranged to form a palindrome. Return true if it is possible to rearrange the string into a palindrome; otherwise, return false.

Examples
Input: s = "baba"
Output: true
Explanation: Can be rearranged to form a palindrome "abba" 

Input: s = "geeksogeeks"
Output: true
Explanation: The characters of the string can be rearranged to form the palindrome "geeksoskeeg".

Input: s = "geeksforgeeks"
Output: false
Explanation: The given string can't be converted into a palindrome.

Constraints:
1 ≤ s.length ≤ 106
s consists of only lowercase English letters.
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool canFormPalindrome(string &s) {
    unordered_map<char, int> mp;
    for(char ch : s){
        mp[ch]++;
    }
    int oddCount = 0;
    for(auto &p : mp){
        if(p.second % 2 != 0){
            oddCount++;
        }
    }
    return oddCount <= 1;
}

int main() {
    string s = "baba";
    cout << canFormPalindrome(s) << endl; // Output: true
}