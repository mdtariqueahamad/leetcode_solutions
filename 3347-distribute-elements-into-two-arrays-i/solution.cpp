class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1, v2;
        if(!nums.size() || 1 == nums.size()) return nums;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        int count = 2;
        while(count != nums.size()){
            if(v1.back() > v2.back()) v1.push_back(nums[count]);
            else v2.push_back(nums[count]);
            count++;
        }
        for(int i = 0; i < v2.size(); i++)
        v1.push_back(v2[i]);

        return v1;
    }
};
