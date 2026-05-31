/*
3161. Block Placement Queries
Hard
There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.
You are given a 2D array queries, which contains two types of queries:
For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.

Example 1:
Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]
Output: [false,true,true]
Explanation:
For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.

Example 2:
Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]
Output: [true,true,false]
Explanation:
Place an obstacle at x = 7 for query 0. A block of size at most 7 can be placed before x = 7.
Place an obstacle at x = 2 for query 2. Now, a block of size at most 5 can be placed before x = 7, and a block of size at most 2 before x = 2.

Constraints:
1 <= queries.length <= 15 * 104
2 <= queries[i].length <= 3
1 <= queries[i][0] <= 2
1 <= x, sz <= min(5 * 104, 3 * queries.length)
The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
The input is generated such that there is at least one query of type 2.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Fenwick {
public:
    vector<int> bit;

    Fenwick(int n) : bit(n + 1) {}

    void update(int i, int val) {
        while (i < bit.size()) {
            bit[i] = max(bit[i], val);
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, bit[i]);
            i -= i & -i;
        }
        return res;
    }
};

vector<bool> getResults(vector<vector<int>>& queries) {
    int n = min(50000, (int)queries.size() * 3);

    set<int> obs = {0, n};
    for (auto &q : queries)
        if (q[0] == 1)
            obs.insert(q[1]);

    Fenwick ft(n + 1);

    for (auto it = obs.begin(); next(it) != obs.end(); ++it) {
        int l = *it;
        int r = *next(it);
        ft.update(r, r - l);
    }

    vector<bool> ans;

    for (int i = queries.size() - 1; i >= 0; --i) {
        auto &q = queries[i];

        if (q[0] == 1) {
            int x = q[1];
            auto it = obs.find(x);

            int prv = *prev(it);
            int nxt = *next(it);

            ft.update(nxt, nxt - prv);
            obs.erase(it);
        } else {
            int x = q[1];
            int sz = q[2];

            auto it = obs.upper_bound(x);
            int prv = *prev(it);

            ans.push_back(ft.query(prv) >= sz || x - prv >= sz);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            queries[i] = {type, x};
        } else {
            int x, sz;
            cin >> x >> sz;
            queries[i] = {type, x, sz};
        }
    }
    vector<bool> results = getResults(queries);
    for (bool res : results) {
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}