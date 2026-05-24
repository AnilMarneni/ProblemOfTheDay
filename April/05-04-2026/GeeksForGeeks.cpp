/*
Target Sum
Medium
Given an array of integers arr[] and an integer target. We need to build an expression out of arr[] by adding one of the symbols '+' or  '-' before each integer in arr[] and then concatenate all the integers. 
For example : if arr[] = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target.
Note : An expression is considered different from another if the placement of '+' and '-' operators differs, even if the resulting value is the same. 

Examples :
Input: arr[] = [1, 1, 1, 1, 1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Input: arr[] = [1, 2, 3], target = 2
Output: 1
Explanation: There are 1 way to assign symbols to make the sum of nums be target 2(+1 -2 +3). 

Constraints:
1 ≤ arr.size() ≤ 50
1 ≤ arr[i] ≤ 20
0 ≤ sum(arr) ≤ 1000
-1000 ≤ target ≤ 1000
*/

#include<iostream>
#include<vector>
using namespace std;

int totalWays(vector<int>& arr, int target) {
    vector<int> dp(2001, 0);

    dp[1000] = 1;

    for(int num : arr) {

        vector<int> temp(2001, 0);

        for(int sum = -1000; sum <= 1000; sum++) {

            if(dp[sum + 1000]) {

                temp[sum + num + 1000] += dp[sum + 1000];

                temp[sum - num + 1000] += dp[sum + 1000];
            }
        }

        dp = temp;
    }

    return (target > 1000 || target < -1000)
            ? 0
            : dp[target + 1000];
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cout << totalWays(vec, target) << endl;
    return 0;
}