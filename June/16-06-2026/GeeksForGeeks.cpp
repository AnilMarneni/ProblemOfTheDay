/*
Construct List using XOR Queries
Medium
There is an array that initially contains only a single value, 0. 
Given a list of queries queries[][] of size q, where each query is of one of the following types:
0 x: Insert x into the array.
1 x: Replace every element a in the array with a ^ x, where ^ denotes the bitwise XOR operator.
Return the array in sorted order after performing all the queries.

Examples:
Input: q = 5, queries[] = [[0, 6], [0, 3], [0, 2], [1, 4], [1, 5]]
Output: [1, 2, 3, 7]
Explanation:
[0] (initial value)
[0, 6] (add 6 to list)
[0, 6, 3] (add 3 to list)
[0, 6, 3, 2] (add 2 to list)
[4, 2, 7, 6] (XOR each element by 4)
[1, 7, 2, 3] (XOR each element by 5)
The sorted list after performing all the queries is [1, 2, 3, 7]. 

Input: q = 3, queries[] = [[0, 2], [1, 3], [0, 5]] 
Output : [1, 3, 5]
Explanation:
[0] (initial value)
[0, 2] (add 2 to list)
[3, 1] (XOR each element by 3)
[3, 1, 5] (add 5 to list)
The sorted list after performing all the queries is [1, 3, 5].

Constraints:
1 ≤ q ≤ 105
0 ≤ x ≤ 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> constructList(vector<vector<int>> &queries) {
    vector<int> ans = {0};
    int n = queries.size();
    for(int i = 0; i < n; i++){
        int val = queries[i][0];
        int num = queries[i][1];
        if(val == 0){
            ans.push_back(num);
        } else{
            for(int j = 0; j < ans.size(); j++){
                ans[j] = ans[j] ^ num;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for(int i = 0; i < q; i++){
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> result = constructList(queries);
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}