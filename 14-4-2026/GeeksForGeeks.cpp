/*
Remove Spaces
Given a string s, remove all the spaces from the string and return the modified string.

Examples:
Input: s = "g eeks for ge eks"
Output: "geeksforgeeks"
Explanation: All space characters are removed from the given string while preserving the order of the remaining characters, resulting in the final string "geeksforgeeks".

Input: s = "abc d "
Output: "abcd"
Explanation:  All space characters are removed from the given string while preserving the order of the remaining characters, resulting in the final string "abcd".

Constraints:
1 ≤ |s| ≤ 105
*/

#include<iostream>
#include<string>
using namespace std;

string removeSpaces(string& s) {
    int n = s.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != ' '){
            s[j++] = s[i];
        }
    }
    s.resize(j);
    return s;
}

int main(){
    string s = "g eeks for ge eks";
    cout << removeSpaces(s) << endl; // Output: "geeksforgeeks"

    s = "abc d ";
    cout << removeSpaces(s) << endl; // Output: "abcd"

    return 0;
}