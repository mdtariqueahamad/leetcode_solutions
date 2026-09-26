// LeetCode Problem 3217: Delete Nodes From Linked List Present in Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
// Language: cpp

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toDelete(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            if (toDelete.count(curr->val)) {
                prev->next = curr->next; // unlink only
                // DON'T delete curr here
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};