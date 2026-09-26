// LeetCode Problem 1636: Sort Array by Increasing Frequency
// Difficulty: Easy
// Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/
// Language: cpp

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int,int> mpp;

        for(int x: nums) mpp[x]++;

        vector<vector<int>> vec(nums.size()+1);
        vector<int> ans;

        for(auto it: mpp) vec[it.second].push_back(it.first);

        for(int i = 1; i < vec.size(); i++){
            for(int j = vec[i].size()-1; j >= 0; j--){
                sort(vec[i].begin(), vec[i].end());
                int n = i;
                while(n--)
                  ans.push_back(vec[i][j]);
            }
        }
        return ans;
    }
};