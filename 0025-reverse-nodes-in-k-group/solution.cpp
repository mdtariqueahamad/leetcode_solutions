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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *prev, *curr = head, *nxt, *head_trace = head;

        bool check = true;
        while (curr) {

            prev = curr, curr = nxt = curr->next;
            ListNode *prev_trace = prev;

            int i = k;
            ListNode *temp = prev;

            while (i && temp) {
                i--;
                temp = temp->next;
            }

            if (i)
                break;
            
            prev->next = temp;
            while(nxt != temp){
                nxt = nxt->next;
                curr -> next = prev;
                prev = curr;
                curr = nxt;
            }
            if(check){
                check = false;
                head = prev;
            } else {
                head_trace->next = prev;
                head_trace = prev_trace;
            }
        }
        return head;
    }
};
