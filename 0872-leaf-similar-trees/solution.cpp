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
    vector<int> nums1, nums2;
public:

    void dfs1(TreeNode *root){
        if(!root) return;
        if(!(root->left) && !(root->right)){
            nums1.push_back(root->val);
            return;
        }
        dfs1(root -> left);
        dfs1(root -> right);
    }

    void dfs2(TreeNode *root){
        if(!root) return;
        if(!(root -> left) && !(root -> right)){
            nums2.push_back(root->val);
            return;
        }
        dfs2(root -> left);
        dfs2(root -> right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);

        return nums1 == nums2;
    }
};