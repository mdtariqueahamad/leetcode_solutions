// LeetCode Problem 1248: Count Number of Nice Subarrays
// Difficulty: Medium
// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
// Language: cpp

class Solution {
    int temp(vector <int> nums, int k){
        int count = 0, low = 0, high = 0;
        for( ;low < nums.size(); low++){
            if(nums[low] % 2)
            k--;
            while(k < 0){
                if(nums[high] % 2)
                k++;
                high++;
            }
            count += (low - high + 1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k){
        return temp(nums, k) - temp(nums, k-1);
    }
};