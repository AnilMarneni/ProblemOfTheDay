/*
 * Problem Name: Minimum Multiplications to reach End
 *
 * Problem Statement:
 * Given two integers, start and end, along with an array of integers arr[]. In one operation, you can multiply the current value by any element from arr[], and then take the result modulo 1000 to obtain a new value.
 * Find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
 * 
 * Examples :
 * Input: arr[] = [2, 5, 7], start = 3, end = 30
 * Output: 2
 * Explanation:
 * Step 1: 3*2 = 6 % 1000 = 6
 * Step 2: 6*5 = 30 % 1000 = 30
 * 
 * Input: arr[] = [3, 4, 65], start = 7, end = 175
 * Output: 4
 * Explanation:
 * Step 1: 7 * 3 = 21 % 1000 = 21
 * Step 2: 21 * 3 = 63 % 1000 = 63
 * Step 3: 63 * 65 = 4095 % 1000 = 95
 * Step 4: 95 * 65 = 6175 % 1000 = 175
 * 
 * Input: arr[] = [2, 4], start = 3, end = 5
 * Output: -1
 * Explanation: Starting from 3 and multiplying by 2 or 4 always produces even numbers after the first step. Since 5 is odd, it can never be reached.
 * 
 * Constraints:
 * 1  ≤ arr.size()  ≤ 103
 * 1  ≤ arr[i]  ≤ 103
 * 0  ≤ start, end  < 103
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minSteps(vector<int>& arr, int start, int end) {
    vector<int> dist(1000, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == end) return dist[cur];
        for(int ele : arr){
            int nxt = (cur * ele) % 1000;
            if(dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 5};
    int start = 3, end = 30;

    int result = minSteps(arr, start, end);
    if(result != -1) {
        cout << "Minimum steps: " << result << endl;
    } else {
        cout << "End not reachable." << endl;
    }

    return 0;
}
