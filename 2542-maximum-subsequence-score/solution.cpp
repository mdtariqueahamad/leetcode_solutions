class Solution {
    static bool fp(pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();

        vector<pair<int,int>> nums(n);
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++)
            nums[i] = {nums1[i], nums2[i]};

        sort(begin(nums), end(nums), fp);

        long long sum = 0;

        for(int i = 0; i < k; i++) {
            sum += nums[i].first;
            pq.push(nums[i].first);
        }

        long long ans = nums[k-1].second * sum;

        for(int i = k; i < n; i++) {

            sum += nums[i].first - pq.top();

            pq.pop();

            pq.push(nums[i].first);

            ans = max(ans, sum * nums[i].second);
        }

        return ans;
    }
};