/*
3753. Total Waviness of Numbers in Range II
Hard
You are given two integers num1 and num2 representing an inclusive range [num1, num2].
The waviness of a number is defined as the total count of its peaks and valleys:
A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].

Example 1:
Input: num1 = 120, num2 = 130
Output: 3
Explanation:
In the range [120, 130]:
120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 2:
Input: num1 = 198, num2 = 202
Output: 3
Explanation:
In the range [198, 202]:
198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 3:
Input: num1 = 4848, num2 = 4848
Output: 2
Explanation:
Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

Constraints:
1 <= num1 <= num2 <= 1015​​​​​​​
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Node {
    long long cnt;
    long long sum;
};

string s;

Node dp[16][11][11][16][2];
bool vis[16][11][11][16][2];

Node dfs(int pos,
            int last2,
            int last1,
            int len,
            bool tight) {

    if (pos == s.size()) {
        return {1, 0};
    }

    if (!tight && vis[pos][last2][last1][len][0]) {
        return dp[pos][last2][last1][len][0];
    }

    int limit = tight ? s[pos] - '0' : 9;

    Node ans = {0, 0};

    for (int d = 0; d <= limit; d++) {

        bool ntight = tight && (d == limit);

        if (len == 0 && d == 0) {

            Node nxt = dfs(
                pos + 1,
                10,
                10,
                0,
                ntight
            );

            ans.cnt += nxt.cnt;
            ans.sum += nxt.sum;
        }
        else {

            int add = 0;

            if (len >= 2) {
                if ((last1 > last2 && last1 > d) ||
                    (last1 < last2 && last1 < d))
                    add = 1;
            }

            int nlast2;
            int nlast1;

            if (len == 0) {
                nlast2 = 10;
                nlast1 = d;
            }
            else if (len == 1) {
                nlast2 = last1;
                nlast1 = d;
            }
            else {
                nlast2 = last1;
                nlast1 = d;
            }

            Node nxt = dfs(
                pos + 1,
                nlast2,
                nlast1,
                len + 1,
                ntight
            );

            ans.cnt += nxt.cnt;
            ans.sum += nxt.sum + nxt.cnt * add;
        }
    }

    if (!tight) {
        vis[pos][last2][last1][len][0] = true;
        dp[pos][last2][last1][len][0] = ans;
    }

    return ans;
}

long long solve(long long x) {

    if (x <= 0) return 0;

    s = to_string(x);

    memset(vis, 0, sizeof(vis));

    return dfs(0, 10, 10, 0, true).sum;
}

long long totalWaviness(long long num1, long long num2) {
    return solve(num2) - solve(num1 - 1);
}

int main() {
    long long num1, num2;
    cin >> num1 >> num2;

    cout << totalWaviness(num1, num2) << endl;

    return 0;
}