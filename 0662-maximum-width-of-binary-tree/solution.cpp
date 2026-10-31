class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 1;

        while (!q.empty()) {
            int size = q.size();
            int left = -1, right = -1;

            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                long long idx = node.second;

                if (node.first->left) {

                    q.push({node.first->left, 2*idx + 1});

                    if(left == -1)
                        left = 2*idx + 1;
                    
                    right = 2*idx + 1;
                }
                if (node.first->right) {

                    q.push({node.first->right, 2*(idx+1)});

                    if(left == -1)
                        left = 2 * (idx+1);

                    right = 2 * (idx+1);                    
                }
            }

            if (left != -1)
                ans = max(ans, right - left + 1);

        }

        return ans;
    }
};
