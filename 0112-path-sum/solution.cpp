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
    bool hasPathSum(TreeNode* root, int targetSum, int currSum = 0) {

        if(!root) return false;
        if(!root->left && !root->right)
            return currSum + root->val == targetSum;

        return hasPathSum(root->left, targetSum, currSum+root->val) || hasPathSum(root->right, targetSum, currSum+root->val);
    }
};
