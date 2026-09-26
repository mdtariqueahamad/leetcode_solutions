// LeetCode Problem 0145: Binary Tree Postorder Traversal
// Difficulty: Easy
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Language: cpp

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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(NULL == root) return ans;
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        ans.push_back(root -> val);
        return ans;
    }
};