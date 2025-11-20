class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;

        vector<int> res;

        for (auto &p : mp) {
            int left  = mp.count(p.first - 1) ? mp.at(p.first - 1) : 0;
            int right = mp.count(p.first + 1) ? mp.at(p.first + 1) : 0;

            if (p.second == 1 && left == 0 && right == 0)
                res.push_back(p.first);
        }

        return res;
    }
};

