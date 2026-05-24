/*
Transform to Sum Tree
Easy
Given a root of a binary tree with n nodes, where each node may contain positive or negative values, convert it into a tree such that each node’s new value is equal to the sum of all values in its left and right subtrees (based on the original tree). For leaf nodes, update their values to 0.

Examples:      
Input: root = [10, -2, 6, 8, -4, 7, 5]
Output:
Explanation:
Leaf nodes update: The leaf nodes 8, -4, 7, 5 are changed to 0 since they have no children.
Update internal nodes: Left child: 8 + (-4) = 4
Right child: 7 + 5 = 12
Update root node: Root = sum of left and right subtree values = 4 - 2 + 12 + 6 = 20

Input: root = [1, 2, 3, 4, 5, -6, 2]
Output:
Explanation:
Leaf nodes update: The leaf nodes 4, 5, -6, 2 are changed to 0 since they have no children.
Update internal nodes: Left child: 4 + 5 = 9
Right child: -6 + 2 = -4
Update root node: Root = sum of left and right subtree values = 9 + 2 + 3 + (-4) = 10

Constraints:
1 ≤ n ≤ 104
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int solve(Node* root) {
    if(root == NULL)
        return 0;

    int oldVal = root->data;

    int leftSum = solve(root->left);
    int rightSum = solve(root->right);

    root->data = leftSum + rightSum;

    return oldVal + leftSum + rightSum;
}

void toSumTree(Node *node) {
    solve(node);
}

Node* buildTree(){
    int val;
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main(){
    Node* root = buildTree();
    toSumTree(root);
    return 0;
}