class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>  s(nums.begin(), nums.end());
        
        int ans = 0;
        
        for(int x: s){
            int count = 0, curr = x;
            if(s.find(x-1) == s.end()){
                while(s.find(curr) != s.end()){
                    curr++;
                    count++;
                }
                ans = max(ans, count);
            }
        }       
        
        return ans;
    }
};