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
    int dfs(TreeNode *root, unordered_map<long long,int> &mpp, long long sum, int target){

        if(!root) return 0;

        sum += root->val;

        int ans = mpp[sum-target];

        mpp[sum]++;

        ans += dfs(root->left, mpp, sum, target);
        ans += dfs(root->right, mpp, sum, target);

        if(--mpp[sum] == 0) mpp.erase(sum);

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        unordered_map<long long,int> mpp;

        mpp[0] = 1;

        return dfs(root, mpp, 0, targetSum);
    }
};