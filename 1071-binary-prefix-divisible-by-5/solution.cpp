class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums){
       int sum = 0;
        vector<bool> res;
      for(int x : nums){
        sum = (sum * 2) + x;
        sum %= 5;
        if(!(sum % 5))
        res.push_back(true);
        else
        res.push_back(false);
      }
      return res;
    }
};
