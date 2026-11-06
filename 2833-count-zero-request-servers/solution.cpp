class Solution {
    static bool fp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), fp);

        vector<pair<int, int>> qp(queries.size());

        for(int i = 0; i < queries.size(); i++) {
            qp[i] = {queries[i], i};
        }

        sort(qp.begin(), qp.end());

        vector<int> ans(queries.size());
        unordered_map<int, int> mpp;
        int low = 0, high = 0;

        for(int i = 0; i < qp.size(); i++) {

            int val = qp[i].first;

            while(high < logs.size() && logs[high][1] <= val) {
                mpp[logs[high][0]]++;
                high++;
            }
            val -= x;
            while(low < high && logs[low][1] < val) {
                mpp[logs[low][0]]--;
                if(mpp[logs[low][0]] == 0) {
                    mpp.erase(logs[low][0]);
                }
                low++;
            }

            ans[qp[i].second] = n - mpp.size();
        }

        return ans;
    }
};
