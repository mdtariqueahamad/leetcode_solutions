class Solution {
    vector<int> ans;
    vector<int> last;
    unordered_map<int, vector<int>> adj;

    void dfs(vector<int> &nums, string &s, int idx) {

        int charIdx = s[idx] - 'a';
        int prevAncestor = last[charIdx];
        
        if (prevAncestor != -1)
            nums[idx] = prevAncestor;
        
        last[charIdx] = idx;

        for (int child : adj[idx]) {
            dfs(nums, s, child);
        }
        
        last[charIdx] = prevAncestor;
        
        if (nums[idx] != -1) {
            ans[nums[idx]] += ans[idx];
        }
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        
        last.assign(26, -1);
        ans.assign(parent.size(), 1);

        for(int i = 1; i < parent.size(); i++)
            adj[parent[i]].push_back(i);

        dfs(parent, s, 0);

        return ans;
    }
};
