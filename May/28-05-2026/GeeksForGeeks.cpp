/*
Vertical Sum
Medium
Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.

Examples:
Input:
Output: 
4 2 12 3 7
Explanation:
The tree has 5 vertical lines
Line 1 has only one node 4 => vertical sum is 4.
Line 2 has only one node 2 => vertical sum is 2.
Line-3 has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12.
Line-4 has only one node 3 => vertical sum is 3.
Line-5 has only one node 7 => vertical sum is 7.

Input:
Output: 
7 6 4 3 2 1
Explanation:
There are six vertical lines each having one node.

Constraints:
1<=n<=104
1<= Node value <= 105
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> verticalSum(Node* root) {
    map<int,int> mp;
    dfs(root, 0, mp);
    vector<int> ans;
    for (auto &p : mp) ans.push_back(p.second);
    return ans;
}

void dfs(Node* node, int hd, map<int,int>& mp) {
    if (!node) return;
    mp[hd] += node->data;
    dfs(node->left, hd-1, mp);
    dfs(node->right, hd+1, mp);
}

int main(){
    int n;
    cin >> n;
    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nodes[i] = new Node(val);
    }
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        if (left != -1) nodes[i]->left = nodes[left];
        if (right != -1) nodes[i]->right = nodes[right];
    }
    vector<int> result = verticalSum(nodes[0]);
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}