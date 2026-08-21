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
    bool check = true;
    void helper(TreeNode *l, TreeNode *r){
        if(l == nullptr && nullptr == r) return;
        if(l == nullptr || nullptr == r || (l -> val != r -> val)){
            check = false;
            return;
        }
        helper(l -> left, r -> right);
        helper(l -> right, r -> left);
    }
    bool isSymmetric(TreeNode* root) {
        helper(root -> left, root -> right);
        return check;
    }
};
