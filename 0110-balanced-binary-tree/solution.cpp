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
    int dfs(TreeNode* root, int count) {
        if(NULL == root) return count;
        return max(dfs(root -> left, count+1),
        dfs(root -> right, count+1));
    }
public:
    bool isBalanced(TreeNode* root) {

        if(!root) return true;
        
        if(abs(dfs(root->right, 0) - dfs(root->left, 0)) > 1) return false;

        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;

        return true;
    }
};