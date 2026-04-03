/*
3661. Maximum Walls Destroyed by Robots
There is an endless straight line populated with some robots and walls. You are given integer arrays robots, distance, and walls:
robots[i] is the position of the ith robot.
distance[i] is the maximum distance the ith robot's bullet can travel.
walls[j] is the position of the jth wall.
Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.
A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.
Return the maximum number of unique walls that can be destroyed by the robots.

Notes:
A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
Robots are not destroyed by bullets.
 
Example 1:
Input: robots = [4], distance = [3], walls = [1,10]
Output: 1
Explanation:
robots[0] = 4 fires left with distance[0] = 3, covering [1, 4] and destroys walls[0] = 1.
Thus, the answer is 1.

Example 2:
Input: robots = [10,2], distance = [5,1], walls = [5,2,7]
Output: 3
Explanation:
robots[0] = 10 fires left with distance[0] = 5, covering [5, 10] and destroys walls[0] = 5 and walls[2] = 7.
robots[1] = 2 fires left with distance[1] = 1, covering [1, 2] and destroys walls[1] = 2.
Thus, the answer is 3.

Example 3:
Input: robots = [1,2], distance = [100,1], walls = [10]
Output: 0
Explanation:
In this example, only robots[0] can reach the wall, but its shot to the right is blocked by robots[1]; thus the answer is 0.

Constraints:
1 <= robots.length == distance.length <= 105
1 <= walls.length <= 105
1 <= robots[i], walls[j] <= 109
1 <= distance[i] <= 105
All values in robots are unique
All values in walls are unique
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> arr;
vector<int> walls;
vector<vector<int>> f;

int dfs(int i, int j) {
    if (i < 0) return 0;
    if (f[i][j] != -1) return f[i][j];

    int left = arr[i].first - arr[i].second;
    if (i > 0) left = max(left, arr[i - 1].first + 1);

    int l = lower_bound(walls.begin(), walls.end(), left) - walls.begin();
    int r = lower_bound(walls.begin(), walls.end(), arr[i].first + 1) - walls.begin();
    int ans = dfs(i - 1, 0) + (r - l);

    int right = arr[i].first + arr[i].second;
    if (i + 1 < (int)arr.size()) {
        if (j == 0) right = min(right, arr[i + 1].first - arr[i + 1].second - 1);
        else right = min(right, arr[i + 1].first - 1);
    }

    l = lower_bound(walls.begin(), walls.end(), arr[i].first) - walls.begin();
    r = lower_bound(walls.begin(), walls.end(), right + 1) - walls.begin();
    ans = max(ans, dfs(i - 1, 1) + (r - l));

    return f[i][j] = ans;
}

int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& wallsInput) {
    int n = robots.size();
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {robots[i], distance[i]};
    }
    sort(arr.begin(), arr.end());
    walls = wallsInput;
    sort(walls.begin(), walls.end());

    f.assign(n, vector<int>(2, -1));

    return max(dfs(n - 1, 0), dfs(n - 1, 1));
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> robots(n), distance(n), walls(m);
    for (int i = 0; i < n; i++) {
        cin >> robots[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> distance[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> walls[i];
    }
    cout << maxWalls(robots, distance, walls) << endl;
}