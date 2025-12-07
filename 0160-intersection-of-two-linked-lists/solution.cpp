/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int balance(ListNode *head1, ListNode *head2){
        int len1 = 0, len2 = 0;
        while(head1 != NULL || head2 != NULL){
            if(head1 != NULL){
                len1++;
                head1 = head1 -> next;
            }
            if(head2 != NULL){
                len2++;
                head2 = head2 -> next;
            }
        }
        return len1 - len2;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        int diff = balance(headA, headB);
        if(diff > 0){
            while(diff && headA != NULL){
                headA = headA -> next;
                diff--;
            }
        } else{
            while(diff && headB != NULL){
                headB = headB -> next;
                diff++;
            }
        }
        while(headA != NULL && headB != NULL){
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};
