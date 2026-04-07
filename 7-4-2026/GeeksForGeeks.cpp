/*
Stable Marriage Problem

You are given two arrays men[] and women[], each of length n, where:
men[i] represents the preference list of the i-th man, ranking all women in order of preference.
women[i] represents the preference list of the i-th woman, ranking all men in order of preference.
The task is to form n pairs (marriages) such that:
Each man is matched with exactly one woman, and each woman is matched with exactly one man.
The matching is stable, meaning there is no pair (man, woman) who both prefer each other over their current partners.
It is guaranteed that a stable matching always exists. Return the stable matching from the men’s perspective, i.e., the one where men are considered for the final output.
Return an array result[] of size n, where result[i] denotes the index (0-based) of the woman matched with the i-th man.

Examples: 
Input: n = 2, men[] = [[0, 1], [0, 1], women[] = [[0, 1], [0, 1]]
Output: [0, 1]
Explanation:
Man 0 is married to Woman 0 (his first choice and her first choice).
Man 1 is married to Woman 1 (his second choice and her second choice).

Input: n = 3, men[] = [[0, 1, 2], [0, 1, 2], [0, 1, 2]], women[] = [[2, 1, 0], [2, 1, 0], [2, 1, 0]]
Output: [2, 1, 0]
Explanation:
Man 0 is married to Woman 2 (his third choice and her third choice).
Man 1 is married to Woman 1 (his second choice and her second choice).
Man 2 is married to Woman 0 (his first choice and her first choice).

Constraints: 
2 ≤ n ≤ 103
0 ≤ men[i] ≤ n - 1
0 ≤ women[i] ≤ n - 1
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
    int n = men.size();
    vector<int> womenPartners(n, -1);
    vector<int> menPartners(n, -1);
    vector<int> nextProposal(n, 0);

    vector<vector<int>> rank(n, vector<int>(n));
    for (int w = 0; w < n; w++) {
        for (int r = 0; r < n; r++) {
            rank[w][women[w][r]] = r;
        }
    }

    queue<int> freeMen;
    for (int m = 0; m < n; m++) {
        freeMen.push(m);
    }

    while (!freeMen.empty()) {
        int man = freeMen.front();
        freeMen.pop();

        int woman = men[man][nextProposal[man]];
        nextProposal[man]++;

        if (womenPartners[woman] == -1) {
            womenPartners[woman] = man;
            menPartners[man] = woman;
        } else {
            int curMan = womenPartners[woman];
            if (rank[woman][man] < rank[woman][curMan]) {
                womenPartners[woman] = man;
                menPartners[man] = woman;
                freeMen.push(curMan);
            } else {
                freeMen.push(man);
            }
        }
    }
    return menPartners;
}

int main(){
    vector<vector<int>> men = {{0, 1}, {0, 1}};
    vector<vector<int>> women = {{0, 1}, {0, 1}};
    vector<int> result = stableMarriage(men, women);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}