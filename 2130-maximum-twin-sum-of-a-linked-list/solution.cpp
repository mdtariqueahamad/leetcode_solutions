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
    int pairSum(ListNode* head) {
        int ans = 0;

        ListNode *fast = head;
        stack<int> st;

        while(fast){
            st.push(head->val);
            head = head->next;
            fast = fast->next->next;
        }

        while(head){
            ans = max(ans,(st.top()+head->val));
            st.pop();
            head = head->next;
        }

        return ans;
    }
};