/*
Two water Jug problem
You are at the side of a river. You are given a m litre jug and a n litre jug . Both the jugs are initially empty. The jugs dont have markings to allow measuring smaller quantities. You have to use the jugs to measure d litres of water . Determine the minimum no of operations to be performed to obtain d litres of water in one of the jugs.
The operations you can perform are:
Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.

Examples:
Input: m = 3, n = 5, d = 4
Output: 6
Explanation: Operations are as follow-
1. Fill up the 5 litre jug.
2. Then fill up the 3 litre jug using 5 litre jug. Now 5 litre jug contains 2 litre water.
3. Empty the 3 litre jug.
4. Now pour the 2 litre of water from 5 litre jug to 3 litre jug.
5. Now 3 litre jug contains 2 litre of water and 5 litre jug is empty.
  Now fill up the 5 litre jug.
6. Now fill one litre of water from 5 litre jug to 3 litre jug. Now we have 4 litre water in 5 litre jug.

Input: m = 8, n = 56, d = 46
Output: -1
Explanation: Not possible to fill any one of the jug with 46 litre of water.

Constraints:
1 ≤ n, m ≤ 106
1 ≤ d ≤ 106
*/

#include<iostream>
#include<numeric>
using namespace std;

int pour(int m, int n, int d) {
    int from = m, to = 0, step = 1;

    while (from != d && to != d) {
        int move = min(from, n - to);
        to += move;
        from -= move;
        step++;

        if (from == d || to == d)
            break;

        if (from == 0) {
            from = m;
            step++;
        }

        if (to == n) {
            to = 0;
            step++;
        }
    }
    return step;
}

int minSteps(int m, int n, int d) {
    if (d > max(m, n)) return -1;
    if (d % gcd(m, n) != 0) return -1;

    return min(pour(m, n, d), pour(n, m, d));
}

int main() {
    int m = 3, n = 5, d = 4;
    cout << minSteps(m, n, d) << endl; // Output: 6
}