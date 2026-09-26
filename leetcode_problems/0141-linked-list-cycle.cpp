// LeetCode Problem 0141: Linked List Cycle
// Difficulty: Easy
// Link: https://leetcode.com/problems/linked-list-cycle/
// Language: cpp

class Solution {
public:
    bool hasCycle(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};
