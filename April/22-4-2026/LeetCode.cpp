/*
2452. Words Within Two Edits of Dictionary
You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.
In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.
Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.

Example 1:
Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
Output: ["word","note","wood"]
Explanation:
- Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
- Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
- It would take more than 2 edits for "ants" to equal a dictionary word.
- "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
Thus, we return ["word","note","wood"].

Example 2:
Input: queries = ["yes"], dictionary = ["not"]
Output: []
Explanation:
Applying any two edits to "yes" cannot make it equal to "not". Thus, we return an empty array.

Constraints:
1 <= queries.length, dictionary.length <= 100
n == queries[i].length == dictionary[j].length
1 <= n <= 100
All queries[i] and dictionary[j] are composed of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> output;
    for(string query : queries){
        for(string word : dictionary){
            int mismatch = 0;
            for(int i = 0; i < word.size(); i++){
                if(word[i] != query[i]){
                    mismatch++;
                }
                if(mismatch > 2) break;
            }
            if(mismatch <= 2){
                output.push_back(query);
                break;
            }
        }
    }
    return output;
}

int main() {
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};
    vector<string> result = twoEditWords(queries, dictionary);
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}