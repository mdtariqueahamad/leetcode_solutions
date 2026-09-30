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
        int count = 0;
public:
    void dfs(TreeNode *root, int mx){

        if(!root) return;
        if(root->val >= mx) count++;

        dfs(root->left, max(root->val, mx));
        dfs(root->right, max(root->val, mx));
    }
    int goodNodes(TreeNode* root) {

        if(!root) return count;

        count++;

        dfs(root->left, root->val);
        dfs(root->right, root->val);

        return count;
    }
};