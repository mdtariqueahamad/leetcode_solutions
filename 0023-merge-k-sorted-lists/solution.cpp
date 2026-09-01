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
class compare{
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto &it: lists)
            if(it != nullptr)
            pq.push(it);

        if(pq.empty()) return nullptr;

        ListNode *ans = new ListNode();
        ListNode *a = ans;
        while(pq.size()){
            ListNode *curr = pq.top();
            pq.pop();
            ans -> val = curr -> val;
            if(curr -> next) pq.push(curr -> next);

            if(pq.empty()) break;
            ans -> next = new ListNode();
            ans = ans -> next;
        }
        return a;
    }
};
