class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "#,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* solve(string &data, int &i) {
        if(data[i] == '#') {
            i += 2;
            return nullptr;
        }

        string num;

        while(data[i] != ',')
            num += data[i++];

        i++;

        TreeNode* root = new TreeNode(stoi(num));

        root->left = solve(data, i);
        root->right = solve(data, i);

        return root;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return solve(data, i);
    }
};
