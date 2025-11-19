class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int x : position)
            x % 2 ? odd++ : even++;
        return min(odd, even);
    }
};

