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
    void solve(TreeNode *root) {

        if(NULL == root) return;

        swap(root->left, root->right);

        solve(root->left);
        solve(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
