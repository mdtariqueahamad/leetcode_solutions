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

    vector<vector<pair<int, int>>> right;
    vector<vector<pair<int, int>>> left;

    static bool fp(pair<int, int> &a, pair<int, int> &b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }

public:
    void dfs(TreeNode *root, int verOrder, int depth) {

        if(!root) return;

        if(verOrder >= 0) {

            if(right.size() == verOrder) {
                right.push_back({{root->val, depth}});
            } else {
                right[verOrder].push_back({root->val, depth});
            }

        } else {
            int order = -(verOrder + 1);

            if(left.size() == order) {
                left.push_back({{root->val, depth}});
            } else {
                left[order].push_back({root->val, depth});
            }

        }

        dfs(root -> left, verOrder - 1, depth + 1);
        dfs(root -> right, verOrder + 1, depth + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs(root, 0, 0);

        reverse(left.begin(), left.end());
        left.insert(left.end(), right.begin(), right.end());

        for(auto &nums: left) {
            sort(nums.begin(), nums.end(), fp);
        }

        vector<vector<int>> v(left.size());
        for (int i = 0; i < left.size(); i++)
            transform(left[i].begin(), left[i].end(), back_inserter(v[i]),
                    [](const pair<int,int>& p) { return p.first; });
        return v;
    }
};
