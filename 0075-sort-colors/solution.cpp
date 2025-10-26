class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(3, 0);
        for (int i : nums) {
            temp[i]++;
        }
        for(int i = 0; i < temp[0]; i++)
            nums[i] = 0;
        for(int i = temp[0]; i < temp[0]+temp[1]; i++)
            nums[i] = 1;
        for(int i = temp[0]+temp[1]; i < temp[0]+temp[1]+temp[2]; i++)
            nums[i] = 2;
        
    }
};
