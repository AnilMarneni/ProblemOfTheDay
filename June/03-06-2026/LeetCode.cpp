/*
3635. Earliest Finish Time for Land and Water Rides II
Medium
You are given two categories of theme park attractions: land rides and water rides.
Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.
A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.

Example 1:
Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]
Output: 9
Explanation:​​​​​​​
Plan A (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 2. Finish at 2 + landDuration[0] = 6.
Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, finish at 6 + waterDuration[0] = 9.
Plan B (water ride 0 → land ride 1):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 1 opens at landStartTime[1] = 8. Start at time 9, finish at 9 + landDuration[1] = 10.
Plan C (land ride 1 → water ride 0):
Start land ride 1 at time landStartTime[1] = 8. Finish at 8 + landDuration[1] = 9.
Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, finish at 9 + waterDuration[0] = 12.
Plan D (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
Land ride 0 opened at landStartTime[0] = 2. Start at time 9, finish at 9 + landDuration[0] = 13.
Plan A gives the earliest finish time of 9.

Example 2:
Input: landStartTime = [5], landDuration = [3], waterStartTime = [1], waterDuration = [10]
Output: 14
Explanation:​​​​​​​
Plan A (water ride 0 → land ride 0):
Start water ride 0 at time waterStartTime[0] = 1. Finish at 1 + waterDuration[0] = 11.
Land ride 0 opened at landStartTime[0] = 5. Start immediately at 11 and finish at 11 + landDuration[0] = 14.
Plan B (land ride 0 → water ride 0):
Start land ride 0 at time landStartTime[0] = 5. Finish at 5 + landDuration[0] = 8.
Water ride 0 opened at waterStartTime[0] = 1. Start immediately at 8 and finish at 8 + waterDuration[0] = 18.
Plan A provides the earliest finish time of 14.​​​​​​​

Constraints:
1 <= n, m <= 5 * 104
landStartTime.length == landDuration.length == n
waterStartTime.length == waterDuration.length == m
1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 105
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;

long long solve(vector<int>& Astart, vector<int>& Adur,
                    vector<int>& Bstart, vector<int>& Bdur) {
    int m = Bstart.size();

    vector<array<long long, 2>> rides(m);
    for (int i = 0; i < m; i++) {
        rides[i] = {Bstart[i], Bdur[i]};
    }

    sort(rides.begin(), rides.end());

    vector<long long> prefixMinDur(m);
    prefixMinDur[0] = rides[0][1];
    for (int i = 1; i < m; i++) {
        prefixMinDur[i] = min(prefixMinDur[i - 1], rides[i][1]);
    }

    vector<long long> suffixMinStartDur(m);
    suffixMinStartDur[m - 1] = rides[m - 1][0] + rides[m - 1][1];
    for (int i = m - 2; i >= 0; i--) {
        suffixMinStartDur[i] =
            min(suffixMinStartDur[i + 1], rides[i][0] + rides[i][1]);
    }

    long long ans = LLONG_MAX;

    for (int i = 0; i < Astart.size(); i++) {
        long long finish = 1LL * Astart[i] + Adur[i];

        int pos = upper_bound(
            rides.begin(),
            rides.end(),
            array<long long, 2>{finish, LLONG_MAX}
        ) - rides.begin();

        if (pos > 0) {
            ans = min(ans, finish + prefixMinDur[pos - 1]);
        }

        if (pos < m) {
            ans = min(ans, suffixMinStartDur[pos]);
        }
    }

    return ans;
}

int earliestFinishTime(vector<int>& landStartTime,
                        vector<int>& landDuration,
                        vector<int>& waterStartTime,
                        vector<int>& waterDuration) {
    long long ans = min(
        solve(landStartTime, landDuration,
                waterStartTime, waterDuration),
        solve(waterStartTime, waterDuration,
                landStartTime, landDuration)
    );

    return (int)ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> landStartTime(n), landDuration(n);
    for (int i = 0; i < n; i++) {
        cin >> landStartTime[i] >> landDuration[i];
    }
    vector<int> waterStartTime(m), waterDuration(m);
    for (int j = 0; j < m; j++) {
        cin >> waterStartTime[j] >> waterDuration[j];
    }

    cout << earliestFinishTime(landStartTime, landDuration,
                                waterStartTime, waterDuration) << endl;

    return 0;
}