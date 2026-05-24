/*
 * Problem Name: 61. Rotate List
 *
 * Problem Statement:
 * Given the head of a linked list, rotate the list to the right by k places.
 * 
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * Example 2:
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * 
 * Constraints:
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 109
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    int L = 0;
    ListNode* temp = head;
    while(temp->next != NULL){
        L++;
        temp = temp->next;
    }
    temp->next = head;
    L++;
    k = k % L;
    int rem = L - k;
    temp = head;
    while(rem != 1){
        temp = temp->next;
        rem--;
    }
    ListNode* newHead = temp->next;
    temp->next = NULL;
    return newHead;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 2;
    
    ListNode* result = rotateRight(head, k);
    
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}
