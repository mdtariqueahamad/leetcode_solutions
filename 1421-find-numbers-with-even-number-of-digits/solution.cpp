class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int x : nums){
            if(x == 0) count += 1;
            else
            count += !(int((floor(log10(x))) + 1) % 2);
        }
        return count;
    }
};
