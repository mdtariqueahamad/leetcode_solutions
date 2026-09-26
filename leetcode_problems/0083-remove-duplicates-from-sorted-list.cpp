// LeetCode Problem 0083: Remove Duplicates from Sorted List
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Language: cpp

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *root = head;
        while(head -> next != nullptr){
            if(head -> val == head -> next -> val){
                ListNode *temp = head -> next;
                head -> next = head -> next -> next;
                delete temp;
            } else
            head = head -> next;
        }
        return root;
    }
};