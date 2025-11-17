class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited;
        ListNode* temp = head;

        while(temp != nullptr) {
            if(visited.count(temp)) {
                return true;  // Cycle detected
            }
            visited.insert(temp);
            temp = temp->next;
        }

        return false;  // No cycle
    }
};

