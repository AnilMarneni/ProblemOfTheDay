/*
 * Problem Name: Remove Invalid Parentheses
 *
 * Problem Statement:
 * Given a string s consisting of lowercase letters and parentheses '(' and ')'.
 * A string is considered valid if:
 * Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
 * Parentheses are properly nested.
 * Remove the minimum number of invalid parentheses from s so that the resulting string becomes valid.  Return all the possible distinct valid strings in lexicographically sorted order.
 * 
 * Examples :
 * Input:  = "()())()"
 * Output: ["(())()", "()()()"]
 * Explanation:
 * The string "()())()" has one extra ')', making it invalid. By removing one ')', we can make it valid in two ways:
 * Remove the 3rd index ')' -> "(())()"
 * Remove the 4th index ')' -> "()()()"
 * Both are valid and require the minimum removals.
 * 
 * Input: s = "(a)())()"
 * Output: ["(a())()", "(a)()()"]
 * Explanation:
 * We remove one ')' (minimum removals) to make it valid. Possible valid results:
 * Remove a ')' -> "(a())()"
 * Remove another ')' -> "(a)()()"
 * 
 * Input: s = ")("
 * Output: [""]
 * Explanation: The string ")(" is invalid. Removing both parentheses (minimum removals) gives an empty string "", which is valid.
 * 
 * Constraints:
 * 1 ≤ |s| ≤ 20
 * s consists of lowercase English letters and parentheses '(' and ')'
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

void dfs(string &s, int idx, int open, int remOpen, int remClose, string curr, set<string>& st){
    if(idx == s.size()){
        if(open == 0 && remOpen == 0 && remClose == 0){
            st.insert(curr);
        }
        return;
    }
    char ch = s[idx];
    if(ch == '('){
        if(remOpen > 0){
            dfs(s, idx + 1, open, remOpen - 1, remClose, curr, st);
        }
        dfs(s, idx + 1, open + 1, remOpen, remClose, curr + ch, st);
    } else if(ch == ')'){
        if(remClose > 0){
            dfs(s, idx + 1, open, remOpen, remClose - 1, curr, st);
        }
        if(open > 0){
            dfs(s, idx + 1, open - 1, remOpen, remClose, curr + ch, st);
        }
    } else {
        dfs(s, idx + 1, open, remOpen, remClose, curr + ch, st);
    }
}

vector<string> validParenthesis(string &s) {
    int remOpen = 0, remClose = 0;
    
    for(char ch : s){
        if(ch == '('){
            remOpen++;
        } else if(ch == ')'){
            if(remOpen > 0){
                remOpen--;
            } else {
                remClose++;
            }
        }
    }
    
    set<string> st;
    dfs(s, 0, 0, remOpen, remClose, "", st);
    return vector<string>(st.begin(), st.end());
}

int main() {
    string s = "()())()";
    vector<string> result = validParenthesis(s);
    for(const string& str : result) {
        cout << str << endl;
    }
    return 0;
}
