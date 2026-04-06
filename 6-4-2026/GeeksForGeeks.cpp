/*
Huffman Encoding
Given a string s of distinct characters and their corresponding frequency f[ ] i.e. character s[i] has f[i] frequency. You need to build the Huffman tree and return all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

Examples:
Input: s = "abcdef", f[] = {5, 9, 12, 13, 16, 45}
Output: [0, 100, 101, 1100, 1101, 111]
Explanation:

HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111

Constraints:
1 ≤ s.size() = f.size() ≤ 26
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char data;
    int freq;
    int idx;
    Node* left;
    Node* right;

    Node(char d, int f, int i) {
        data = d;
        freq = f;
        idx = i;
        left = right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq)
            return a->idx > b->idx;
        return a->freq > b->freq;
    }
};

void dfs(Node* root, string code, vector<string> &ans) {
    if (!root) return;

    if (root->data != '$') {
        ans.push_back(code);
        return;
    }

    dfs(root->left, code + "0", ans);
    dfs(root->right, code + "1", ans);
}

vector<string> huffmanCodes(string &s, vector<int> f) {

    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < s.size(); i++) {
        pq.push(new Node(s[i], f[i], i));
    }

    if (pq.size() == 1) return {"0"};

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('$',
            left->freq + right->freq,
            min(left->idx, right->idx));

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    vector<string> ans;
    dfs(pq.top(), "", ans);

    return ans;
}

int main() {
    string s;
    int n;
    cin >> s >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    vector<string> result = huffmanCodes(s, f);
    for (const string& code : result) {
        cout << code << " ";
    }
    cout << endl;
}