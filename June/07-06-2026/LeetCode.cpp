/*
2196. Create Binary Tree From Descriptions
Medium
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,
If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.
The test cases will be generated such that the binary tree is valid.

Example 1:
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:
Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.

Constraints:
1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> mp;
    unordered_set<int> child;

    for (auto &d : descriptions) {
        int p = d[0], c = d[1], left = d[2];

        if (!mp.count(p)) mp[p] = new TreeNode(p);
        if (!mp.count(c)) mp[c] = new TreeNode(c);

        if (left) mp[p]->left = mp[c];
        else mp[p]->right = mp[c];

        child.insert(c);
    }

    for (auto &[val, node] : mp) {
        if (!child.count(val)) return node;
    }

    return nullptr;
}

void inOrder(TreeNode* node, vector<int>& res) {
    if (node == nullptr)
        return;
        
    inOrder(node->left, res);
    res.push_back(node->val);
    inOrder(node->right, res);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> descriptions(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        cin >> descriptions[i][0] >> descriptions[i][1] >> descriptions[i][2];
    }
    TreeNode* root = createBinaryTree(descriptions);
    vector<int> result;
    inOrder(root, result);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}