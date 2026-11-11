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
    void dfs(TreeNode* root, TreeNode*& prev, TreeNode*& swap1, TreeNode*& swap2){
        if(root == NULL){
            return;
        }
        dfs(root->left, prev, swap1, swap2);
        if(prev && prev->val > root->val){
            if(swap1 == NULL){
                swap1 = prev;
            }
            swap2 = root;
        }
        prev = root;
        dfs(root->right, prev, swap1, swap2);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* swap1 = NULL;
        TreeNode* swap2 = NULL;
        TreeNode* prev = NULL;

        dfs(root, prev, swap1, swap2);        
        swap(swap1->val, swap2->val);
    }
};
