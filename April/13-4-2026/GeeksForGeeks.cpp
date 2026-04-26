/*
Next Smallest Palindrome
Given a number, in the form of an array num[] containing digits from 1 to 9(inclusive). Find the next smallest palindrome strictly larger than the given number.

Examples:

Input: num[] = [9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2]
Output: [9, 4, 1, 8, 8, 0, 8, 8, 1, 4, 9]
Explanation: Next smallest palindrome is 9 4 1 8 8 0 8 8 1 4 9.

Input: num[] = [2, 3, 5, 4, 5]
Output: [2, 3, 6, 3, 2]
Explanation: Next smallest palindrome is 2 3 6 3 2.

Constraints:
1 ≤ n ≤ 105
1 ≤ num[i] ≤ 9
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> nextPalindrome(vector<int>& num) {
    int n = num.size();
    
    bool all9 = true;
    for (int d : num) {
        if (d != 9) { all9 = false; break; }
    }
    if (all9) {
        vector<int> ans(n+1, 0);
        ans[0] = 1;
        ans[n] = 1;
        return ans;
    }
    
    vector<int> ans = num;

    for (int i = 0; i < n/2; i++) {
        ans[n-1-i] = ans[i];
    }

    if (ans > num) return ans;

    int carry = 1;
    int mid = (n-1)/2;
    while (mid >= 0 && carry) {
        int val = ans[mid] + carry;
        ans[mid] = val % 10;
        carry = val / 10;
        mid--;
    }

    if (carry) {
        ans.insert(ans.begin(), 1);
        ans.push_back(1);
        n += 2;
    }

    for (int i = 0; i < n/2; i++) {
        ans[n-1-i] = ans[i];
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    vector<int> result = nextPalindrome(num);
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}