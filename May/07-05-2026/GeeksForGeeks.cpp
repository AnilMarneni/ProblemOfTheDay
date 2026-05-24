/*
Check if subtree
Medium
Given two binary trees with roots root1 (for tree T) and root2 (for tree S), each containing at most N nodes. Determine whether tree S is a subtree of tree T.
Return true if S is a subtree of T, otherwise return false.
Note: A tree S is considered a subtree of T if there exists a node in T such that the subtree rooted at that node is identical to S. Two trees are identical if they have the same structure and the same node values.

Examples:
Input: root1 = [1, 2, 3, N, N, 4], root2 = [3, 4]  
Output: true 
Explanation: In the tree rooted at root1, the subtree starting at node 3 is identical to the tree rooted at root2 (same structure and node values). Hence, root2 is a subtree of root1, so the output is true.

Input: root1 = [26, 10, N, 20, 30, 40, 60], root2 = [26, 10, N, 20, 30, 40, 60]
Output: true 
Explanation: Both root1 and root2 represent identical trees. So, root2 is a subtree of root1, and the output is true.

Constraints:
1 ≤ n ≤ 103
1 ≤ value of nodes ≤ 104
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

Node* buildTree() {

    int val;
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

bool isSame(Node* a, Node* b) {

    if(a == NULL && b == NULL) return true;

    if(a == NULL || b == NULL) return false;

    if(a->data != b->data) return false;

    return isSame(a->left, b->left) &&
           isSame(a->right, b->right);
}

bool isSubTree(Node* root1, Node* root2) {

    if(root2 == NULL) return true;

    if(root1 == NULL) return false;

    if(isSame(root1, root2)) return true;

    return isSubTree(root1->left, root2) ||
           isSubTree(root1->right, root2);
}

int main() {

    Node* root1 = buildTree();
    Node* root2 = buildTree();

    if(isSubTree(root1, root2))
        cout << "True";
    else
        cout << "False";

    return 0;
}