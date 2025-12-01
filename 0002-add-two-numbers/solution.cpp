class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans, *res;
        int carry = 0;
        bool check = true;
        while(l1 && l2){
            int sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            sum %= 10;
            if(check){
            check = false;
            ans = new ListNode(sum);
            res = ans;
            l1 = l1 -> next;
            l2 = l2 -> next;
            continue;
            }
            ans -> next = new ListNode(sum);
            ans = ans -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        if(l1){
            while(l1){
            int sum = l1 -> val + carry;
            carry = sum / 10;
            sum %= 10;
            if(check){
            return l1;
            }
            ans -> next = new ListNode(sum);
            ans = ans -> next;
            l1 = l1 -> next;
            }
        }
        else if(l2){
            while(l2){
            int sum = l2 -> val + carry;
            carry = sum / 10;
            sum %= 10;
            if(check){
                return l2;
            }
            ans -> next = new ListNode(sum);
            ans = ans -> next;
            l2 = l2 -> next;
        }
        }
        if(carry){
            ans -> next = new ListNode(carry);
        }
        return res;
    }
};
