/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode *root, unordered_map<int, TreeNode*> &mpp) {

        if(root->left) {
            mpp[root->left->val] = root;
            dfs(root->left, mpp);
        }

        if(root->right){
            mpp[root->right->val] = root;
            dfs(root->right, mpp);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<int, TreeNode*> mpp;
        dfs(root, mpp);

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> visited;

        for(int i = 0; i < k; i++) {
            int size = q.size();

            while(size) {
                size--;
                TreeNode *node = q.front();
                q.pop();

                visited.insert(node->val);

                if(node->left && visited.find(node->left->val) == visited.end())
                    q.push(node->left);
                
                if(node->right && visited.find(node->right->val) == visited.end())
                    q.push(node->right);
                
                if(mpp.find(node->val) != mpp.end() && visited.find(mpp[node->val]->val) == visited.end())
                    q.push(mpp[node->val]);
            }
        }

        vector<int> ans(q.size());

        for(int i = 0; !q.empty(); i++) {
            ans[i] = q.front()->val;
            q.pop();
        }

        return ans;
    }
};
