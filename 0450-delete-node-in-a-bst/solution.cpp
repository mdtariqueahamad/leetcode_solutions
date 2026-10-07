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
    TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* prev = nullptr;
    TreeNode* node = root;

    // Find node
    while (node && node->val != key) {
        prev = node;

        if (key < node->val)
            node = node->left;
        else
            node = node->right;
    }

    if (!node) return root;

    // 0 or 1 child
    if (!node->left || !node->right) {
        TreeNode* child = node->left ? node->left : node->right;

        if (!prev)
            root = child;
        else if (prev->left == node)
            prev->left = child;
        else
            prev->right = child;

        delete node;
        return root;
    }

    // 2 children: find inorder successor
    TreeNode* succPrev = node;
    TreeNode* succ = node->right;

    while (succ->left) {
        succPrev = succ;
        succ = succ->left;
    }

    // Detach successor from its old position
    if (succPrev != node)
        succPrev->left = succ->right;

    // Successor takes node's position
    succ->left = node->left;

    if (succPrev == node)
        succ->right = succ->right;
    else
        succ->right = node->right;

    if (!prev)
        root = succ;
    else if (prev->left == node)
        prev->left = succ;
    else
        prev->right = succ;

    delete node;
    return root;
}
};