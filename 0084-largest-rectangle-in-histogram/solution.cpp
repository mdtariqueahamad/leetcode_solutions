class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ps(n), ns(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();

            if(st.empty()) ps[i] = -1;
            else ps[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();

            if(st.empty()) ns[i] = n;
            else ns[i] = st.top();

            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            
            int len = ns[i] - ps[i] - 1;
            int h = nums[i];

            ans = max(ans, h*len);
        }

        return ans;
    }
};
