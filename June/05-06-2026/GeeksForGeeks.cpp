/*
Lexicographically smallest after removing k
Medium 
Given a string s consisting of n lowercase characters. Return the lexicographically smallest string after removing exactly k characters from the string. But you have to correct the value of k, i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2. You can remove any k characters.
Note: If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty return -1.

Examples:
Input: s = "fooland", k = 2
Output: "and" 
Explanation: As the size of the string = 7 which is not a power of 2, hence k = 4. After removing 4 characters from the given string, the lexicographically smallest string is "and".

Input: s = "code", k = 4
Output: "cd"
Explanation: As the length of the string = 4, which is 2 to the power 2, hence k = 2. Hence, lexicographically smallest string after removal of 2 characters is "cd".

Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ 105
*/

#include <iostream>
#include <string>
#include<stack>
#include<algorithm>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

string lexicographicallySmallest(string &s, int k) {
    int n = s.size();
    if(isPowerOfTwo(n))
        k /= 2;
    else
        k *= 2;
    if(k >= n) return "-1";
    stack<char> mono;
    for(char ch : s){
        while(!mono.empty() && k > 0 && mono.top() > ch){
            mono.pop();
            k--;
        }
        mono.push(ch);
    }
    while(k > 0 && !mono.empty()){
        mono.pop();
        k--;
    }
    string str = "";
    while(!mono.empty()){
        str += mono.top();
        mono.pop();
    }
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    cout << lexicographicallySmallest(s, k) << endl;

    return 0;
}