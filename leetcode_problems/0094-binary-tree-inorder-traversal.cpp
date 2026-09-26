// LeetCode Problem 0094: Binary Tree Inorder Traversal
// Difficulty: Easy
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans;
        inorderTraversal(root -> left);
        ans.push_back(root -> val);
        inorderTraversal(root -> right);
        return ans;
    }
};