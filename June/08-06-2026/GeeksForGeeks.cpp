/*
Delete Nodes with Greater on Right
Easy
Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

Examples:
Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15->11->6->3
Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.

Input: LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last node has a greater value node on its right, so all the nodes except the last node must be removed.

Constraints:
1 ≤ size of linked list ≤ 106
1 ≤ element of linked list ≤ 106
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
    
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

Node *compute(Node *head) {
    if (!head || !head->next) return head;
    head = reverseList(head);
    Node* curr = head;
    int maxSoFar = curr->data;
    
    while (curr && curr->next) {
        if (curr->next->data < maxSoFar) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
            maxSoFar = curr->data;
        }
    }
    
    head = reverseList(head);
    return head;
}

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    head = compute(head);
    
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    
    return 0;
}