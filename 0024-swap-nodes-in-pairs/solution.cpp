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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        else if(head -> next == NULL) return head;
        ListNode *slow = head, *fast = head -> next;
        while(slow != nullptr && fast != nullptr){
            swap(slow -> val, fast -> val);
            if(fast -> next == nullptr || fast -> next -> next == nullptr) break;
            slow = fast -> next;
            fast = slow -> next;
        }
        return head;
    }
};
