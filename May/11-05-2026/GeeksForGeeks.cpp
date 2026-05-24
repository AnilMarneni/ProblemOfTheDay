/*
 * Problem Name: Palindrome Pairs
 *
 * Problem Statement:
 * Given an array arr[] consisting of n strings. Determine whether there exists a pair of indices (i, j) such that i ≠ j and the concatenation arr[i] + arr[j] forms a palindrome.
 * Return true if such a pair exists; otherwise, return false.
 * Note: A string is considered a palindrome if it reads the same forward and backward.
 * 
 * Examples:
 * Input: arr[] = ["geekf", "geeks", "or", "keeg", "abc", "bc"]
 * Output: true
 * Explanation: There is a pair "geekf" and "keeg". Their concatenation "geekfkeeg" is a palindrome.
 * 
 * Input: arr[] = ["abc", "xyxcba", "geekst", "or", "bc"]
 * Output: true
 * Explanation: There is a pair "abc" and "xyxcba". Their concatenation "abcxyxcba" is a palindrome.
 * 
 * Input: arr[] = ["aa"]
 * Output: false
 * Explanation: There is only one string present, so the output is false.
 * 
 * Constraints:
 * 1 ≤ n ≤ 2*104
 * 1 ≤ |arr[i]| ≤ 10
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int wordIndex = -1;
    vector<int> palindromeSuffixIndices;
};

TrieNode* root = new TrieNode();

bool isPalindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void insert(const string &word, int index) {
    TrieNode* node = root;
    for (int i = word.size() - 1; i >= 0; i--) {
        if (isPalindrome(word, 0, i)) {
            node->palindromeSuffixIndices.push_back(index);
        }
        if (!node->children.count(word[i])) {
            node->children[word[i]] = new TrieNode();
        }
        node = node->children[word[i]];
    }
    node->wordIndex = index;
    node->palindromeSuffixIndices.push_back(index);
}

bool search(const string &word, int index) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (node->wordIndex != -1 && node->wordIndex != index &&
            isPalindrome(word, i, word.size() - 1)) {
            return true;
        }
        if (!node->children.count(word[i])) return false;
        node = node->children[word[i]];
    }

    for (int j : node->palindromeSuffixIndices) {
        if (j != index) return true;
    }
    return false;
}

bool palindromePair(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        insert(arr[i], i);
    }
    for (int i = 0; i < n; i++) {
        if (search(arr[i], i)) return true;
    }
    return false;
}
