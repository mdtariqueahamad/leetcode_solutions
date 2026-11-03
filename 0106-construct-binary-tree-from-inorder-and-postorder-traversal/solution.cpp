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

    unordered_map<int, int> mpp;

    TreeNode *construct(vector<int> &p, int &pi, int is, int ie) {

        if(ie < is) return nullptr;

        int x = p[pi];
        TreeNode *root = new TreeNode(x);
        pi--;

        root->right = construct(p, pi, mpp[x]+1, ie);
        root->left = construct(p, pi, is, mpp[x]-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inOr, vector<int>& postOr) {
        for(int i = 0; i < inOr.size(); i++)
            mpp[inOr[i]] = i;
        
        int n = inOr.size()-1;
        return construct(postOr, n, 0, inOr.size()-1);
    }
};
