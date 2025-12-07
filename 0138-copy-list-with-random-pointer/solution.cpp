/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* ahead){
        Node *head = ahead;
        if(head == NULL) return NULL;
        Node *newhead = new Node(head -> val);
        Node *temp = newhead;
        unordered_map<Node*, Node*> mp;
        mp[head] = temp;
        while(head -> next != NULL){
            head = head -> next;
            temp -> next = new Node(head -> val);
            temp = temp -> next;
            mp[head] = temp;
        }
        head = ahead;
        temp = newhead;
        while(head != NULL){
            temp -> random = mp[head -> random];
            head = head -> next;
            temp = temp -> next;
        }
        return newhead;
    }
};
