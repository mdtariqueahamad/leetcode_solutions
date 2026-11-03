class Solution {
public:
    int minMoves(vector<int>& nums) {

        int largest = *max_element(nums.begin(), nums.end());

        int moves = 0;

        for(int x: nums)
            moves += (largest - x);
        
        return moves;
    }
};
