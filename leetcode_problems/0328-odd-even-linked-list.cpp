// LeetCode Problem 0328: Odd Even Linked List
// Difficulty: Medium
// Link: https://leetcode.com/problems/odd-even-linked-list/
// Language: cpp

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};