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

    void inorder(TreeNode* root, int k, vector<int>& arr) {
        if (!root || arr.size() == k) return;

        inorder(root->left, k, arr);

        if (arr.size() == k) return;
        arr.push_back(root->val);

        inorder(root->right, k, arr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, k, vec);

        return vec.back();
    }
};
