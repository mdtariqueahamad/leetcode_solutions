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
    int ans = 0;

    void dfs(TreeNode* root, int curr, char c){
        if(!root) return;
        ans = max(curr, ans);

        if('r' == c) {
            dfs(root->left, curr+1, 'l');
            dfs(root->right, 1, 'r');
        }
        else {
            dfs(root->left, 1, 'l');
            dfs(root->right, curr+1, 'r');
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, 1, 'l');
        dfs(root->right, 1, 'r');
        return ans;
    }
};