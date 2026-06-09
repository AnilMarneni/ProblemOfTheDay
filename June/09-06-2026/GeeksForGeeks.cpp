/*
Seating Arrangement
Easy
Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an empty seat and 1 denotes an occupied seat.
Determine whether it is possible to seat all k people such that no two occupied seats are adjacent (including newly seated people).

Examples:
Input: k = 2, seats[] = [0, 0, 1, 0, 0, 0, 1]
Output: true
Explanation: The two people can sit at index 0 and 4.

Input: k = 1, seats[] = [0, 1, 0]
Output: false
Explanation: There is no way to get a seat for one person.

Constraints:
0 ≤ k ≤ 105
1 ≤ seats.size() ≤ 105
seats[i] == 0 or seats[i] == 1
*/

#include <iostream>
#include <vector>
using namespace std;

bool canSeatAllPeople(int k, vector<int>& seats) {
    int n = seats.size();

    for (int i = 0; i < n && k > 0; i++) {
        if (seats[i] == 0) {
            bool leftEmpty = (i == 0 || seats[i - 1] == 0);
            bool rightEmpty = (i == n - 1 || seats[i + 1] == 0);

            if (leftEmpty && rightEmpty) {
                seats[i] = 1;
                k--;
            }
        }
    }

    return k == 0;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }
    cout << (canSeatAllPeople(k, seats) ? "true" : "false") << endl;
    return 0;
}