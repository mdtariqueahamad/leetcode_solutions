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
    int traverseLeft(TreeNode *root, int n) {
        if(!root) return n;

        return traverseLeft(root->left, n+1);
    }

    int traverseRight(TreeNode *root, int n) {
        if(!root) return n;

        return traverseRight(root->right, n+1);
    }
public:
    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int lh = traverseLeft(root, 0);
        int rh = traverseRight(root, 0);

        if(lh == rh) return (1 << lh) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
