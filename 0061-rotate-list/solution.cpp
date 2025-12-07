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
    ListNode* rotateRight(ListNode* head, int k){
        ListNode *temp = head, *prev;
        if(head == NULL || head -> next == NULL) return head;
        int count = 1;
        while(temp -> next != nullptr){
            count++;
            temp = temp -> next;
        }
        temp -> next = head;
        k %= count;
        k = count - k;
        while(k){
            prev = head;
            head = head -> next;
            k--;
        }
        prev -> next = NULL;
        return head;
    }
};
