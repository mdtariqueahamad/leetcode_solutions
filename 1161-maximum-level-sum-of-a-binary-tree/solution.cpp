/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;

        q.push(root);
        int ans = 1, sumMax = root->val;

        for(int level = 1; !q.empty(); level++) {

            int size = q.size(), sum = 0;

            while(size--) {

                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) q.push(curr->left);

                if(curr->right) q.push(curr->right);
                
                sum += curr->val;
            }
            if(sum > sumMax) {
                    sumMax = sum;
                    ans = level;
            }
        }

        return ans;
    }
};