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
    bool find(TreeNode *root, int &curr) {

        if(!root) return false;
        
        if(root->val < k-curr) return find(root->right, curr);
        else if(root->val > k-curr) return find(root->left, curr);

        if(curr == root->val && k-curr == curr) return false;

        return true;
    }

    bool dfs(TreeNode *root) {

        if(!root) return false;
        if(find(mainroot, root->val)) return true;

        return dfs(root->left) || dfs(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        mainroot = root;
        this->k = k;
        return dfs(root);
    }

private:
    TreeNode *mainroot = nullptr;
    int k;
};
