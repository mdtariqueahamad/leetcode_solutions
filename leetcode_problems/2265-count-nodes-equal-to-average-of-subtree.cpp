// LeetCode Problem 2265: Count Nodes Equal to Average of Subtree
// Difficulty: Medium
// Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
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
    int n = 0;
    void tr(TreeNode *root){
        if(!root) return;
        int sum = 0, count = 0;
        n += traversal(root, sum, count);
        tr(root->left);
        tr(root->right);
    }
    int traversal(TreeNode *root, int &sum, int &count){
        if(!root) return 0;
        sum += root->val;
        count++;
        traversal(root->left, sum, count);
        traversal(root->right, sum, count);
        return sum/count == root->val;
    }
    int averageOfSubtree(TreeNode* root) {
        tr(root);
        return n;
    }
};