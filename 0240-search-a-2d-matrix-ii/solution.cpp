class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ci = matrix[0].size()-1, ri = 0;

        while(ci >= 0 && ri < matrix.size()) {
            if(target == matrix[ri][ci]) return true;
            else if(target > matrix[ri][ci]) ri++;
            else ci--;
        }

        return false;
    }
};
