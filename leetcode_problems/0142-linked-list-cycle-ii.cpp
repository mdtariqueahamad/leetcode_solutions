// LeetCode Problem 0142: Linked List Cycle II
// Difficulty: Medium
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Language: cpp

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;

        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(!fast || !fast->next) return nullptr;
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};
