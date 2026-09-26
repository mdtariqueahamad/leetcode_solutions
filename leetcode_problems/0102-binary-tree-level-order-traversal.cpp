// LeetCode Problem 0102: Binary Tree Level Order Traversal
// Difficulty: Medium
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                temp.push_back(q.front() -> val);
                if(q.front() -> left != NULL) q.push(q.front() -> left);
                if(q.front() -> right != NULL) q.push(q.front() -> right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};