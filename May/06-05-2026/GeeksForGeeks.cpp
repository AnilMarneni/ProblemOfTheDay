/*
 * Problem Name: Size of Binary Tree
 *
 * Problem Statement:
 * Given the root of a binary tree, return the size of the tree. The size of a binary tree is the total number of nodes in the tree.
 * 
 * Examples:
 * Input:
 * Output:  3
 * Explanation: There are 3 nodes in the given binary tree, so its size is 3.
 * 
 * Input:
 * Output: 6
 * Explanation: There are 6 nodes in the given binary tree, so its size is 6.
 * 
 * Constraints:
 * 1 ≤ number of nodes ≤ 105
 * 1 ≤ node->data ≤ 105
 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int getSize(Node* root) {
    // code here
    if(root == nullptr){
        return 0;
    }
    int left = getSize(root->left);
    int right = getSize(root->right);
    return left + right + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    int size = getSize(root);
    cout << size << endl; // Output: 3

    return 0;
}
