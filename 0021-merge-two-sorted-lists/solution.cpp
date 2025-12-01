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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(!list1 && !list2) return nullptr;
        ListNode *temp;
        ListNode *ans;
        bool check = true;
        while(list1 && list2){
            if(check){
                check = false;
                temp = new ListNode();
                ans = temp;
            }
            else{
            temp -> next = new ListNode();
            temp = temp -> next;
            }
            if(list1 -> val < list2 -> val){
                temp -> val = list1 -> val;
                list1 = list1 -> next;
            }
            else{
                temp -> val = list2 -> val;
                list2 = list2 -> next;
            }
        }
        if(check){
            if(list1){
            ans = list1;
        }
        else if(list2){
            ans = list2;
        }
        }
        else{
        if(list1){
            temp -> next = list1;
        }
        else if(list2){
            temp -> next = list2;
        }
        }
        return ans;
    }
};
