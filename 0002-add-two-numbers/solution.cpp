class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;   // We'll store result in l1
        ListNode* prev = nullptr; // Keep track of last node
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            if (l1 != nullptr) {
                l1->val = sum % 10; // store sum in l1
                prev = l1;
                l1 = l1->next;
            } else {
                // l1 ended, but l2 or carry remains
                prev->next = new ListNode(sum % 10); 
                prev = prev->next;
            }

            if (l2 != nullptr) l2 = l2->next;
        }

        return head;
    }
};
