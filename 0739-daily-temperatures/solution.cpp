class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        vector<int> nums(tem.size(), 0);
        stack<int> st;

        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && tem[st.top()] < tem[i]){
                nums[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return nums;
    }
};