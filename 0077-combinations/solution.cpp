class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int x, int n, int k){

        if(temp.size() + (n - x + 1) < k) return;
        
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        if(x > n) return;

        temp.push_back(x);
        solve(x+1, n, k);
        temp.pop_back();

        solve(x+1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {

        solve(1, n, k);

        return ans;
    }
};
