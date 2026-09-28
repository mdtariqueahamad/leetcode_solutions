class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());

        for(int &x: candies){
            if((x+extraCandies) >= mx) x = 1;
            else x = 0;
        }

        vector<bool> nums(candies.begin(), candies.end());
        return nums;
    }
};