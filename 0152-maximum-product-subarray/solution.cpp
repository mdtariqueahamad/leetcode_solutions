class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currx, currn, prod = nums[0];
        currx = currn = prod;
        for(int x = 1; x < nums.size(); x++){
            int i = nums[x];
            if (i < 0) swap(currx, currn);
            currx = max(i, i*currx);
            currn = min(i, i*currn);
            prod = max(currx, prod);
        }
        
        return prod;
    }
};
