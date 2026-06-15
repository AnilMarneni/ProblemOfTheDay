/*
Minimum Cost to Fill Given Weight
Medium
Given a bag of size w kg and you are provided costs of packets different weights of oranges in array cost[], find the minimum total cost to buy exactly w kg oranges
The cost of 1 kg orange is present at index 0 and in general arr[i] has cost of (i+1) kg orange.
cost[i] = -1 means that 'i+1' kg packet of orange is unavailable.
If it is not possible to buy exactly w kg oranges then return -1. It may be assumed that there is an infinite supply of all available packet types.

Examples:
Input: cost[] = [20, 10, 4, 50, 100], w = 5
Output: 14
Explanation: The minimum cost is 14 by purchasing a 2kg packet for 10 and a 3kg packet for 4.

Input: cost[] = [-1, -1, 4, 3, -1], w = 5
Output: -1
Explanation: It is not possible to buy 5 kgs.

Constraints:
1 ≤ cost.size(), w ≤ 2*103
1 ≤ cost[i] ≤ 105
*/

#include <iostream>
#include <vector>
using namespace std;

int minimumCost(vector<int>& cost, int w) {
    const int INF = 1e9;

    vector<int> dp(w + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= w; i++) {
        for (int j = 0; j < cost.size(); j++) {
            int wt = j + 1;

            if (cost[j] == -1 || wt > i)
                continue;

            dp[i] = min(dp[i],
                        dp[i - wt] + cost[j]);
        }
    }

    return dp[w] == INF ? -1 : dp[w];
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << minimumCost(cost, w) << endl;
    return 0;
}