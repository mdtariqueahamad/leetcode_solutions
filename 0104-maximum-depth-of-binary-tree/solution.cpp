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
    int mx = 0;
    void dfs(TreeNode* root, int count) {
        mx = max(count, mx);
        if(NULL == root) return;
        dfs(root -> left, count+1);
        dfs(root -> right, count+1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return mx;   
    }
};
