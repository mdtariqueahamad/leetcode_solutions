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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

       if(!head || !(head -> next) || !(head -> next -> next)) return {-1, -1};

       ListNode *prev = head; head = head -> next;
       vector<int> nums;

       int idx = 1;

       while(nullptr != head -> next){

        if(head -> val > prev -> val && head -> val > head -> next -> val || head -> val < prev -> val && head -> val < head -> next -> val) nums.push_back(idx);

        head = head -> next;
        prev = prev -> next;

        idx++;
       }

       if(0 == nums.size() || 1 == nums.size()) return {-1, -1};

       int max = nums[nums.size()-1] - nums[0];
       int minm = INT_MAX;
       
       for(int i = 0; i < nums.size()-1; i++)
        minm = min(minm, nums[i+1] - nums[i]);

       return {minm, max};
    }
};
