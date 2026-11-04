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
    int idx = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder, int bound = INT_MAX) {

        if(idx == preorder.size()) return nullptr;

        TreeNode *root = new TreeNode(preorder[idx++]);

        if(idx < preorder.size() && preorder[idx] < root->val)
        root->left = bstFromPreorder(preorder, preorder[idx-1]);

        if(idx < preorder.size() && preorder[idx] < bound)
        root->right = bstFromPreorder(preorder, bound);

        return root;
    }
};
