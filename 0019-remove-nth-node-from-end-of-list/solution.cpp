/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        else if(head -> next == NULL) return nullptr;
        ListNode* temp = head;
        int size = 1; 
        for( ; temp -> next != NULL; size++)
            temp = temp -> next;
        n = size - n;
        temp = head;
        for(;n > 1;n--)
            temp = temp -> next;
        if(n < 1){
            head = head -> next;
            delete temp;
            return head;
        }
        ListNode *del;
            del = temp -> next;
            temp -> next = del -> next;
        delete del;
        return head;
    }
};
