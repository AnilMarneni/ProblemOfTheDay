/*
URLify a given string
Given a string s, replace all the spaces in the string with '%20'.

Examples:
Input: s = "i love programming"
Output: "i%20love%20programming"
Explanation: The 2 spaces are replaced by '%20'

Input: s = "Mr Benedict Cumberbatch"
Output: "Mr%20Benedict%20Cumberbatch"
Explanation: The 2 spaces are replaced by '%20'

Constraints:
1 ≤ s.size() ≤ 104
*/

#include<iostream>
#include<string>
using namespace std;

string URLify(string &s) {
    int n = s.size();
    string ans = "";
    for(int i = 0; i < n; i++){
        if(s[i] == ' '){
            ans += "%20";
            continue;
        }
        ans += s[i];
    }
    return ans;
}

int main(){
    string s = "i love programming";
    cout << URLify(s) << endl; // Output: "i%20love%20programming"

    s = "Mr Benedict Cumberbatch";
    cout << URLify(s) << endl; // Output: "Mr%20Benedict%20Cumberbatch"

    return 0;
}