class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for(auto &nums: matrix)
            for(int &x: nums) {
                pq.push(x);
                if(pq.size() > k) pq.pop();
            }

        return pq.top();
    }
};
