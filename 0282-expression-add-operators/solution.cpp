class Solution {
public:
    vector<string> ans;
    string temp = "";
    string s;
    int n;
    long long target_val;

    void solve(int idx, long long sum, long long prod, long long curr_val) {
        if (idx == n) {
            if (sum + (prod * curr_val) == target_val) {
                ans.push_back(temp);
            }
            return;
        }

        int d = s[idx] - '0';

        if (curr_val != 0) {
            temp.push_back(s[idx]);
            solve(idx + 1, sum, prod, curr_val * 10 + d);
            temp.pop_back();
        }

        temp.push_back('+');
        temp.push_back(s[idx]);
        solve(idx + 1, sum + (prod * curr_val), 1, d);
        temp.pop_back();
        temp.pop_back();

        temp.push_back('-');
        temp.push_back(s[idx]);
        solve(idx + 1, sum + (prod * curr_val), -1, d);
        temp.pop_back();
        temp.pop_back();

        temp.push_back('*');
        temp.push_back(s[idx]);
        solve(idx + 1, sum, prod * curr_val, d);
        temp.pop_back();
        temp.pop_back();
    }

    vector<string> addOperators(string num, int target) {
        s = num;
        n = s.size();
        target_val = target;
        if (!n) return {""};
        
        temp.push_back(s[0]);
        solve(1, 0, 1, s[0] - '0');
        
        return ans;
    }
};
