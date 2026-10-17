class Solution {
    class fp {
    public:
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.second > b.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;

        for(int x: nums)
            mpp[x]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, fp> pq;

        for(auto it: mpp) {
            pq.push({it.first, it.second});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()) {
            auto it = pq.top();
            ans.push_back(it.first);
            pq.pop();
        }

        return ans;
    }
};