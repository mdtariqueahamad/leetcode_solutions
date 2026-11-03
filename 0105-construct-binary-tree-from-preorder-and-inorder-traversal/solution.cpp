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

    TreeNode *construct(vector<int> &p, int pi, int is, int ie) {

        if(ie < is) return nullptr;

        TreeNode *root = new TreeNode(p[pi]);

        root->right = construct(p, mpp[p[pi]] - is + pi +1, mpp[p[pi]]+1, ie);
        root->left = construct(p, pi+1, is, mpp[p[pi]]-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preOr, vector<int>& inOr) {

        for(int i = 0; i < inOr.size(); i++)
            mpp[inOr[i]] = i;
        
        return construct(preOr, 0, 0, inOr.size()-1);
    }
};
